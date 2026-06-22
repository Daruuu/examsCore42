#!/bin/bash
# Ejecuta todos los mapas de prueba en bsq-original.
# Uso: ./run_tests.sh [ruta_al_binario]

DIR="$(cd "$(dirname "$0")" && pwd)"
BSQ="${1:-$DIR/bsq_test}"

if [ ! -x "$BSQ" ]; then
	echo "Compilando bsq_test..."
	ln -sf bsq_exam.h "$DIR/bsq.h"
	gcc -Wall -Wextra "$DIR/bsq_exam.c" -o "$BSQ" || exit 1
fi

for f in "$DIR"/test_map*.txt; do
	echo "=== $(basename "$f") ==="
	"$BSQ" "$f" 2>&1
	echo
done
