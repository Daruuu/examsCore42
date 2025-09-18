# picoshell

## Descripción
Implementa un shell minimalista que puede ejecutar pipelines de comandos. El programa debe ser capaz de ejecutar múltiples comandos conectados mediante pipes, donde la salida de un comando se convierte en la entrada del siguiente.

## Prototipo
```c
int picoshell(char** cmds[]);
```

## Parámetros
- `cmds`: Array de arrays de comandos, terminado en NULL

## Conceptos Clave
- **Pipeline**: Cadena de comandos conectados por pipes
- **Redirección**: STDIN/STDOUT redireccionados entre procesos
- **Gestión de procesos**: Fork y wait para múltiples procesos
- **Gestión de pipes**: Creación y cierre correcto de pipes

## Ejemplo de Uso
```c
char* cmd1[] = {"echo", "hola", NULL};
char* cmd2[] = {"grep", "h", NULL};
char* cmd3[] = {"sed", "s/h/H/", NULL};
char** cmds[] = {cmd1, cmd2, cmd3, NULL};

picoshell(cmds);
```

## Comportamiento Esperado
- Ejecuta comandos en secuencia
- Conecta la salida de cada comando con la entrada del siguiente
- Espera a que todos los procesos terminen
- Retorna 0 en caso de éxito, 1 en caso de error