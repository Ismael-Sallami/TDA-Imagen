# TDA-Imagen

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/inicio.png)

# Introducción

En esta práctica hemos llevado a cabo el hecho de tratar con el objeto imagen en formato pgm. Básicamente la práctica se ha centrado en el desarrollo de diversos métodos para que podamos tratar con imagenes. Los métodos nos han permitido poder ajustar el contraste de una imagen, poder hacer zoom 2x de esta, generar tanto iconos como subimagenes a partir de un objeto imagen, barajar pseudoaleatoriamente las filas de este y poder invertir las imagenes con el color opuesto de cad píxel. Además esta clase ofrece operaciones de lectura y escritura de imágenes, manipulación de pixeles y aplicación de filtros. En resumen, esta clase nos permite editar una imagen y realizar diversas operaciones sobre esta.
Esta clase ha sido realizada por los alumnos Ismael Sallami Moreno y por Fernando Gracia Choin, alumnos del doble grado Informática y Administración y Dirección de empresas.
Hemos intentado aplicar las técnicas más eficientes acorde el conocimiento adquirido a lo largo de nuestra enseñanza en dicha carrera en la Universidad de Granada(UGR).

# Ejecutables

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/ej01_imagenes/estudiante/doc/invert.png)
## Negativo:

Calcula el negativo de una imagen.

> __negativo__ \<FichImagenOriginal\> \<FichImagenDestino\>

@param "<FichImagenOriginal>" Imagen PGM a la que se va a calcular.

@param <FichImagenDestino> Imagen PGM resultado de calcular el negativo.

Esta funcion se encarga de calcular el negativo de una imagen y para ello se sirve un algoritmo que usa una constante que representa el mayor valor de byte (255) y calculando el byte inverso de cada byte de la imagen, de tal manera que en dicha posición calcula el inverso, reflejando la imagen inversa.

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/AdjustContrast.png)
## Contraste:

Ajusta el contraste de una imagen.

> __contraste__ \<FichImagenOriginal\> \<FichImagenDestino\> \<in1\> \<in2\> \<out1\> \<out2\>
@param "<FichImagenOriginal>" Imagen PGM a la que se va a modificar el contraste.

@param <FichImagenDestino> Imagen PGM resultado de modificar el contraste.

@param <in1> umbral inferior de entrada.

@param <in2> umbral superior de entrada.

@param <out1> umbral inferior de salida.

@param <out2> umbral superior de salida.

Esta función se encarga de llevar acabo el ajuste del contraste mediante los parámetros que recibe, se sirve básicamente de un algoritmo
en el consigue modificar cada pixel para conseguir el contraste deseado.

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/Mean.png)
## Mean:

Calcula la media del contorno establecido(suele ser matriz/imagen).

@param <i> fila de la matriz.

@param <j> columna de la matriz.

@param <height> altura de la imagen.

@param <width> anchura de la matriz.

Es una función que se utilzada para complementar otras, en este caso es en la de generar el icono de una imagen.
![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/shuffle.png)
## Barajar:

Baraja pseudoaleatoriamente las filas de una imagen.
>__barajar__<FichImagenOriginal\>

@param "<FichImagenOriginal>" Imagen PGM a la que se va a realizar el barajado de las filas.

Esta función se encarga de barajar pseudoaleatoriamente las filas de una imagen, estableciendo una imagen distinta a la original, ya que es 
resultado del barajado de las filas de esta. Para ello se sirve de una algoritmo específico, y posteriormente recorre todas las filas para llevar
acabo dicha acción. Modifica el objeto imagen original.

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/Subsample.png)
## Icono:

Genera el icono de una imagen.

> __icono__ <FichImagenOriginal\> \<FichImagenDestino\> \<factor\>

@param "<FichImagenOriginal>" Imagen PGM a la que se va a calcular el icono.

@param <FichImagenDestino> Imagen PGM resultado de calcular el icono.

@param <factor> factor de reduccion para calcular el icono.

Esta función se encarga de generar el icono de una imagen, para ello necesita un factor, a partir del cual genera dicha reducción, y además
usa la función mean mencionada anteriormente.

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/Subimagen.png)
## Subimagen:

Genera una subimagen

> __subimagen__ <FichImagenOriginal\> \<FichImagenDestino\> \<nrow\> \<ncool\> \<height\> \<width\>

@param "<FichImagenOriginal>" Imagen PGM a la que se va a calcular la subimagen.

@param "<FichImagenDestino>" Imagen PGM resultado de calcular la subimagen.

@param <nrow> fila de la matriz.

@param <ncol> columna de la matriz.

@param <height> altura de la imagen.

@param <width> anchura de la matriz.

Esta funcion se encarga de calcular la subimagen a partir de el objeto imagen y en función de los parámetros de entrada, para ello
básicamente se encarga de recortar dicha imagen.

![](https://github.com/Ismael-Sallami/TDA-Imagen/blob/main/image_use/Zoom.png)
## Zoom:

Se encarga de hacer zoom2x a una imagen.
> __zoom__ <FichImagenOriginal\> \<FichImagenDestino\>

@param "<FichImagenOriginal>" Imagen PGM a la que se le va hacer el zoom2x.

@param "<FichImagenDestino>" Imagen PGM resultado de hacer el zoom2x.

Esta función trata de hacer el zoom2x de una determinada foto, y para ello tiene 2 partes, primero se centra en las columnas y posteriormente
en las filas, de esta manera el algoritmo es má legible y de forma más estructurada.

# AUTHOR
> ISMAEL SALLAMI MORENO



*/
