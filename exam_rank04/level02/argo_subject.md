# argo (JSON Parser)

## Descripción
Implementa un parser de JSON que construye un AST (Abstract Syntax Tree) y puede serializar de vuelta a formato JSON. El parser debe manejar números enteros, strings con escapes básicos, y objetos JSON.

## Prototipo
```c
int argo(json *dst, FILE *stream);
```

## Tipos Soportados
- **Números enteros**: 42, -17
- **Strings**: "hello", "escape \" test"
- **Objects**: {"key": value, "key2": value2}
- **Escape sequences**: \\ y \" solamente

## Conceptos Clave
- **AST**: Abstract Syntax Tree para representar datos estructurados
- **Recursive Descent**: Técnica de parsing top-down
- **Tokenización**: Reconocer elementos básicos
- **Gestión de memoria**: Estructuras dinámicas enlazadas
- **Error handling**: Manejo robusto de errores de parsing

## Estructura del AST
```c
typedef struct json {
    enum { MAP, INTEGER, STRING } type;
    union {
        struct { struct pair *data; size_t size; } map;
        int integer;
        char *string;
    };
} json;
```

## Funciones Principales
- `argo()`: Función principal de parsing
- `parse_int()`: Parser de números enteros
- `parse_string()`: Parser de strings con escapes
- `parse_map()`: Parser de objetos JSON
- `free_json()`: Liberación de memoria del AST
- `serialize()`: Serialización de vuelta a JSON

## Ejemplos de Entrada/Salida
- Input: "42" → Output: 42
- Input: "\"hello world\"" → Output: "hello world"
- Input: "{\"name\":\"John\",\"age\":30}" → Output: {"name":"John","age":30}