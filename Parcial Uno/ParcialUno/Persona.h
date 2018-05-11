#ifndef ENTIDADUNO_H_INCLUDED
#define ENTIDADUNO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[50];
    int isEmpty;
    int personaId;
}ePersona;


#endif // ENTIDADUNO_H_INCLUDED


static int proximoId();
int persona_init(ePersona* array,int limite);
static int buscarLugarLibre(ePersona* array,int limite);
int persona_mostrar(ePersona* array,int limite);
int persona_buscarPorId(ePersona* array,int limite, int id);
int persona_alta(ePersona* array,int limite);
int persona_modificacion(ePersona* array,int limite, int id);
int persona_baja(ePersona* array,int limite, int id);
