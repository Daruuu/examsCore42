# Exam Rank 04 - Sistemas Operativos y Parsing Avanzado

Este repositorio contiene todos los ejercicios del Exam Rank 04 organizados por niveles de dificultad. Cada ejercicio se enfoca en conceptos avanzados de sistemas operativos, parsing de lenguajes, y programación de bajo nivel.

## 📁 Estructura del Proyecto

```
exam_rank04/
├── level01/          # Nivel 1 - Procesos y Pipes
├── level02/          # Nivel 2 - Parsing y AST
├── level03/          # Nivel 3 - Shell Avanzado
├── level04/          # Nivel 4 - Sistemas Complejos
└── README.md         # Este archivo
```

## 🎯 Niveles de Dificultad

### 🔧 [Nivel 1 - Procesos y Pipes](./level01/)
Ejercicios fundamentales sobre gestión de procesos, pipes y comunicación entre procesos.

| Ejercicio | Descripción | Archivo |
|-----------|-------------|---------|
| **ft_popen** | Implementación de popen() con pipes | [📄 ft_popen.c](./level01/ft_popen.c) |
| **picoshell** | Shell minimalista con pipelines | [📄 picoshell.c](./level01/picoshell.c) |
| **sandbox** | Entorno controlado para ejecutar funciones | [📄 sandbox.c](./level01/sandbox.c) |

#### 📚 Conceptos Clave del Nivel 1
- **Fork/Exec**: Creación y ejecución de procesos
- **Pipes**: Comunicación entre procesos padre e hijo
- **File Descriptors**: Redirección de entrada/salida
- **Signals**: Manejo de señales del sistema
- **Process Monitoring**: Control y monitoreo de procesos

### 🧠 [Nivel 2 - Parsing y AST](./level02/)
Ejercicios avanzados sobre parsing de lenguajes y construcción de árboles de sintaxis abstracta.

| Ejercicio | Descripción | Archivo |
|-----------|-------------|---------|
| **argo** | Parser de JSON con AST | [📄 argo.c](./level02/argo.c) |
| **vbc** | Evaluador de expresiones matemáticas | [📄 vbc.c](./level02/vbc.c) |

#### 📚 Conceptos Clave del Nivel 2
- **AST**: Abstract Syntax Tree para representar datos estructurados
- **Recursive Descent**: Técnica de parsing top-down
- **Tokenización**: Reconocimiento de elementos básicos
- **Memory Management**: Gestión de estructuras dinámicas
- **Error Handling**: Manejo robusto de errores de parsing

### 🚀 [Nivel 3 - Shell Avanzado](./level03/)
Ejercicios sobre implementación de shells más complejos con características avanzadas.

| Ejercicio | Descripción | Archivo |
|-----------|-------------|---------|
| **microshell** | Shell básico con ejecución de comandos | [📄 microshell.c](./level03/microshell.c) |

#### 📚 Conceptos Clave del Nivel 3
- **Command Execution**: Ejecución de comandos del sistema
- **Argument Parsing**: Procesamiento de argumentos de línea de comandos
- **Process Management**: Gestión avanzada de procesos
- **Signal Handling**: Manejo de señales en shells

### 🏆 [Nivel 4 - Sistemas Complejos](./level04/)
Ejercicios de mayor complejidad que integran múltiples conceptos de sistemas operativos.

| Ejercicio | Descripción | Archivo |
|-----------|-------------|---------|
| **minishell** | Shell completo con pipelines avanzados | [📄 minishell.c](./level04/minishell.c) |

#### 📚 Conceptos Clave del Nivel 4
- **Advanced Pipelines**: Pipelines complejos con múltiples comandos
- **Process Synchronization**: Sincronización entre múltiples procesos
- **Memory Management**: Gestión avanzada de memoria
- **System Integration**: Integración de múltiples componentes del sistema

## 🛠️ Compilación

Para compilar cualquier ejercicio:

```bash
gcc -Wall -Wextra -Werror ejercicio.c -o ejercicio
```

## 📖 Documentación Detallada

### 🔧 Nivel 1 - Procesos y Pipes

