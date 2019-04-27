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
	char * texto;
	char * otro_texto;
	texto = 0;

	memcpy(texto, otro_texto, 10);
	return EXIT_SUCCESS;
}
