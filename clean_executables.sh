#!/bin/bash

# Función para buscar y eliminar ejecutables
eliminar_ejecutables() {
    local DIR=${1:-.}   # Carpeta a analizar (por defecto la actual)

    echo "🔍 Buscando ejecutables en: $DIR"

    # Buscar en todas las profundidades archivos ejecutables y eliminarlos
    find "$DIR" -type f -perm -u=x -exec rm -i {} \;

    echo "✅ Eliminación finalizada en $DIR"
}

# Llamada a la función
# Si quieres pasarle un directorio específico: ./script.sh /ruta/carpeta
eliminar_ejecutables "$1"

