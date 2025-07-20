
Este problema mezcla conceptos de ejecución de funciones en entornos controlados, manejo de señales, control de tiempo de ejecución y procesos zombies. Es un desafío más teórico y técnico que los anteriores.

---

## 🔍 1. Descripción general del problema: `sandbox`

Debes ejecutar una función `f` dentro de un proceso hijo y detectar si:

* Termina correctamente (`exit code 0`) → función **"nice"** → retornas `1`.
* Termina por **señal**, **timeout**, o **exit code distinto de 0** → función **"bad"** → retornas `0`.
* Ocurre un **error interno en tu implementación** → retornas `-1`.

Además, si `verbose == true`, debes imprimir mensajes específicos según lo que haya pasado.

---

## 🧠 2. Conceptos clave involucrados

Este ejercicio pone a prueba tu manejo de:

* **Procesos hijos (`fork`)**.
* **Ejecución de funciones con timeout (`alarm`)**.
* **Manejo de señales (`sigaction`)**.
* **Inspección de estado del hijo (`waitpid` con `WIFEXITED`, `WIFSIGNALED`, etc)**.
* **Evitar zombies** – asegurar que los procesos se cierren bien.
* **kill()** para terminar procesos que exceden el tiempo permitido.

---

## 🧱 3. Pauta de resolución paso a paso

### Paso 1: Crear el proceso hijo

* Haz un `fork()` para ejecutar la función `f()` en un proceso separado.

### Paso 2: En el hijo

* Ejecuta la función `f()` directamente.
* Luego llama a `exit(0)` si todo fue bien (el hijo no debe retornar nunca al padre).
* No hagas *printf*, *alarm* ni *sigaction* en el hijo.

### Paso 3: En el padre

#### a) Configura el timeout

* Usa `alarm(timeout)` para establecer el tiempo máximo permitido.

#### b) Usa `waitpid()` para esperar al hijo

* Puedes hacerlo de forma **bloqueante** o usando `WNOHANG` + bucle y control manual del timeout (opcional).
* Espera a que el hijo:

  * Termine correctamente (`WIFEXITED`)
  * Sea matado por una señal (`WIFSIGNALED`)
  * No termine dentro del timeout → deberás usar `kill(pid, SIGKILL)`.

#### c) Verifica el resultado

* Si `WIFEXITED` y `exit code == 0` → función nice → `return 1`.
* Si `exit code != 0` → función bad → `return 0`.
* Si `WIFSIGNALED` → función bad → `return 0` e imprime `strsignal(sig)`.
* Si fue matado por timeout → `kill(pid, SIGKILL)` y retorna `0`.

#### d) Imprimir si `verbose == true`

* Usa los mensajes EXACTOS del enunciado.
* Usa `strsignal(signal)` para describir señales como `"Segmentation fault"`, `"Abort"`...

---

## 📌 Casos que debes cubrir

| Caso                                               | Acción | Resultado | Mensaje (si `verbose`)                                |
| -------------------------------------------------- | ------ | --------- | ----------------------------------------------------- |
| La función `f` termina con `exit(0)`               | ✅      | `1`       | `"Nice function!\n"`                                  |
| La función `f` termina con otro `exit(x)`          | ❌      | `0`       | `"Bad function: exited with code x\n"`                |
| La función `f` causa un `SIGSEGV`, `SIGABRT`, etc. | ❌      | `0`       | `"Bad function: <signal>\n"`                          |
| La función `f` no termina a tiempo                 | ⏰      | `0`       | `"Bad function: timed out after <timeout> seconds\n"` |
| Tu código falla                                    | ❗      | `-1`      | *(no imprime)*                                        |

---

## ⚠️ 4. Errores comunes que debes evitar

* ❌ No matar el proceso si pasa el timeout.
* ❌ No esperar bien al proceso → zombies.
* ❌ No detectar bien señales (`WIFSIGNALED`).
* ❌ Imprimir mensajes incorrectos o mal formateados.
* ❌ Olvidar `exit()` en el hijo → comportamiento impredecible.
* ❌ Llamar funciones no permitidas o hacer `printf` desde el hijo.

---

¿Quieres que pasemos ahora a los del **nivel 02** (argo, vbc) o prefieres detenerte aquí para trabajar en los tres primeros?
