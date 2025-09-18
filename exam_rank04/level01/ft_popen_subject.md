# ft_popen

## Descripción
Implementa una función `ft_popen` que simula el comportamiento de `popen()` de la biblioteca estándar de C. Esta función permite ejecutar un comando del sistema y obtener acceso a su entrada o salida a través de un pipe.

## Prototipo
```c
int ft_popen(const char *file, char *const argv[], char type);
```

## Parámetros
- `file`: Nombre del programa a ejecutar
- `argv`: Array de argumentos para el programa
- `type`: Tipo de acceso ('r' para lectura, 'w' para escritura)

## Valor de Retorno
- File descriptor del pipe en caso de éxito
- -1 en caso de error

## Conceptos Clave
- **Pipes**: Comunicación entre procesos
- **Fork**: Creación de procesos hijo
- **Exec**: Reemplazo de imagen de proceso
- **Dup2**: Redirección de file descriptors

## Ejemplo de Uso
```c
int fd = ft_popen("ls", (char *const[]){"ls", "-l", NULL}, 'r');
char buffer[1024];
read(fd, buffer, sizeof(buffer));
close(fd);
```