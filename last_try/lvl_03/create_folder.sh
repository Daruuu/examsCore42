#!/bin/bash

# Lista de nombres de carpetas y archivos
names=(
  "add_prime_sum"
  "epur_str"
  "expand_str"
  "ft_atoi_base"
  "ft_list_size"
  "ft_range"
  "ft_rrange"
  "hidenp"
  "lcm"
  "paramsum"
  "pgcd"
  "print_hex"
  "rstr_capitalizer"
  "str_capitalizer"
  "tab_mult"
)

# Crear las carpetas y archivos .c
for name in "${names[@]}"
do
  mkdir -p "$name"  # Crear la carpeta
  touch "$name/$name.c"  # Crear el archivo .c dentro de la carpeta
done

echo "Carpetas y archivos creados con éxito."

