/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>
#include <algorithm>

#include <cassert>
using namespace std;

//método que tiene como objetivo llevar a cabo la operación invierte
const byte MAX_BYTE_VALUE=255;

void Image::Invert(){
    for (int i=0; i < get_rows(); i++)
        for (int j=0; j < get_cols(); j++)
            set_pixel( i, j, MAX_BYTE_VALUE - get_pixel(i, j));
}

//Modifica el contraste de una imagen
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2){
    //comprobaciones
    assert(0<=in1 && in1 <=255 && 0<=in2 && in2 <=255 && 0<=out1 && out1 <=255 && 0<=out2 && out2 <=255 && in1<in2 && out1<out2);
    double e1=in1,e2=in2,s1=out1,s2=out2;
    //calculo de valor constante
    double valor=(s2-s1)/(e2-e1);
    for (int i = 0; i < (get_cols() * get_rows()); i++) {
    // Nos aseguramos de que el píxel de entrada esté en el rango válido
        byte pixel = get_pixel(i);
        if (pixel >= in1 && pixel <= in2) {
            double pre_insert = (s1 + (valor * (pixel - e1)));
            byte insert = static_cast<byte>(round(pre_insert));
            set_pixel(i, insert);
        }
        // Si el píxel de entrada está fuera del rango, lo dejamos sin cambios.
    }
}

// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image::Mean (int i, int j, int height, int width) const{
    double media=0;
    for(int x=i;x<height+i;x++){
        for(int y=j;y<width+j;y++){
            media+=get_pixel(x,y);
        }
    }
    return media/(height*width);
}

// Genera un icono como reducción de una imagen.
Image Image::Subsample(int factor) const{
   assert(factor>0);
   int new_rows = get_rows() / factor;
   int new_cols = get_cols() / factor;
   Image icono(new_rows, new_cols);
   for(int i=0,x=0;i<get_rows();i+=factor){
      for(int j=0,y=0;j<get_cols();j+=factor){
        double valor=Mean(i,j,factor,factor);
        icono.set_pixel(x,y,valor);
        y++;
      }
      x++;
   }
   return icono;
}

 // Genera una subimagen.
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    assert(nrow>=0 && ncol>=0 && height>=0 && width>=0);
    Image imagen_recortada(height,width);
    int posi=0;
    for(int i=nrow;i<nrow+height;i++){
        int posj=0;
        for(int j=ncol;j<ncol+width;j++){
            imagen_recortada.set_pixel(posi,posj,get_pixel(i,j));
            posj++;
        }
        posi++;
    }
    return imagen_recortada;
}

//Baraja pseudoaleatoriamente las filas de una imagen.

//método principal que expone el pdf.

/*void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        for (int c=0; c<cols;c++)
            temp.set_pixel(r,c,get_pixel(newr,c));
        }
    Copy(temp);
}*/

//Método adaptado al tipo 2 de la implementación de la matriz imagen.

void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        temp.img[r]=img[newr];
    }
    Copy(temp);
}


// Genera una imagen aumentada 2x.
Image Image::Zoom2X() const{
   //creamos nuestro objeto image resultado del zoom
   Image resultado((2*get_rows())-1,(2*get_cols())-1);


   //copiamos la matriz origen en la de salida, no usamos copy ya que no queremos que modifique ni las filas ni las columnas
   for(int i=0;i<get_rows();i++){
       for(int j=0;j<get_cols();j++){
           resultado.set_pixel(i,j,get_pixel(i,j));
       }
   }


   int rows=get_rows();
   int cols=get_cols();
   int rows_salida=resultado.get_rows();
   int cols_salida=resultado.get_cols();
  
   //aumentamos columnas
   for(int i=0;i < rows_salida;i++){
       for(int j=0;j<cols_salida-1;j+=2){
           double value=resultado.get_pixel(i,j)+resultado.get_pixel(i,j+1);
           int valor=round(value/2);
               for(int x=cols_salida-1;x>j+1;x--){
                   resultado.set_pixel(i,x,resultado.get_pixel(i,x-1));
                   }
                   resultado.set_pixel(i,j+1,valor);
                   
       }
   }

   //Aumentamos filas
   for(int i=0;i<rows_salida-1;i+=2){
    for(int j=0;j<cols_salida;j++){
        double value=resultado.get_pixel(i,j)+resultado.get_pixel(i+1,j);
        int valor=round(value/2);
        for(int x=rows_salida-1;x>i+1;x--){
            resultado.set_pixel(x,j,resultado.get_pixel(x-1,j));
        }
        resultado.set_pixel(i+1,j,valor);
    }
   }
   return resultado;
}       