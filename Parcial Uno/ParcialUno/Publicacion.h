#ifndef ENTIDADDOS_H_INCLUDED
#define ENTIDADDOS_H_INCLUDED
#include "Persona.h"
typedef struct
{
    int numeroRubro;
    char textoAviso[64];
    int isEmpty;
    int personaId;
    int publicacionId;

}ePublicacion;

int publicacion_init(ePublicacion* publicacion,int limite);
static int proximoAviso();
static int buscarLugarLibrePubli(ePublicacion* publicacion,int limite);
int publicacion_mostrar(ePublicacion* publicacion,int limite);
int publicacion_buscarPorId(ePublicacion* publicacion,int limite, int id);
int publicacion_alta(ePublicacion* publicacion,int limite);
int publicacion_pausar(ePublicacion* publicacion,int limite, int id);
int publicacion_baja(ePublicacion* publicacion,int limite, int id);



#endif // ENTIDADDOS_H_INCLUDED
