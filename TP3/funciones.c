#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int agregarpelicula(Emovie* strucDY)
{
    system("cls");
    FILE* file;
    int x=0;

    do
    {
    printf("ingrese titulo :");
    fflush(stdin);
    gets(strucDY->titulo);
    }while(strlen(strucDY->titulo)>20);

    do
    {
    printf("ingrese genero :");
    fflush(stdin);
    gets(strucDY->genero);
    }while(strlen(strucDY->genero)>20);

    do
    {
    printf("ingrese duracion (min):");
    scanf("%d",&(strucDY->duracion));
    }while(strucDY->duracion>600||strucDY->duracion<0);

    do
    {
    printf("ingrese descripcion :");
    fflush(stdin);
    gets(strucDY->descripcion);
    }while(strlen(strucDY->descripcion)>50);

    do
    {
        printf("ingrese puntaje (de/100):");
        scanf("%d",&(strucDY->puntaje));
    }while(strucDY->puntaje>100||strucDY->puntaje<0);


    do
    {
    printf("ingrese nombre de foto con extencion:");
    fflush(stdin);
    gets(strucDY->linkImagen);
    }while(strlen(strucDY->linkImagen)>50);


    file=fopen("datos.bin","a+b");

    x=fwrite(strucDY,sizeof(Emovie),1,file);

    fclose(file);
    system("cls");

    return x;
}


int borrarPelicula()
{
    system("cls");
    FILE* lector;
    FILE* escritor;
    char titulo[30];
    Emovie peli;
    int x=0;


    printf("escriba el nombre para borrar :");
    fflush(stdin);
    gets(titulo);
    system("cls");

    lector=fopen("datos.bin","r+b");
    if(lector==NULL)
    {
        printf("\nno se pudo leer archivo\n");
    }
    escritor=fopen("datosaux.bin","w+b");
    if(escritor==NULL)
    {
        printf("\nno se pudo escribir archivo\n");
    }

        while(!feof(lector))
        {
            if((fread(&peli,sizeof(Emovie),1,lector))==1)
            {
                if(stricmp(titulo,peli.titulo)!=0)
                {
                    x=1;
                    fwrite(&peli,sizeof(Emovie),1,escritor);
                }
            }
        }
    fclose(lector);
    fclose(escritor);
    REescritor( );
    return x;
}

void REescritor( )
{
    FILE* lector;
    FILE* escritor;
    Emovie peli;
    int x=0;
    char titulo[30];

    lector=fopen("datosaux.bin","r+b");
    if(lector==NULL)
    {
        printf("\nno se pudo leer archivo\n");
    }
    escritor=fopen("datos.bin","w+b");
    if(escritor==NULL)
    {
        printf("\nno se pudo escribir archivo\n");
    }
        while(!feof(lector))
        {
            if((fread(&peli,sizeof(Emovie),1,lector))==1)
            {
                x=1;
                fwrite(&peli,sizeof(Emovie),1,escritor);
            }
        }
    fclose(lector);
    fclose(escritor);
    return x;
}



int ModificarPelicula(Emovie* strucDY)
{
    system("cls");
    FILE* lector;
    FILE* escritor;
    char titulo[30];
    Emovie peli;
    int x=0;
    char seguir='s';
    int opcion;


    printf("escriba el nombre para modificar :");
    fflush(stdin);
    gets(titulo);

    lector=fopen("datos.bin","r+b");
    if(lector==NULL)
    {
        printf("\nno se pudo leer archivo\n");
    }
    escritor=fopen("datosaux.bin","w+b");
    if(escritor==NULL)
    {
        printf("\nno se pudo escribir archivo\n");
    }

        while(!feof(lector))
        {
            if((fread(&peli,sizeof(Emovie),1,lector))==1)
            {
                if(stricmp(titulo,peli.titulo)!=0)
                {
                    fwrite(&peli,sizeof(Emovie),1,escritor);
                }
                if(stricmp(titulo,peli.titulo)==0)
                {
                    x=1;
                    do
                    {
                        system("cls");
                        printf("modificar a %s\n",peli.titulo);
                        printf("1-modificar nombre\n");
                        printf("2-modificar genero\n");
                        printf("3-modificar duracion\n");
                        printf("4-modificar descripcion\n");
                        printf("5-modificar puntaje\n");
                        printf("6-modificar nombre de foto.extencion\n");
                        printf("7-salir\n");

                        scanf("%d",&opcion);
                        switch(opcion)
                        {
                            case 1:
                                do
                                {
                                printf("escriba su nuevo nombre\n");
                                fflush(stdin);
                                gets(peli.titulo);
                                }while(strlen(strucDY->titulo)>20);
                            break;
                            case 2:
                                do
                                {
                                printf("escriba su nuevo genero\n");
                                fflush(stdin);
                                gets(peli.genero);
                                }while(strlen(strucDY->genero)>20);
                            break;
                            case 3:
                                 do
                                {
                                    printf("escriba su nueva duracion\n");
                                    scanf("%d",&peli.duracion);
                                 }while(strucDY->duracion>600||strucDY->duracion<0);
                            break;
                            case 4:
                                do
                                {
                                printf("escriba su nuevo descripcion\n");
                                fflush(stdin);
                                gets(peli.descripcion);
                                }while(strlen(strucDY->descripcion)>50);
                            break;
                            case 5:
                                  do
                                {
                                    printf("escriba su nuevo puntaje\n");
                                    scanf("%d",&peli.puntaje);
                                }while(strucDY->puntaje>100||strucDY->puntaje<0);
                            break;
                            case 6:
                                do
                                {
                                printf("escriba su nuevo nombre de foto con extencion\n");
                                fflush(stdin);
                                gets(peli.linkImagen);
                                }while(strlen(strucDY->linkImagen)>50);
                            break;
                            case 7:
                                seguir='n';
                            break;
                        }
                    }while(seguir=='s');
                    fwrite(&peli,sizeof(Emovie),1,escritor);
                }
            }
        }
    fclose(lector);
    fclose(escritor);
    REescritor( );
    system("cls");
    return x;
}




int generarPagina()
{
    FILE* lector;
    FILE* escritor;
    Emovie peli;
    int x=0;

    lector=fopen("datos.bin","rb");
    if(lector==NULL)
    {
        printf("\nno se pudo leer archivo\n");
    }
    escritor=fopen("index.html","wb");
    if(escritor==NULL)
    {
        printf("\nno se pudo escribir archivo\n");
    }

        while(!feof(lector))
        {
            if((fread(&peli,sizeof(Emovie),1,lector))==1)
            {
                    x=1;
                    fprintf(escritor,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' <IMG SRC=""carteleras/%s""\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d/100</li>\n<li>Duración:%d min</li>\n</ul>\n<p>%s.</p>\n</article>",peli.linkImagen,peli.titulo,peli.genero,peli.puntaje,peli.duracion,peli.descripcion);
            }
        }
    fclose(lector);
    fclose(escritor);
    return x;
}


