#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "Persona.h"
#include "Publicacion.h"

static int buscarLugarLibrePubli(ePublicacion* publicacion,int tam);
static int proximoAviso();


static int proximoAviso()
{
    static int ultimoAviso = -1;
    ultimoAviso++;
    return ultimoAviso;
}

int publicacion_init(ePublicacion* publicacion,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicacion != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            publicacion[i].isEmpty = 0;
        }
    }
    return retorno;
}


int buscarLugarLibrePubli(ePublicacion* publicacion,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicacion != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(publicacion[i].isEmpty == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_mostrar(ePublicacion* publicacion,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicacion != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(publicacion[i].isEmpty == 1)
            {
               printf("\n %d - %d - %s",publicacion[i].publicacionId,publicacion[i].numeroRubro,publicacion[i].textoAviso);
            }
        }
    }
    return retorno;
}

int publicacion_buscarPorId(ePublicacion* publicacion,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicacion != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(publicacion[i].isEmpty == 1 && publicacion[i].personaId == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_alta(ePublicacion* publicacion,int limite)
{
    int retorno = -1;
    char textoAviso[64];
    int numeroRubro;
    int aviso;
    int id;
    int indice;

    if(limite > 0 && publicacion != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibrePubli(publicacion,limite);
        if(indice >= 0)
        {
            retorno = -3;
            aviso = proximoAviso();
            if(!getValidInt("Ingrese su ID de cliente?","Error", &id,0,10000, 2))
                {
            if(!getValidInt("Ingrese su numero de rubro","Error", &numeroRubro,0,10000, 2))
                {
            if(!getValidString("Ingrese el texto de aviso","Error", "Error excedio el limite", textoAviso, 64, 2))
                {
                retorno = 0;

                publicacion[indice].personaId = id;
                 publicacion[indice].numeroRubro = numeroRubro;
                 strcpy(publicacion[indice].textoAviso,textoAviso);
                publicacion[indice].isEmpty = 1;
                printf("\nSu numero de aviso es: %d ", aviso);
                }
            }
        }
    }

}
    return retorno;
}

int publicacion_pausar(ePublicacion* publicacion,int limite, int id)
{
    int retorno = -1;
    int indice;
    int estado;
    indice = publicacion_buscarPorId(publicacion,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidInt("Ingrese su nuevo estado","Error excedio el limte", &estado, 0, 100, 2))
        {

                            retorno = 0;
                            publicacion[indice].isEmpty = estado;
                            publicacion[indice].personaId = id;
                            publicacion[indice].isEmpty = 1;
                    }


        }
        return retorno;
    }


int publicacion_baja(ePublicacion* publicacion,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = publicacion_buscarPorId(publicacion,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        publicacion[indice].isEmpty = 0;
    }
    return retorno;
}












