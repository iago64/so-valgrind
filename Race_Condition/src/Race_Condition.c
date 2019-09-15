/*
 ============================================================================
 Name        : Race_Condition.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int variable_muy_mal_compartida;
time_t tiempo;
int a;

void modificarVariable(){

	while(a < 20){
		int random = (rand() % 100);
		variable_muy_mal_compartida = random;
		printf("\nThread2: %d", variable_muy_mal_compartida);
		a++;
	}
}

int main(void) {

	srand((unsigned) time(&tiempo));
	pthread_t thread1;
	variable_muy_mal_compartida = 0;
	pthread_create(&thread1, NULL, (void *)modificarVariable, NULL);

	while (a < 20){
		variable_muy_mal_compartida = 30;
		printf("\nThread Main: %d", variable_muy_mal_compartida);
		a++;
	}

	return EXIT_SUCCESS;
}
