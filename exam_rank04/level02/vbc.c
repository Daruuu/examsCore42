/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc.c                                              :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s ? **s : 0);
    return (0);
}

node *parse_expr(char **s);
node *parse_term(char **s);
node *parse_factor(char **s);

node *parse_factor(char **s)
{
    if (**s == '\0')
    {
        unexpected(0);
        return NULL;
    }
    if (isdigit(**s))
    {
        node n = {VAL, **s - '0', NULL, NULL};
        (*s)++;
        return new_node(n);
    }
    else if (accept(s, '('))
    {
        node *inside = parse_expr(s);
        if (!inside)
            return NULL;
        if (!expect(s, ')'))
        {
            destroy_tree(inside);
            return NULL;
        }
        return inside;
    }
    unexpected(**s);
    return NULL;
}

node *parse_term(char **s)
{
    node *left = parse_factor(s);
    if (!left)
        return NULL;
    while (**s == '*')
    {
        (*s)++;
        node *right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = {MULTI, 0, left, right};
        left = new_node(n);
    }
    return left;
}

node *parse_expr(char **s)
{
    node *left = parse_term(s);
    if (!left)
        return NULL;
    while (**s == '+')
    {
        (*s)++;
        node *right = parse_term(s);
        if (!right)
        {
            destroy_tree(left);
            return NULL;
        }
        node n = {ADD, 0, left, right};
        left = new_node(n);
    }
    return left;
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return eval_tree(tree->l) + eval_tree(tree->r);
        case MULTI:
            return eval_tree(tree->l) * eval_tree(tree->r);
        case VAL:
            return tree->val;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    char *p = argv[1];
    node *tree = parse_expr(&p);

    if (!tree)
        return (1);

    if (*p)
    {
        unexpected(*p);
        destroy_tree(tree);
        return (1);
    }

    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}