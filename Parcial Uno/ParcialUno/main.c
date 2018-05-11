#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "Persona.h"
#include "Publicacion.h"
#define CLIENTES 100
#define PUBLICACIONES 1000



int main()
{
    ePublicacion publicacion[PUBLICACIONES];
    ePersona array[CLIENTES];
    int menu;
    int auxiliarId;

 persona_init(array, CLIENTES);
 publicacion_init(publicacion,PUBLICACIONES);

    do
    {
        getValidInt("\n\n1.Alta Persona\n2.Baja persona\n3.Modificar persona \n4.Publicar\n5.Pausar n10.\nSalir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                persona_alta(array,CLIENTES);
                break;
            case 2:
                getValidInt("Ingrese su id cliente","\nNumero valida\n",&auxiliarId,0,100,2);
                persona_modificacion(array,CLIENTES,auxiliarId);
                break;
            case 3:
                getValidInt("Ingrese su id cliente","\nNumero valida\n",&auxiliarId,0,100,2);
                publicacion_mostrar(publicacion,PUBLICACIONES);
                persona_baja(array,CLIENTES,auxiliarId);
                break;
            case 4:
                getValidInt("Ingrese el id del cliente","\nNumero valida\n",&auxiliarId,0,100,2);
                publicacion_alta(publicacion, PUBLICACIONES);
                break;
            case 5:
                getValidInt("Ingrese el id de la publicacion","\nNumero valida\n",&auxiliarId,0,100,2);
                persona_mostrar(array,CLIENTES);

                /*break;
            case 6:


                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;*/



        }

    }while(menu != 9);

    return 0;
}

