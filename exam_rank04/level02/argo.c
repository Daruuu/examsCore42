/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo.c                                             :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Definición de estructuras para el AST
typedef struct json {
    enum {
        MAP,
        INTEGER,
        STRING
    } type;
    union {
        struct {
            struct pair *data;
            size_t size;
        } map;
        int integer;
        char *string;
    };
} json;

typedef struct pair {
    char *key;
    json value;
} pair;

// Declaraciones de funciones
int argo(json *dst, FILE *stream);
int parser(json *dst, FILE *stream);
int parse_int(json *dst, FILE *stream);
int parse_string(json *dst, FILE *stream);
int parse_map(json *dst, FILE *stream);
void free_json(json j);

// Función para mirar el siguiente carácter sin consumirlo
int peek(FILE *stream)
{
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

// Función para reportar errores de parsing
void unexpected(FILE *stream)
{
    if (peek(stream) != EOF)
        printf("unexpected token '%c'\n", peek(stream));
    else
        printf("unexpected end of input\n");
}

// Función para aceptar un carácter específico
int accept(FILE *stream, char c)
{
    if (peek(stream) == c)
    {
        (void)getc(stream);
        return 1;
    }
    return 0;
}

// Función para requerir un carácter específico
int expect(FILE *stream, char c)
{
    if (accept(stream, c))
        return 1;
    unexpected(stream);
    return 0;
}

// Función principal de parsing
int parser(json *dst, FILE *stream)
{
    int c = peek(stream);
    
    if (c == '"')
        return parse_string(dst, stream);
    else if (isdigit(c) || c == '-')
        return parse_int(dst, stream);
    else if (c == '{')
        return parse_map(dst, stream);
    else
    {
        unexpected(stream);
        return -1;
    }
}

// Parser de números enteros
int parse_int(json *dst, FILE *stream)
{
    int n;
    
    if (fscanf(stream, "%d", &n) == 1)
    {
        dst->type = INTEGER;
        dst->integer = n;
        return 1;
    }
    
    unexpected(stream);
    return -1;
}

// Parser de strings
int parse_string(json *dst, FILE *stream)
{
    char buffer[4096];
    char c;
    int i = 0;
    
    if (!expect(stream, '"'))
        return -1;
    
    while (1)
    {
        c = getc(stream);
        
        if (c == EOF)
        {
            unexpected(stream);
            return -1;
        }
        
        if (c == '"')
            break;
        
        if (c == '\\')
        {
            c = getc(stream);
            if (c == EOF)
            {
                unexpected(stream);
                return -1;
            }
        }
        
        buffer[i++] = c;
        
        if (i >= sizeof(buffer) - 1)
        {
            unexpected(stream);
            return -1;
        }
    }
    
    buffer[i] = '\0';
    
    dst->type = STRING;
    dst->string = strdup(buffer);
    if (!dst->string)
        return -1;
    
    return 1;
}

// Parser de maps/objects
int parse_map(json *dst, FILE *stream)
{
    pair *items = NULL;
    size_t size = 0;
    json key;
    
    if (!expect(stream, '{'))
        return -1;
    
    if (accept(stream, '}'))
    {
        dst->type = MAP;
        dst->map.size = 0;
        dst->map.data = NULL;
        return 1;
    }
    
    while (1)
    {
        items = realloc(items, sizeof(pair) * (size + 1));
        if (!items)
            return -1;
        
        if (parse_string(&key, stream) == -1)
        {
            free(items);
            return -1;
        }
        
        if (!expect(stream, ':'))
        {
            free(key.string);
            free(items);
            return -1;
        }
        
        if (parser(&items[size].value, stream) == -1)
        {
            free(key.string);
            free(items);
            return -1;
        }
        
        items[size].key = key.string;
        size++;
        
        if (accept(stream, ','))
            continue;
        else if (peek(stream) == '}')
            break;
        else
        {
            unexpected(stream);
            for (size_t j = 0; j < size; j++)
            {
                free(items[j].key);
                free_json(items[j].value);
            }
            free(items);
            return -1;
        }
    }
    
    if (!expect(stream, '}'))
    {
        for (size_t j = 0; j < size; j++)
        {
            free(items[j].key);
            free_json(items[j].value);
        }
        free(items);
        return -1;
    }
    
    dst->type = MAP;
    dst->map.size = size;
    dst->map.data = items;
    
    return 1;
}

// Función principal del parser
int argo(json *dst, FILE *stream)
{
    return parser(dst, stream);
}

// Función para liberar memoria del AST
void free_json(json j)
{
    switch (j.type)
    {
        case MAP:
            for (size_t i = 0; i < j.map.size; i++)
            {
                free(j.map.data[i].key);
                free_json(j.map.data[i].value);
            }
            free(j.map.data);
            break;
        
        case STRING:
            free(j.string);
            break;
        
        case INTEGER:
            break;
    }
}

// Función para serializar AST de vuelta a JSON
void serialize(json j)
{
    switch (j.type)
    {
        case INTEGER:
            printf("%d", j.integer);
            break;
            
        case STRING:
            putchar('"');
            for (int i = 0; j.string[i]; i++)
            {
                if (j.string[i] == '\\' || j.string[i] == '"')
                    putchar('\\');
                putchar(j.string[i]);
            }
            putchar('"');
            break;
            
        case MAP:
            putchar('{');
            for (size_t i = 0; i < j.map.size; i++)
            {
                if (i != 0)
                    putchar(',');
                
                json key_json = {.type = STRING, .string = j.map.data[i].key};
                serialize(key_json);
                
                putchar(':');
                serialize(j.map.data[i].value);
            }
            putchar('}');
            break;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    
    char *filename = argv[1];
    FILE *stream = fopen(filename, "r");
    if (!stream)
        return 1;
    
    json file;
    
    if (argo(&file, stream) != 1)
    {
        free_json(file);
        fclose(stream);
        return 1;
    }
    
    serialize(file);
    printf("\n");
    
    free_json(file);
    fclose(stream);
    return 0;
}