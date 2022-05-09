/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Ali, Pablo Sharif
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"

int main(void) {
	setbuf(stdout, NULL);
	float variable;


	utn_getFloat(&variable, "\nmensajito", "\nboludo", 10, 1, 2);
	printf("%f", variable);

	return 0;
}
