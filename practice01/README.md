# practice01 - mini_serv documentado

Esta carpeta contiene una versión documentada de la solución de
`exam_rank06/original/valid-version-lyl.c`.

## Objetivo

El programa implementa un servidor TCP de chat sobre `127.0.0.1`. Cada cliente
recibe un ID, puede enviar líneas terminadas en `\n` y el servidor retransmite
cada línea a los demás clientes.

## Conceptos principales

- `select()` permite atender varios descriptores en un único bucle.
- `ids[fd]` relaciona un descriptor con el ID visible del cliente.
- `bufs[fd]` conserva datos parciales hasta recibir `\n`.
- `extract_message()` separa una línea completa del resto del buffer.
- `send_all()` difunde avisos y mensajes a todos excepto al emisor.

## Compilación y ejecución

```bash
cc -Wall -Wextra -Werror mini_serv.c -o mini_serv
./mini_serv 8081
```

En otra terminal:

```bash
nc 127.0.0.1 8081
```

Nota: esta copia conserva la lógica del archivo original. Antes de entregarla
al tester del examen, hay que verificar sus restricciones exactas de funciones,
especialmente el uso de `inet_addr()`.
