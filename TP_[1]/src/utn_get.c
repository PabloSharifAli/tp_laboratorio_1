/*
 * Biblioteca.c
 *
 *  Created on: 7 abr. 2022
 *  Author: Ali, Pablo Sharif
 */
#include "utn_get.h"

int utn_getInt(int * pNnumeroEntero, char * mensaje, char * mensajeError, int maximo, int minimo, int maximoDeReintentos){ //agregamos la "p" al comienzo para recordar que es un puntero

	int auxNumeroEntero;
	int retorno;
	retorno = -1; // damos por sentado que está todo mal y va a fallar

	if(pNnumeroEntero != NULL && maximo >= minimo && maximoDeReintentos >= 0) // hacemos esto para asegurarnos de que la dirección sea válida y no nula, y después validamos los parámetros. Esto se hace siempre que tengamos uno o más punteros
	{
		do{
			printf("%s", mensaje);
			scanf("%d", &auxNumeroEntero);
			maximoDeReintentos --;

			if(auxNumeroEntero >= minimo && auxNumeroEntero <= maximo)
			{
				*pNnumeroEntero = auxNumeroEntero; // asignamos el valor guardado en la variable al contenido de la direccion de memoria
				retorno = 0; // como salimos del while, el retorno pasa a estar todo ok y lo ponemos en 0
				break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno; // retornamos el retorno
}

float utn_getFloat(float * pNnumeroFlotante, char * mensaje, char * mensajeError, float maximo, float minimo, int maximoDeReintentos){

	float auxNumeroFlotante;
	float retorno;
	retorno = -1;

	if(pNnumeroFlotante != NULL && maximo >= minimo && maximoDeReintentos >= 0)
	{
		do{
			printf("%s", mensaje);
			scanf("%f", &auxNumeroFlotante);
			maximoDeReintentos --;

			if(auxNumeroFlotante >= minimo && auxNumeroFlotante <= maximo)
			{
				*pNnumeroFlotante = auxNumeroFlotante;
				retorno = 0;
				break;
			}else{
				printf("%s", mensajeError);
			}

		}while(maximoDeReintentos > 0);
	}

	return retorno;
}
