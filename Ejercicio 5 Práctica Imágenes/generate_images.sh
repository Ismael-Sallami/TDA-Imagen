#!/bin/bash

# Directorio donde se guardarán las imágenes
output_directory="imagenes_generadas"
mkdir -p "$output_directory"

# Número de imágenes a generar
num_images=5

# Rango de tamaños de las imágenes (ancho y alto)
min_size=100
max_size=800

# Genera las imágenes aleatorias
for ((i = 1; i <= num_images; i++)); do
    width=$(shuf -i $min_size-$max_size -n 1)
    height=$(shuf -i $min_size-$max_size -n 1)
    output_file="$output_directory/image_${i}.pgm"
    
    # Crea una imagen en blanco con tamaño aleatorio
    convert -size "${width}x${height}" xc:white "$output_file"

    echo "Imagen generada: $output_file"
done

echo "Se han generado $num_images imágenes en el directorio $output_directory"

