/*
 ============================================================================
 Name        : TP_1.c
 Author      : Ali, Pablo Sharif
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "utn_calculos.h"
#define BTC 40174.50

int main(void) {
	setbuf(stdout, NULL);

	int retornoGetInt;
	int retornoGetFloat;
	int opcionDelMenu;
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	int submenu;
	int flagKilometros = 0;
	int flagAerolineas = 0;
	int flagLatam = 0;
	int flagCalculo = 0;
	float resultadoDebitoLatam;
	float resultadoCreditoLatam;
	float resultadoBitcoinLatam;
	float resultadoPrecioUnitarioLatam;
	float resultadoDebitoAerolineas;
	float resultadoCreditoAerolineas;
	float resultadoBitcoinAerolineas;
	float resultadoPrecioUnitarioAerolineas;
	float resultadoDiferencia;

	int kilometrosForzado = 7090;
	int precioAerolineasForzado = 162965;
	int precioLatamForzado = 159339;
	float resultadoDebitoLatamForzado;
	float resultadoCreditoLatamForzado;
	float resultadoBitcoinLatamForzado;
	float resultadoPrecioUnitarioLatamForzado;
	float resultadoDebitoAerolineasForzado;
	float resultadoCreditoAerolineasForzado;
	float resultadoBitcoinAerolineasForzado;
	float resultadoPrecioUnitarioAerolineasForzado;
	float resultadoDiferenciaForzado;

	do{
		printf("1) Ingresar kilometros\n");
		printf("2) Ingresar precio de vuelos\n");
		printf("3) Calcular todos los costos\n");
		printf("4) Informar resultados\n");
		printf("5) Carga forzada de datos\n");
		printf("6) Salir\n");

		retornoGetInt = utn_getInt(&opcionDelMenu, "Ingrese la opcion que quiera\n", "la opcion es incorrecta\n", 6, 1, 1);
		if(retornoGetInt == 0){
			switch(opcionDelMenu){
			case 1:
				retornoGetFloat = utn_getFloat(&kilometros, "Ingrese los kilometros de su vuelo\n", "Debe ingresar 1 km como minimo\n", 999999999, 1, 2);
				if(retornoGetFloat == 0){
					flagKilometros = 1;
				}else{
					printf("Debe ingresar 1 km como minimo\n");
				}
				break;
			case 2:
				do{
					printf("1) Ingresar precio de vuelo por Aerolineas\n");
					printf("2) Ingresar precio de vuelo por Latam\n");
					printf("3) Volver al menu\n");

					retornoGetInt = utn_getInt(&submenu, "Ingrese la opcion que quiera\n", "la opcion es incorrecta\n", 3, 1, 1);
					if(retornoGetInt == 0){
						switch(submenu){
						case 1:
							retornoGetFloat = utn_getFloat(&precioAerolineas,"Ingrese precio de vuelo por Aerolineas\n", "Debe ingresar $1 como minimo\n", 999999999.9, 1, 2 );
							if(retornoGetFloat == 0)
							{
								flagAerolineas = 1;
							}else{
								printf("Debe ingresar $1 como minimo\n");
							}
							break;
						case 2:
							retornoGetFloat = utn_getFloat(&precioLatam,"Ingrese precio de vuelo por Latam\n", "Debe ingresar $1 como minimo\n", 999999999.9, 1, 2 );
							if(retornoGetFloat == 0)
							{
								flagLatam = 1;
							}else{
								printf("Debe ingresar $1 como minimo\n");
							}
							break;
						case 3:
							printf("Volviendo al menu\n");
							break;
						}
					}
				}while(submenu != 3 || flagAerolineas != 1 || flagLatam != 1);
				break;
			case 3:
				if(flagKilometros == 1 && flagAerolineas == 1 && flagLatam == 1)
				{
					flagCalculo = 1;

					resultadoDebitoLatam = utn_descuento(precioLatam, 10);
					resultadoDebitoAerolineas =utn_descuento(precioAerolineas, 10);

					resultadoCreditoLatam = utn_aumento(precioLatam, 25);
					resultadoCreditoAerolineas = utn_aumento(precioAerolineas, 25);

					resultadoBitcoinLatam = utn_division(precioLatam, BTC);
					resultadoBitcoinAerolineas = utn_division(precioAerolineas, BTC);

					resultadoPrecioUnitarioLatam = utn_division(precioLatam, kilometros);
					resultadoPrecioUnitarioAerolineas = utn_division(precioAerolineas, kilometros);

					resultadoDiferencia = utn_resta(precioLatam, precioAerolineas);
				}else{
					printf("Debe ingresar los kilometros y precios de vuelo para calcular los costos\n");
				}
				break;
			case 4:
				if(flagCalculo == 1){
					printf("\nKms ingresados: %.2f\n", kilometros);
					printf("\nPrecio Aerolineas: %.2f\na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin: %.8f\nd) Mostrar precio unitario: %.2f\n",
							precioAerolineas, resultadoDebitoAerolineas, resultadoCreditoAerolineas, resultadoBitcoinAerolineas, resultadoPrecioUnitarioAerolineas);
					printf("\nPrecio Latam: %.2f\na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin: %.8f\nd) Mostrar precio unitario: %.2f\n",
							precioLatam, resultadoDebitoLatam, resultadoCreditoLatam, resultadoBitcoinLatam, resultadoPrecioUnitarioLatam);
					printf("\nLa diferencia de precio es de: %.2f\n", resultadoDiferencia);
				}else{
					printf("Debe calcular los costos para poder imprimirlos\n");
				}
				break;
			case 5:
				resultadoDebitoLatamForzado = utn_descuento(precioLatamForzado, 10);
				resultadoDebitoAerolineasForzado = utn_descuento(precioAerolineasForzado, 10);

				resultadoCreditoLatamForzado =  utn_aumento(precioLatamForzado, 25);
				resultadoCreditoAerolineasForzado = utn_aumento(precioAerolineasForzado, 25);

				resultadoBitcoinLatamForzado = utn_division(precioLatamForzado, BTC);
				resultadoBitcoinAerolineasForzado =	utn_division(precioAerolineasForzado, BTC);

				resultadoPrecioUnitarioLatamForzado = utn_division(precioLatamForzado, kilometrosForzado);
				resultadoPrecioUnitarioAerolineasForzado = utn_division(precioAerolineasForzado, kilometrosForzado);

				resultadoDiferenciaForzado = utn_resta(precioLatamForzado, precioAerolineasForzado);

				printf("\nKms ingresados: %d\n", kilometrosForzado);
				printf("\nPrecio Aerolineas: %d\na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin: %.8f\nd) Mostrar precio unitario: %.2f\n",
						precioAerolineasForzado, resultadoDebitoAerolineasForzado, resultadoCreditoAerolineasForzado, resultadoBitcoinAerolineasForzado, resultadoPrecioUnitarioAerolineasForzado);
				printf("\nPrecio Latam: %d\na) Precio con tarjeta de debito: %.2f\nb) Precio con tarjeta de credito: %.2f\nc) Precio pagando con bitcoin: %.8f\nd) Mostrar precio unitario: %.2f\n",
						precioLatamForzado, resultadoDebitoLatamForzado, resultadoCreditoLatamForzado, resultadoBitcoinLatamForzado, resultadoPrecioUnitarioLatamForzado);
				printf("\nLa diferencia de precio es de: %.2f\n", resultadoDiferenciaForzado);
				break;
			case 6:
				printf("Hasta luego\n");
				break;
			}
		}
	}while(opcionDelMenu != 6);

	return 0;
}
