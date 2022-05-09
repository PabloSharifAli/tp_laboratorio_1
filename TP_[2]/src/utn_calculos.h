/*
 * utn_calculos.h
 *
 *  Created on: 16 abr. 2022
 *  Author: Ali, Pablo Sharif
 */

#ifndef UTN_CALCULOS_H_
#define UTN_CALCULOS_H_d

#include <stdio.h>


/// @brief Esta funcion realiza una suma entre dos numeros
///
/// @param numeroUno Toma el primer numero
/// @param numeroDos Toma el segundo numero
/// @return retorna el resultado de la cuenta
float utn_suma(float numeroUno, float numeroDos);

/// @brief Esta funcion realiza una resta entre dos numeros
///
/// @param numeroUno Toma el primer numero
/// @param numeroDos Toma el segundo numero
/// @return retorna el resultado de la cuenta
float utn_resta(float numeroUno, float numeroDos);

/// @brief Esta funcion realiza una multiplicacion entre dos numeros
///
/// @param numeroUno Toma el primer numero
/// @param numeroDos Toma el segundo numero
/// @return retorna el resultado de la cuenta
float utn_multiplicacion(float numeroUno, float numeroDos);

/// @brief Esta funcion realiza una division entre dos numeros
///
/// @param numeroUno Toma el primer numero
/// @param numeroDos Toma el segundo numero
/// @return retorna el resultado de la cuenta
float utn_division(float numeroUno, float numeroDos);

/// @brief Esta funcion aplica un descuento a un numero
///
/// @param numeroUno Toma el numero
/// @param porcentaje Toma el porcentaje a aplicar
/// @return retorna el resultado de la cuenta
float utn_descuento(float numeroUno, int porcentaje);

/// @brief
///
/// @param numeroUno Toma el numero
/// @param porcentaje Toma el porcetaje a aplicar
/// @return retorna el resultado de la cuenta
float utn_aumento(float numeroUno, int porcentaje);
#endif /* UTN_CALCULOS_H_ */
