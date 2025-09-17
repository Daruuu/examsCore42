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

//	 FUNCTION TO MODIFY 
int accept(char **s, char c)
{
	//if (**s)	add comparision to c
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
    unexpected(**s);
    return (0);
}

// ====================== NEW IMPLEMENTATION ==================================

/** Forward declaration */
static node *parse_expr_r(char **s);

/**
 * parse_factor - Parses the most basic unit of the expression.
 *
 * Grammar handled:
 *   factor → DIGIT | '(' expr ')'
 *
 * Steps to understand:
 * 1. If the current char is a digit:
 *    - Convert it to an integer value.
 *    - Create a node of type VAL with that value.
 *
 * 2. If the current char is '(':
 *    - Consume '('.
 *    - Call parse_expr_r recursively to evaluate the inside expression.
 *    - Expect and consume the closing ')'.
 *
 * 3. Otherwise:
 *    - Print an unexpected token error.
 *    - Return NULL.
 *
 * Returns:
 * - Pointer to the new node representing a factor.
 * - NULL if parsing fails.
 */

static node *parse_factor(char **s)	/* factor -> digit | '(' expr ')' */
{
	/*1. If the current char is a digit:
		- Convert it to an integer value.
		- Create a node of type VAL with that value.*/
    if (isdigit((unsigned char)**s)) {
        node n = { VAL, **s - '0', NULL, NULL };
        (*s)++;
        return new_node(n);
    }
	/*2. If the current char is '(':
		- Consume '('.
		- Call parse_expr_r recursively to evaluate the inside expression.
		- Expect and consume the closing ')'.*/
    if (accept(s, '('))
	{
        node *e = parse_expr_r(s);
        if (!e)
            return NULL;
        if (!expect(s, ')')) {
            destroy_tree(e);
            return NULL;
        }
        return e;
    }
    unexpected(**s);
    return NULL;
}

/**
 * parse_term - Parses a sequence of factors separated by '*'.
 *
 * Grammar handled:
 *   term → factor { '*' factor }
 *
 * Steps to understand:
 * 1. Parse the first factor with parse_factor().
 * 2. While the current char is '*':
 *    - Consume '*'.
 *    - Parse the next factor.
 *    - Create a MULTI node with the current tree as left child
 *      and the new factor as right child.
 *    - Update the current tree pointer to this new MULTI node.
 *
 * Example:
 *   Input: "3*4*5"
 *   Tree: (((3 * 4) * 5))
 *
 * Returns:
 * - Pointer to the root node of the multiplication tree.
 * - NULL if parsing fails.
 */

static node	*parse_term(char **s)	/* term -> factor { '*' factor } */
{
    node *left = parse_factor(s);
    if (!left)
        return NULL;
    while (accept(s, '*')) {
        node *right = parse_factor(s);
        if (!right) {
            destroy_tree(left);
            return NULL;
        }
        node n = { MULTI, 0, left, right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}

/**
 * parse_expr_r - Parses a sequence of terms separated by '+'.
 *
 * Grammar handled:
 *   expr → term { '+' term }
 *
 * Steps to understand:
 * 1. Parse the first term with parse_term().
 * 2. While the current char is '+':
 *    - Consume '+'.
 *    - Parse the next term.
 *    - Create an ADD node with the current tree as left child
 *      and the new term as right child.
 *    - Update the current tree pointer to this new ADD node.
 *
 * Example:
 *   Input: "3+4*5"
 *   Tree: (3 + (4 * 5))   // correct precedence
 *
 * Returns:
 * - Pointer to the root node of the addition tree.
 * - NULL if parsing fails.
 */

static node *parse_expr_r(char **s)		/* expr -> term { '+' term } */
{
    node *left = parse_term(s);
    if (!left)
        return NULL;
    while (accept(s, '+')) {
        node *right = parse_term(s);
        if (!right) {
            destroy_tree(left);
            return NULL;
        }
        node n = { ADD, 0, left, right };
        left = new_node(n);
        if (!left)
            return NULL;
    }
    return left;
}

/**
 * parse_expr - Entry point for parsing the full expression string.
 *
 * Grammar handled:
 *   expr (entire input)
 *
 * Steps to understand:
 * 1. Call parse_expr_r() to parse the whole input.
 * 2. After parsing, check if the input string has remaining characters.
 *    - If yes: print "Unexpected token".
 *    - If no: parsing was successful.
 * 3. If there was an error, free the allocated AST.
 *
 * Example:
 *   Input: "((2+3)*4)"
 *   Produces a tree representing (2+3)*4.
 *
 * Returns:
 * - Pointer to the root node of the AST (Abstract Syntax Tree).
 * - NULL if parsing fails.
 */

node *parse_expr(char *s)	/* Main parser */
{
    char *p = s;	//	new line added
	
    node *ret = parse_expr_r(&p);
    if (!ret)
        return NULL;

    if (*p) {
        unexpected(*p);
        destroy_tree(ret);
        return NULL;
    }
    return ret;
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);

    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}

