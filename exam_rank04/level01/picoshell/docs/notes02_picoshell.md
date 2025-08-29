https://github.com/Lastftw/42-Exam-rank-4/blob/main/LVL%201/picoshell.c

Este es un ejercicio más complejo que ft_popen y apunta a simular el funcionamiento interno de una pipeline en un shell.

## 🔍 1. Descripción general del problema: `picoshell`

Tienes que implementar una mini-shell que ejecute una **secuencia de comandos encadenados por pipes**, como:

``` bash
    echo hola | grep o | sed 's/o/a/g'
```

### Firma de la función

```c
int picoshell(char *cmds[]);
```

* `cmds`: array null-terminado de comandos, donde cada comando es un `argv[]` usable directamente por `execvp`.
* Cada `argv[]` está en una fila, como `cmds[0]`, `cmds[1]`, `cmds[2]`, ... hasta `NULL`.

Tu tarea es:

1. Lanzar cada comando como un proceso hijo.
2. Conectar la salida de uno con la entrada del siguiente (pipe chaining).
3. Esperar a que todos terminen.
4. Si ocurre un error en cualquier punto: cerrar todos los `fd` abiertos y retornar `1`.

---

## 🧠 2. Conceptos clave involucrados

Esto evalúa tus habilidades con:

* **pipes encadenadas**: cada par de comandos requiere un `pipe`.
* **fork y execvp**: lanzar un proceso por cada comando.
* **dup2**: redirigir `stdin` y `stdout`.
* **gestión de múltiples descriptores**: cerrar lo que no usas.
* **sin memory leaks ni file descriptor leaks**.

---

## 🧱 3. Pauta de resolución paso a paso

### 📌 Paso 1: Preparar el pipeline

* Cuenta cuántos comandos hay (hasta `NULL` en `cmds`).
* Para `N` comandos necesitas `N - 1` pipes.

### 📌 Paso 2: Loop de ejecución de los procesos

Para cada comando `i` de `cmds`:

1. Si **no es el primer comando**, duplica el `read end` del pipe anterior en `stdin`.
2. Si **no es el último comando**, duplica el `write end` del pipe actual en `stdout`.
3. Cierra todos los descriptores innecesarios dentro del hijo.
4. Ejecuta el comando con `execvp`.

**En el padre**:

* Guarda los `pid` para hacer `wait()` luego.
* Cierra los extremos del pipe que ya no se usan (para evitar leaks y que los hijos no queden bloqueados).
* Pasa al siguiente comando.

### 📌 Paso 3: Esperar a que todos los hijos terminen

* Usa `waitpid` en un bucle o `wait` si no necesitas controlar cada PID individual.

### 📌 Paso 4: Manejo de errores

* Si algo falla (pipe, fork, exec), cierra todos los descriptores abiertos.
* Retorna `1`.

---

## 🧠 Ejemplo simplificado de estructura

Si ejecutas:

```bash
echo hola | grep o | sed 's/o/a/g'
```

Visualmente el pipeline sería:

```text
[echo hola] → [grep o] → [sed 's/o/a/g']
     stdout       stdin stdout     stdin
```

* Cada bloque se comunica con el siguiente por un pipe.
* El primero escribe en el primer pipe.
* El del medio lee de un pipe y escribe en otro.
* El último solo lee.

---

## ⚠️ 4. Errores comunes que debes evitar

* ❌ Olvidar cerrar extremos del pipe en el padre o en los hijos → cuelgue del proceso.
* ❌ No esperar a los hijos → procesos zombies.
* ❌ Confundir qué extremo del pipe usar como entrada y cuál como salida.
* ❌ Usar mal el `argv[]` que recibes → asegúrate de que cada fila es directamente usable en `execvp`.
* ❌ No resetear los fds entre procesos → un `dup2` mal hecho puede hacer que stdout o stdin estén mal redirigidos.

---
