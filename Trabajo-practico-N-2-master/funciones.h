
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    char dni[20];

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/** \brief Inicializa el array de abonado
 * \param Lista el array se pasa por parametro
 * \return 0 en el caso que el lugar este libre.
 */
int abonado_init(EPersona* lista);

/** \brief Pide los datos para dar de alta a la persona, pide nombre, edad y dni
 * \param Lista el array se pasa por parametro
 * \return El nombre, edad y dni de la persona ingresada.
 */
int persona_alta(EPersona* lista);

/** \brief Da de baja a la persona
 * \param  lista el array que pasa por parametro
 * \param dni el dni a ser buscado en el array
 * \return 0  da de baja la posicion 1a que se encontraba la persona
 */
int persona_eliminar(EPersona* lista, int dni);

/** \brief Ordena a las personas por nombre
 * \param lista el array que pasa por el parametro
 * \param 0 para ordenar de menor a mayor, 1 para ordenar de mayor a menor
 * \return Orden de los nombres de las personas
 */
int persona_ordenar(EPersona* lista, int orden);

/** \brief Muestra los datos de las personas (nombre, edad, estado, dni)
 * \param lista el array que pasa por el parametro
 * \return nombre, edad, estado , dni de las personas
 */

int personas_mostrar(EPersona* lista);

/** \brief Muestra grafico de las personas menores a 18 años, entre 19-35 y los mayores a 35.
 * \param lista el arrray que pasa por el parametro
 * \return Cantidad de personas menores a 18 años, entre 19-35 y mayores a 35.
 */

int persona_grafico(EPersona* lista);


