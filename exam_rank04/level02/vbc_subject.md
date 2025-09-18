# vbc (Variable Byte Code)

## Descripción
Implementa un evaluador de expresiones matemáticas que parsea expresiones con operadores de suma (+) y multiplicación (*), maneja paréntesis para precedencia, y construye un árbol de sintaxis abstracta (AST) para evaluación.

## Prototipo
```c
node *parse_expr(char *s);
int eval_tree(node *tree);
```

## Gramática Soportada
- **Números**: Dígitos individuales (0-9)
- **Operadores**: + (suma), * (multiplicación)
- **Paréntesis**: Para agrupar expresiones
- **Precedencia**: * tiene mayor precedencia que +

## Conceptos Clave
- **AST**: Abstract Syntax Tree para representar expresiones
- **Recursive Descent**: Parser recursivo descendente
- **Operator Precedence**: Manejo de precedencia de operadores
- **Tree Evaluation**: Evaluación recursiva del árbol
- **Memory Management**: Gestión de memoria para el AST

## Estructura del Nodo
```c
typedef struct node {
    enum { ADD, MULTI, VAL } type;
    int val;
    struct node *l;
    struct node *r;
} node;
```

## Funciones Principales
- `parse_expr()`: Parser principal de expresiones
- `parse_term()`: Parser de términos (multiplicaciones)
- `parse_factor()`: Parser de factores (números y paréntesis)
- `eval_tree()`: Evaluador del árbol de sintaxis
- `destroy_tree()`: Liberación de memoria del árbol

## Ejemplos de Expresión
- "2+3" → 5
- "2*3" → 6
- "2+3*4" → 14 (precedencia: * antes que +)
- "(2+3)*4" → 20 (paréntesis cambian precedencia)
- "2*3+4*5" → 26

## Manejo de Errores
- Tokens inesperados
- Paréntesis no balanceados
- Entrada vacía o inválida
- Liberación de memoria en caso de error