#!/bin/bash

# Nombre del archivo de datos
data_file="datos.txt"

# Nombre del archivo de gráfico de salida
output_graph="Eficiencia_Empirica.pgm"

# Comando Gnuplot para generar la gráfica con líneas
gnuplot <<EOF
set term png
set output "$output_graph"

# Configura el estilo de la gráfica con líneas
set title "Mi Gráfica"
set xlabel "Tiempo en Segundos"
set ylabel "Tamaño Size()" 

# Carga los datos desde el archivo y genera la gráfica con líneas
plot "$data_file" using 1:2 with lines
EOF

echo "Gráfica generada como $output_graph."

