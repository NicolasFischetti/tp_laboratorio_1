#include "funciones.h"
#define limitePersonas 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"

int abonado_init(EPersona* lista)
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePersonas;i++)
        {
            lista[i].estado = 0;
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona lista[])
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePersonas;i++)
        {
            if(lista[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limitePersonas;i++)
        {
            if(lista[i].estado == 1 && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_alta(EPersona* lista)
{
    int retorno = -1;
    char nombre[50];
    char dni[20];
    int edad;
    int indice;

    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = -2;
        indice = obtenerEspacioLibre(lista);
        if(indice >= 0)
        {
            retorno = -3;
            if(!getValidString("\nIngrese su nombre\n","\nError ingrese su nombre nuevamente\n","\nNombre muy largo\n", nombre,50,2))
            {
                if(!getValidInt("\nIngrese su edad\n","\nError ingrese la edad nuevamente\n",&edad,0,100,2))
                {
                    if(!getValidDni("\nIngrese su dni\n","\nError ingrese su dni nuevamente\n", "error muy largo el dni",dni, 2))
                    {
                        retorno = 0;
                        strcpy(lista[indice].nombre,nombre);
                        strcpy(lista[indice].dni,dni);
                        lista[indice].edad = edad;
                        lista[indice].estado = 1;
                    }
                }
            }
        }
    }
    return retorno;
}

int persona_eliminar(EPersona* lista, int dni)
{

    int retorno = -1;
    int indice;
    indice = buscarPorDni(lista,dni);
    if(indice >= 0)
    {
        retorno = 0;
        lista[indice].estado = 0;
    }
    return retorno;
}

int persona_ordenar(EPersona* lista, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    EPersona auxiliarPersona;

    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limitePersonas-1;i++)
            {
                    if(lista[i].estado == 1 && lista[i+1].estado == 1 )
                    {
                        if((strcmp(lista[i].nombre,lista[i+1].nombre) > 0 && !orden) || (strcmp(lista[i].nombre,lista[i+1].nombre) < 0 && orden))
                        {
                            auxiliarPersona = lista[i];
                            lista[i] = lista[i+1];
                            lista[i+1] = auxiliarPersona;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    for(i = 0; i < limitePersonas; i++) {
        if(lista[i].estado == 1)
            printf("\n%s - %s - %d",lista[i].nombre,lista[i].dni,lista[i].edad);
    }
    printf("\n\n");

    return retorno;
}


int personas_mostrar(EPersona* lista)
{
    int retorno = -1;
    int i;
    if(limitePersonas > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limitePersonas;i++)
        {
            if(lista[i].estado == 1)
            {
               printf("\n %s - %d - %d - %s\n",lista[i].nombre,lista[i].edad,lista[i].estado,lista[i].dni);
            }
        }
    }
    return retorno;
}

int persona_grafico(EPersona* lista)
{
    int retorno = -1;
    int i;

    int less18 = 0;
    int middle = 0;
    int more35 = 0;

    for(i = 0; i < limitePersonas; i++) {
        if(lista[i].estado == 1) {
            if(lista[i].edad <= 18)
                less18 += 1;
            else if(lista[i].edad >= 19 && lista[i].edad <= 35)
                middle += 1;
            else
                more35 += 1;
        }
    }

    int totalLines = 0;
    if(less18 > middle) {
        if(less18 > more35) {
            totalLines = less18;
        } else {
            totalLines = more35;
        }
    } else {
        if(middle > more35) {
            totalLines = middle;
        } else {
            totalLines = more35;
        }
    }

    printf("\n\n");
    for(i = totalLines; i > 0; i--) {
        printf(i <= less18 ? "  *  " : "     ");
        printf(i <= middle ? "  *  " : "     ");
        printf(i <= more35 ? "  *  " : "     ");
        printf("\n");
    }
    printf("\n\n <18 19-35 >35 \n\n");

    return retorno;
}
