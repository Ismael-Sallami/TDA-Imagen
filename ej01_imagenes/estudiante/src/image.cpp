/**
 * @file image.cpp
 * @brief Fichero con definiciones para los métodos primitivos de la clase Image
 *
 */

#include <cstring>
#include <cassert>
#include <iostream>

#include <image.h>
#include <imageIO.h>

using namespace std;

/********************************
      FUNCIONES PRIVADAS
********************************/

//Implementación inicial de la matriz de la imagen Tipo 1.
/*void Image::Allocate(int nrows, int ncols, byte * buffer){
    rows = nrows;
    cols = ncols;

    img = new byte * [rows];

    if (buffer != 0)
        img[0] = buffer;
    else
        img[0] = new byte [rows * cols];

    for (int i=1; i < rows; i++)
        img[i] = img[i-1] + cols;
}*/

//Implemenación de la matriz con filas no contiguas Tipo 2.
void Image::Allocate(int nrows, int ncols, byte* buffer) {
    rows = nrows;
    cols = ncols;
    img = new byte*[rows];
    //inicializa la matriz con filas no contiguas en memoria
    for (int i = 0; i < rows; ++i) {
            img[i] = new byte[cols];
        }

    if (buffer != nullptr) {
        // Utiliza el búfer proporcionado
        int pos=0;
        for (int i = 0; i < rows; ++i) {
            for(int j=0;j<cols;++j){
                img[i][j]=buffer[pos++];
            }
        }
    }
}


// Función auxiliar para inicializar imágenes con valores por defecto o a partir de un buffer de datos
void Image::Initialize (int nrows, int ncols, byte * buffer){
    if ((nrows == 0) || (ncols == 0)){
        rows = cols = 0;
        img = 0;
    }
    else Allocate(nrows, ncols, buffer);
}

// Función auxiliar para copiar objetos Imagen

/*void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int k=0; k<rows*cols;k++)
        set_pixel(k,orig.get_pixel(k));
}*/

void Image::Copy(const Image & orig){
    Initialize(orig.rows,orig.cols);
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++)
            set_pixel(i,j,orig.get_pixel(i,j));
    }
}

// Función auxiliar para destruir objetos Imagen
bool Image::Empty() const{
    return (rows == 0) || (cols == 0);
}

//destroy para la implementación de tipo I
/*void Image::Destroy(){
    if (!Empty()){
        delete [] img[0];
        delete [] img;
    }
}*/

//destroy para la implementación de tipo II

void Image::Destroy(){
    if(!Empty()){
        for(int i=0;i<rows;++i){
            delete[]img[i];
        }
        delete [] img;
    }
}

LoadResult Image::LoadFromPGM(const char *file_path) {
    if (ReadImageKind(file_path) != IMG_PGM)
        return LoadResult::NOT_PGM;

    int imageRows, imageCols;
    byte *buffer = ReadPGMImage(file_path, imageRows, imageCols);

    if (!buffer)
        return LoadResult::READING_ERROR;

    Initialize(imageRows, imageCols, buffer);
    return LoadResult::SUCCESS;
}

/********************************
       FUNCIONES PÚBLICAS
********************************/

// Constructor por defecto

Image::Image(){
    Initialize();
}

// Constructores con parámetros
Image::Image (int nrows, int ncols, byte value){
    Initialize(nrows, ncols);
    for (int k=0; k<rows*cols; k++) set_pixel(k,value);
}

bool Image::Load (const char * file_path) {
    Destroy();
    return LoadFromPGM(file_path) == LoadResult::SUCCESS;
}

// Constructor de copias

Image::Image (const Image & orig){
    assert (this != &orig);
    Copy(orig);
}

// Destructor

Image::~Image(){
    Destroy();
}

// Operador de Asignación

Image & Image::operator= (const Image & orig){
    if (this != &orig){
        Destroy();
        Copy(orig);
    }
    return *this;
}

// Métodos de acceso a los campos de la clase

int Image::get_rows() const {
    return rows;
}

int Image::get_cols() const {
    return cols;
}

int Image::size() const{
    return get_rows()*get_cols();
}

// Métodos básicos de edición de imágenes
void Image::set_pixel (int i, int j, byte value) {
    img[i][j] = value;
}
byte Image::get_pixel (int i, int j) const {
    return img[i][j];
}
//set y get desenrollado para la implementación tipo I
/*
// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?
    img[0][k] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?
    return img[0][k];
}
*/
//cambiamos set y get pixel desenrollada, para que funcione el constructor,también
//podemos optar por cambiar el constructor.

//get y set desenrollado para la implementación tipo II

// This doesn't work if representation changes
void Image::set_pixel (int k, byte value) {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse set_pixel(i,j,value)?

    int r=k/rows;//calcula la posición en la fila
    int c=k%cols; //calcula la posición en la columna

    img[r][c] = value;
}

// This doesn't work if representation changes
byte Image::get_pixel (int k) const {
    // TODO this makes assumptions about the internal representation
    // TODO Can you reuse get_pixel(i,j)?

    int r=k/rows;//calcula la posición en la fila
    int c=k%cols; //calcula la posición en la columna
    return img[r][c];
}

// Métodos para almacenar y cargar imagenes en disco
//Método Save para la implementación I.
/*bool Image::Save (const char * file_path) const {
    // TODO this makes assumptions about the internal representation
    byte * p = img[0];
    return WritePGMImage(file_path, p, rows, cols);
}*/

//Método Save para la implementación de tipo II

bool Image::Save(const char * file_path)const{
    //creamos un puntero para almacenar las filas de la imagen
    byte * aux=new byte[size()];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            //lo multiplicamos por i para acceder a la fila y sumamos j para posicionarnos en la posición de la columna
            aux[i*cols+j]=get_pixel(i,j);
        }
    }
    //no hacemos directamente return ya que no podemos eliminar aux directamente ya que debemos de usarlo
    bool PNG=WritePGMImage(file_path,aux,rows,cols);
    delete [] aux;
    return PNG;
}