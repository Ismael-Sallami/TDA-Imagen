// Fichero: barajar.cpp
// Baraja las filas de una imagen PGM
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include<ctime>

#include <image.h>

using namespace std;

int main (int argc, char *argv[]){
 
   char *origen, *destino; // nombres de los ficheros
  Image image;

  //vemos el tiempo inicial
  clock_t tini,tfin;

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  /*
   // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;
  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;
  */ //comentamos esta sección para que me genere una lista de datos concretos que vamos a usar posteriormente

  // Baraja las filas de una imagen
  tini=clock(); 
  image.ShuffleRows();
  tfin=clock();
  
  // Guardar la imagen resultado en el fichero
  if (!image.Save(destino)){
    //cout  << "La imagen se guardo en " << destino << endl;
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  //una vez ha realizado las tareas medimos de nuevo el tiempo

  // Mostramos resultados
cout << "Ticks de reloj : " << tfin-tini << endl;
cout << "Segundos : " << (tfin-tini)/(double)CLOCKS_PER_SEC
<< endl;

  cout  << (tfin-tini)/(double)CLOCKS_PER_SEC <<  " " << image.size() << endl;

  return 0;
}
