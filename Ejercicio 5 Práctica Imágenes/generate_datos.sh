#!/bin/bash

# Directorio donde se encuentran las imágenes generadas
input_directory="imagenes_generadas"

# Ruta absoluta al programa C++
program="../ej01_imagenes/barajar"

#Directorio donde se guardan las imágenes de salida
output_directory="imagenes_barajadas"

# Nombre del archivo de salida
output_file="datos.txt"

# Limpia el archivo de salida o crea uno nuevo
> "$output_file"

# Itera sobre las imágenes en el directorio y ejecuta el programa
for image in "$input_directory"/*.pgm; do
    if [ -f "$image" ]; then
        # Nombre del archivo de salida (imagen generada por el programa)
        output_image="$output_directory/$(basename "$image")_editada.pgm"

        # Ejecuta el programa con la imagen como entrada y el nombre del archivo de salida
        "$program" "$image" "$output_image" >> "$output_file"
        echo "Procesada imagen: $image"

    fi
done

echo "Proceso completado. Los resultados se han guardado en $output_file"

