#!/bin/bash

# Lista de nombres de carpetas y archivos
names=("ft_strlen" "ft_swap" "putstr" "repeat_alpha" "rev_print" "rot_13" "rotone" "search_and_replace" "ulstr")

# Crear las carpetas y archivos .c
for name in "${names[@]}"
do
  mkdir -p "$name"  # Crear la carpeta
  touch "$name/$name.c"  # Crear el archivo .c dentro de la carpeta
done

echo "Carpetas y archivos creados con éxito."

