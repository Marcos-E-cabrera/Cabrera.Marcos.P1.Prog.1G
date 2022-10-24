/*
 ============================================================================
 Name        : 1G.c
 Author      : Cabrera marcos - 1G
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

	/*1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto y
	 *   devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.

	  2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
	  	 un carácter como segundo y otro carácter  como tercero,  la misma deberá reemplazar cada ocurrencia del segundo parámetro
	  	 por el tercero y devolver la cantidad de veces que se reemplazo ese carácter en la cadena

	 3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo.
		Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main.

	 */

float aplicarAumento ( float precio );
int reemplazarCaracteres ( char cadena[], char a, char b);

typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;

int ordenarVacunasPorTipoYEfectividad(eVacuna vector[], int tam);

int main(void) {

	setbuf(stdout, NULL);

	eVacuna listaVacunas[TAM] =
	{ {1, "Sputnik", 'c', 25.0},
	  {2, "Sinophar", 'a', 36.0},
	  {3, "Pfizer", 'a', 27.0},
	};

	float precio = 50.00;
	float aumento;

	char cadena[] = {"rxxmplazarCaractxrxs"};
	int cont;

	aumento = aplicarAumento( precio );
	printf("Precio %.2f, precio con aumento %.2f", precio, aumento);

	cont = reemplazarCaracteres(cadena, 'x', 'e');
	printf("\ncantidad de cambio: %d\n\n", cont);


	ordenarVacunasPorTipoYEfectividad(listaVacunas, TAM);

    for(int i=0 ; i<TAM; i++)
    {
        printf ("%2d | %10s | %2c | %.2f \n", listaVacunas[i].id, listaVacunas[i].nombre, listaVacunas[i].tipo, listaVacunas[i].efectividad);
    }

	return EXIT_SUCCESS;
}

int ordenarVacunasPorTipoYEfectividad(eVacuna vector[], int tam)
{
    int retorno = -1;
    eVacuna swap;
    if(vector && tam)
    {
        for( int i=0; i<tam-1 ; i++)
        {
            for(int j= i+1; j<tam ; j++)
            {
                if( (vector[i].tipo > vector[j].tipo) ||
                	(vector[i].tipo == vector[j].tipo  && vector[i].efectividad > vector[j].efectividad ))
                {
                	swap= vector[j];
                    vector[j]= vector[i];
                    vector[i]=swap;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int reemplazarCaracteres ( char* cadena, char letraARemplazar, char letraRemplazante)
{
	int contador = 0;
	int len;

	if ( cadena != NULL )
	{
		len = strlen(cadena);

		for ( int i = 0; i < len ; i++ )
		{
			if ( cadena[i] == letraARemplazar )
			{
				cadena[i] = letraRemplazante;
				contador++;
			}
		}
	}
	return contador;
}

float aplicarAumento (float precio)
{
	float aux;
	float aumento = 1.05;

	aux = precio * aumento;

	return aux;
}
