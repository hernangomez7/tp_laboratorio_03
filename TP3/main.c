#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int main()
{
    int opcion;
    char seguir ='s';
    Emovie* pelicula;
    int x;
    FILE* f;
    if((f=fopen("datos.bin","ab"))==NULL)
    {
        printf("error de creacion de archivo");
    }
    fclose(f);



    if( (pelicula=(Emovie*)malloc(sizeof(Emovie)))==NULL)
    {
        printf("error al asignar espacio");
    }

    do
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar\n");
        printf("3- Modificar\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");


        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                x=agregarpelicula(pelicula);
                if(x==1)
                {
                    printf("la pelicula se agrego afectivamente\n");
                }
                else
                {
                    printf("error al agregar pelicula");
                }

            break;
            case 2:
                x=borrarPelicula();
                if(x==1)
                {
                    printf("la pelicula se borro afectivamente\n");
                }
                else
                {
                    printf("no se a efectado ningun cambio\n");
                }
            break;
            case 3:
                x=ModificarPelicula(pelicula);
                if(x==1)
                {
                    printf("modificacion exitosa\n");
                }
                else
                {
                    printf("fallo al modificar\n");
                }
            break;
            case 4:
                x=generarPagina( );
                if(x==1)
                {
                    printf("creacion de pagina completa\n");
                }
                else
                {
                    printf("fallo al crear pagina\n");
                }
            break;
            case 5:
                seguir='n';
            break;
        }
    }while(seguir=='s');
    return 0;
}
