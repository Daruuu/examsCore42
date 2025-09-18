# sandbox

## Descripción
Implementa una función `sandbox` que ejecuta una función en un entorno controlado para detectar comportamientos problemáticos como segmentation faults, timeouts, o códigos de salida incorrectos.

## Prototipo
```c
int sandbox(void (*f)(void), unsigned int timeout, bool verbose);
```

## Parámetros
- `f`: Función a ejecutar en el sandbox
- `timeout`: Tiempo límite en segundos
- `verbose`: Si mostrar mensajes informativos

## Valor de Retorno
- 1: Función ejecutada correctamente
- 0: Función problemática detectada
- -1: Error en la función sandbox

## Conceptos Clave
- **Fork**: Ejecutar función en proceso separado
- **Signals**: Manejo de señales (SIGALRM, SIGKILL)
- **Wait**: Esperar terminación de proceso hijo
- **Process monitoring**: Detectar diferentes tipos de terminación

## Tipos de Problemas Detectados
- **Timeout**: Función que no termina en tiempo límite
- **Segmentation fault**: Acceso a memoria inválida
- **Exit code**: Código de salida diferente de 0
- **Signals**: Terminación por señal (SIGABRT, SIGKILL, etc.)

## Mensajes de Salida
- "Nice function!\n"
- "Bad function: exited with code <exit_code>\n"
- "Bad function: <signal description>\n"
- "Bad function: timed out after <timeout> seconds\n"