#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define limitePersonas 20
#include "utn.h"

int main()
{
    EPersona lista[limitePersonas];
    char seguir='s';
    int opcion=0;
    int abonado_init(EPersona* lista);
    char auxiliarDni[20];

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Mostrar lista de personas\n");
        printf("6- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                persona_alta(lista);
                break;
            case 2:
                getValidDni("\nIngrese el dni de la persona que desea eliminar", "\n Error en el ingreso del dni\n", "error al ingresar el dni", auxiliarDni, 2);
                persona_eliminar(lista, auxiliarDni);
                break;
            case 3:
                persona_ordenar(lista, 0);
                break;
            case 4:
                persona_grafico(lista);
                break;
            case 5:
                personas_mostrar(lista);
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }


}

