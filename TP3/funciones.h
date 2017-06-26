
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}Emovie;


/**
 *  agrega una pelicula al archivo binario.
 *  @param puntero de estructura dinamico.
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 */
int agregarpelicula(Emovie* );

/**
 *  borra una pelicula del archivo binario.
 *  @return retorna 1 o 0 de acuerdo a si pudo borrar la pelicula o no.
 */
int borrarPelicula(void);

/**
 *  pasa datos de un archivo hacia otro archivo.
 */
void REescritor(void);

int ModificarPelicula(Emovie* );
/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @return retorna 1 o 0 de acuerdo a si pudo generar la pagina o no.
 */
int generarPagina(void );

