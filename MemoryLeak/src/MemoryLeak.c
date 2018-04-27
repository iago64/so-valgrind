/*
 ============================================================================
 Name        : MemoryLeak.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 0;
	while (a < 10) {
		void * ptr = malloc(100);
		a++;
	}
	return EXIT_SUCCESS;
}
