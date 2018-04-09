#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "float.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroA;
    float numeroB;
    float resultado;

    while(seguir=='s')
    {

        printf("1- Ingresar 1er operando A=%.2f\n", numeroA);
        printf("2- Ingresar 2do operando B=%.2f\n", numeroB);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese el numero A\n");
                scanf("%f", &numeroA);
                break;
            case 2:
                printf("Ingrese el numero B\n");
                scanf("%f", &numeroB);
                break;
            case 3:
                if (sumar(numeroA, numeroB, &resultado)==0)
                {
                    printf("La suma es %.2f\n", resultado );
                }
                else
                {
                    printf("Error ingrese nuevamente su suma\n");
                }
                break;
            case 4:
                if (restar( numeroA,  numeroB, &resultado)==0)
                {
                    printf("La resta es %.2f\n", resultado );
                }
                else
                {
                    printf("Error ingrese nuevamente la resta\n");
                }
                break;
            case 5:
                if (dividir( numeroA,  numeroB, &resultado)==0)
                {
                    printf("La division es %.2f: \n", resultado);
                }
                else
                {
                    printf("Error ingrese nuevamente la division\n");
                }
                break;
            case 6:
                if (multiplicar( numeroA,  numeroB, &resultado)==0)
                {
                    printf("La multiplicacion es: %.2f\n", resultado);
                }
                else
                {
                    printf("Error ingrese nuevamente la multiplicacion\n");
                }
                break;
            case 7:
                if (factoriar(numeroA, &resultado)==0)
                {
                    printf("El numero factoriado es %.2f: \n", resultado);
                }
                else
                {
                    printf("Error ingrese nuevamente el factorial\n");
                }
                break;
            case 8:
                printf("la suma total es: %.2f\n",sumar );
                printf("La resta total es: %.2f\n", restar);
                printf("La división total es: %.2f\n", dividir);
                printf("La multiplicación total es: %.2f\n",multiplicar);
                printf("El factorial del numero A es: %.2f\n", factoriar);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

