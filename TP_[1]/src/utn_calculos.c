/*
 * utn_calculos.c
 *
 *  Created on: 16 abr. 2022
 *  Author: Ali, Pablo Sharif
 */

#include "utn_calculos.h"


float utn_suma(float numeroUno, float numeroDos){
	float resultado;

	resultado = numeroUno + numeroDos;

	return resultado;
}

float utn_resta(float numeroUno, float numeroDos){
	float resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

float utn_multiplicacion(float numeroUno, float numeroDos){
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

float utn_division(float numeroUno, float numeroDos){
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}

float utn_descuento(float numeroUno, int porcentaje){
	int descuento;
	float resusltado;

	descuento = (float) numeroUno * porcentaje / 100;
	resusltado = numeroUno - descuento;

	return resusltado;
}

float utn_aumento(float numeroUno, int porcentaje){
	int aumento;
	float resusltado;

	aumento = (float) numeroUno * porcentaje / 100;
	resusltado = numeroUno + aumento;

	return resusltado;
}
