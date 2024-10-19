#!/bin/bash

# Lista de nombres de carpetas y archivos
names=(
	"alpha_mirror"
	"camel_to_snake"
	"do_op"
	"ft_atoi"
	"ft_strcmp"
	"ft_strcspn"
	"ft_strdup"
	"ft_strpbrk"
	"ft_strrev"
	"ft_strspn"
	"inter"
	"is_power_of_2"
	"last_word"
	"max"
	"print_bits"
	"reverse_bits"
	"snake_to_camel"
	"swap_bits"
	"union"
	"wdmatch"
)

# Crear las carpetas y archivos .c
for name in "${names[@]}"
do
  mkdir -p "$name"  # Crear la carpeta
  touch "$name/$name.c"  # Crear el archivo .c dentro de la carpeta
done

echo "Carpetas y archivos creados con éxito."

