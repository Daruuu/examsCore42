#!/bin/bash

# Lista de nombres de carpetas y archivos
names=(
"flood_fill"
"fprime"
"ft_itoa"
"ft_list_foreach"
"ft_list_remove_if"
"ft_split"
"rev_wstr"
"rostring"
"sort_int_tab"
"sort_list"
)

# Crear las carpetas y archivos .c
for name in "${names[@]}"
do
  mkdir -p "$name"  # Crear la carpeta
  touch "$name/$name.c"  # Crear el archivo .c dentro de la carpeta
done

echo "Carpetas y archivos creados con éxito."