#### ft_popen
- **Propósito**: Implementar comunicación con procesos externos
- **Conceptos**: Pipes, fork, exec, redirección de file descriptors
- **Dificultad**: Intermedio
- **Documentación**: [📄 ft_popen_subject.md](./level01/ft_popen_subject.md)

#### picoshell
- **Propósito**: Ejecutar pipelines de comandos
- **Conceptos**: Pipeline, redirección, gestión de múltiples procesos
- **Dificultad**: Intermedio-Avanzado
- **Documentación**: [📄 picoshell_subject.md](./level01/picoshell_subject.md)

#### sandbox
- **Propósito**: Ejecutar funciones en entorno controlado
- **Conceptos**: Fork, signals, timeout, detección de errores
- **Dificultad**: Avanzado
- **Documentación**: [📄 sandbox_subject.md](./level01/sandbox_subject.md)

### 🧠 Nivel 2 - Parsing y AST

#### argo (JSON Parser)
- **Propósito**: Parser completo de JSON con AST
- **Conceptos**: AST, recursive descent, gestión de memoria, serialización
- **Dificultad**: Avanzado
- **Documentación**: [📄 argo_subject.md](./level02/argo_subject.md)

#### vbc (Variable Byte Code)
- **Propósito**: Evaluador de expresiones matemáticas
- **Conceptos**: AST, operator precedence, recursive parsing
- **Dificultad**: Intermedio-Avanzado
- **Documentación**: [📄 vbc_subject.md](./level02/vbc_subject.md)

## 🎓 Objetivos de Aprendizaje

### 📚 Conceptos Fundamentales
- **Gestión de Procesos**: Fork, exec, wait, signals
- **Comunicación Interproceso**: Pipes, file descriptors
- **Parsing de Lenguajes**: Tokenización, AST, recursive descent
- **Gestión de Memoria**: Allocación dinámica, liberación, memory leaks

### 🔧 Habilidades Técnicas
- **Programación de Sistemas**: Trabajo con APIs del sistema operativo
- **Debugging Avanzado**: Manejo de errores complejos
- **Arquitectura de Software**: Diseño de parsers y evaluadores
- **Optimización**: Gestión eficiente de recursos

### 🚀 Proyectos Prácticos
- **Shell Implementation**: Creación de shells funcionales
- **Language Parser**: Parsers para lenguajes de dominio específico
- **Process Manager**: Herramientas de gestión de procesos
- **System Utilities**: Utilidades del sistema operativo

## 📝 Notas Importantes

- **Normas de 42**: Todos los ejercicios siguen las normas de 42 School
- **Memory Management**: Cuidado especial con memory leaks y double-free
- **Error Handling**: Manejo robusto de todos los casos de error
- **Process Safety**: Prevención de procesos zombie y memory leaks

## 🔍 Casos de Prueba

Cada ejercicio incluye casos de prueba específicos:

### ft_popen
```bash
./ft_popen
# Debe ejecutar 'ls -l' y mostrar la salida
```

### picoshell
```bash
./picoshell
# Debe ejecutar: echo "hola" | grep "h" | sed 's/h/H/'
# Salida esperada: Hola
```

### sandbox
```bash
./sandbox
# Debe probar diferentes tipos de funciones problemáticas
```

### argo
```bash
./argo test.json
# Debe parsear y serializar el archivo JSON
```

### vbc
```bash
./vbc "2+3*4"
# Debe evaluar la expresión y mostrar: 14
```

## 🏗️ Arquitectura de los Ejercicios

### Patrones de Diseño Utilizados
- **Recursive Descent Parser**: Para parsing de lenguajes
- **Abstract Syntax Tree**: Para representación de datos estructurados
- **Pipeline Pattern**: Para procesamiento de datos en cadena
- **Sandbox Pattern**: Para ejecución controlada de código

### Principios de Programación
- **Single Responsibility**: Cada función tiene una responsabilidad específica
- **Error Propagation**: Errores se propagan correctamente hacia arriba
- **Resource Management**: Gestión cuidadosa de recursos del sistema
- **Defensive Programming**: Validación de todas las entradas

---

**Autor**: dasalaza  
**Escuela**: 42 Barcelona  
**Año**: 2024  
**Especialización**: Sistemas Operativos y Parsing de Lenguajes
