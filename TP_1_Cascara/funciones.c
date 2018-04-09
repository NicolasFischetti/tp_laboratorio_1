#define MAX_FLOAT 3.4E+38
#define MIN_FLOAT 3.4E-38
#include "float.h"

/** \brief Suma de dos numeros flotantes
 * \param x float Primer numero flotante
 * \param y float Segundo numero flotante
 * \param resultado float* Resultado pasado por referencia
 * \return float si esta todo bien 0, si es - overflow -1 o si es + overflow -1;
 */
float sumar(float x, float y, float *resultado)
{
    int retorno = -1;
    double numeroAuxiliar;
    numeroAuxiliar= x+y;
    if (numeroAuxiliar < FLT_MAX && numeroAuxiliar > FLT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }
    return retorno;
}
/** \brief Resta de flotantes
 * \param x float El primer numero a restar
 * \param y float El segundo numero a restar
 * \param resultado float* Resultado pasado pasado por referencia
 * \return float si esta todo bien 0, si es - overflow -1 o si es + overflow -1;
 */
float restar(float x, float y, float *resultado)
{
    int retorno = -1;
    long numeroAuxiliar;
    numeroAuxiliar= x-y;
    if (numeroAuxiliar < FLT_MAX || numeroAuxiliar > FLT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }
    else
    {
        retorno= -1;
    }
    return retorno;
}
/** \brief División de flotantes
 * \param x float Primer numero a dividir
 * \param y float Segundo numero a dividir
 * \param resultado float* devuelve el resultado pasado por referencia
 * \return float  si esta todo bien 0, si y es = 0 devuelve -1,
 */
float dividir(float x, float y, float *resultado)
{
    int retorno = -1;
    long numeroAuxiliar;
    numeroAuxiliar= x/y;
    if (y == 0)
    {
        retorno = -1;
    }
    else
    {
        *resultado= numeroAuxiliar;
        retorno = 0;
    }
    return retorno;
}
/** \brief Multiplicación de flotantes
 * \param x float Primer numero a multiplicar
 * \param y float Segundo numero a multiplicar
 * \param resultado float* devuelve el resultado pasado por referencia
 * \return float si esta todo bien 0, si es - overflow -1 o si es + overflow -1;
 */
float multiplicar(float x, float y, float *resultado)
{
    int retorno= -1;
    long numeroAuxiliar;
    numeroAuxiliar= x*y;
    if (numeroAuxiliar < FLT_MAX || numeroAuxiliar > FLT_MIN)
    {
        retorno = 0;
        *resultado= numeroAuxiliar;
    }

    return retorno;
}
/** \brief Factorizacion de una numero
 * \param x float Numero a factorizar
 * \param resultado float* devuelve el resultado pasado por referencia
 * \return float si todo esta bien 0, si el numero < 0 devuelve -1
 */
float factoriar(float x, float* resultado)
{
    int retorno = -1;
    long numeroAuxiliar = 1;
    if (x < 0 || x > FLT_MAX || x < FLT_MIN)
    {
        retorno= -1;
    }
    else
    {
        for (int i = 1; i <= x; i++)
        {
            numeroAuxiliar= numeroAuxiliar * i;
        }
        *resultado= numeroAuxiliar;
        retorno= 0;
    }
    return retorno;
}

