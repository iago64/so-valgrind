/*
 ============================================================================
 Name        : SegmentFault.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char * texto = malloc(20);
	strcpy(texto, "Hola");
	char * otro_texto;
	otro_texto = 0;

	memcpy(otro_texto, texto, strlen(texto) + 1);
	return EXIT_SUCCESS;
}
