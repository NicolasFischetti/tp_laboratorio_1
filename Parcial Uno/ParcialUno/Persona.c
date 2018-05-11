#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "Persona.h"

static int buscarLugarLibre(ePersona* array,int tam);
static int proximoId();


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

int persona_init(ePersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = 0;
        }
    }
    return retorno;
}


int buscarLugarLibre(ePersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_mostrar(ePersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 1)
            {
               printf("\n %s - %s - %s - %d",array[i].nombre,array[i].apellido,array[i].cuit, array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int persona_buscarPorId(ePersona* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == 1 && array[i].personaId == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int persona_alta(ePersona* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[50];
    int id;
    char cuit[50];
    int indice;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
                {
            if(!getValidString("Apellido?","Error","Overflow", apellido,50,2))
                {
            if(!getValidCuilt("Ingrese su numero de cuilt", "Error excedio el limte", cuit, 50, 2))
                {
                retorno = 0;
                strcpy(array[indice].nombre,nombre);
                strcpy(array[indice].apellido,apellido);
                 strcpy(array[indice].cuit,cuit);
                array[indice].personaId = id;
                array[indice].isEmpty = 1;
                printf("\nSu numero de id es: %d ", id);
                }
            }
        }
    }

}
    return retorno;
}

int persona_modificacion(ePersona* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    indice = persona_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Ingrese su nuevo nombre","Error excedio el limte","Overflow", nombre,50,2))
        {
            if(!getValidString("Ingrese su nuevo apellido","Error excedio el limte","Overflow", apellido,50,2))
                {
                if(!getValidCuilt("Ingrese su numero nuevo de cuilt", "Error excedio el limte", cuit, 50, 2))
                    {
                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            strcpy(array[indice].apellido,apellido);
                            strcpy(array[indice].cuit,cuit);
                            array[indice].personaId = id;
                            array[indice].isEmpty = 1;
                    }


                }
        }
    }
    return retorno;
}

int persona_baja(ePersona* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = persona_buscarPorId(array,limite,id);
    printf("\n Deseas eliminar el cliente s/n");
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = 0;
    }
    return retorno;
}















