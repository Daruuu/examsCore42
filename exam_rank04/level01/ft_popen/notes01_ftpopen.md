
## 🔍 1. Descripción general del problema: `ft_popen`
https://github.com/Lastftw/42-Exam-rank-4/blob/main/LVL%201/ft_popen.c

Debes implementar una función similar a `popen` de POSIX, que lanza un comando como un proceso hijo, y conecta **su entrada o salida estándar** a un file descriptor que se retorna al proceso padre.

### Prototipo de la función

```c
int ft_popen(const char *file, char const *argv[], char type);
```

* `file`: el ejecutable que quieres lanzar.
* `argv`: argumentos para el ejecutable (null-terminated).
* `type`:
  * `'r'` para leer desde la salida del comando.
  * `'w'` para escribir en la entrada del comando.
* Retorna: el file descriptor conectado a `stdout` del hijo (`'r'`) o a `stdin` del hijo (`'w'`), o `-1` si ocurre un error.

---

## 🧠 2. Conceptos clave involucrados

Tienes que demostrar dominio sobre:

* `pipe()` – creación de un canal de comunicación entre procesos.
* `fork()` – crear un proceso hijo.
* `dup2()` – redireccionar entrada/salida estándar.
* `execvp()` – ejecutar un nuevo proceso reemplazando el actual.
* `close()` – cerrar descriptores para evitar leaks.
* Gestión de errores y validación de parámetros.

---

## 🧱 3. Pauta de resolución paso a paso

### Paso 1: Validación de entrada

* Asegúrate de que `file` y `argv` no sean `NULL`.
* `type` debe ser `'r'` o `'w'`. Si no, retorna `-1`.

### Paso 2: Crear un pipe

* Usa `pipe()` para obtener dos descriptores `[read_fd, write_fd]`.

### Paso 3: Crear el proceso hijo

* Llama a `fork()`.

    * Si falla, cierra ambos extremos del pipe y retorna `-1`.

### Paso 4: En el proceso hijo

Dependiendo del tipo (`'r'` o `'w'`):

* Si `'r'`: el padre va a **leer** la salida del hijo.

    * Entonces el hijo redirige su **stdout al write\_fd**.
* Si `'w'`: el padre va a **escribir** en la entrada del hijo.

    * Entonces el hijo redirige su **stdin al read\_fd**.

Después:

* Cierra todos los descriptores que no necesita (tanto el extremo del pipe que no usará como el otro del padre).
* Llama a `execvp(file, argv)` para ejecutar el comando.

⚠️ Importante: si `execvp` falla, debes llamar a `exit(1)` (o un código de error).

### Paso 5: En el proceso padre

* Cierra el extremo que **no** vas a usar (opuesto al que vas a retornar).
* Retorna el file descriptor que sí vas a usar (para leer o escribir).

---

## ⚠️ 4. Errores comunes que debes evitar

* ❌ No cerrar los descriptores en el hijo y en el padre → **file descriptor leak**.
* ❌ No manejar correctamente el tipo `'r'` vs `'w'` → puedes redirigir mal los descriptores.
* ❌ No validar la entrada → puedes acceder a punteros inválidos.
* ❌ No usar `exit()` si `execvp` falla → el hijo sigue ejecutando código innecesario.
* ❌ Confundir qué extremo del pipe va al hijo y cuál al padre.

---
