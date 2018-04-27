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
#include <unistd.h>
#include <time.h>

int variableManoseada;
time_t tiempo;
int a;
pthread_mutex_t lock;
pthread_mutex_t lock2;

void tocarVariable(){

	int variable = 0;
	printf("Comienzo a ejecutar en el nuevo thread\n");
	while(1){

		pthread_mutex_lock(&lock2);

		printf("Dentro de los locks del Thread - Numero: %d\n", variable);
		sleep(10);

		pthread_mutex_unlock(&lock);
		variable ++;
	}


}

int main(void) {

	srand((unsigned) time(&tiempo));
	pthread_t thread1;
	variableManoseada = 0;

	printf("Lanzo el nuevo thread\n");
	pthread_create(&thread1, NULL, (void *)tocarVariable, NULL);
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_init(&lock2, NULL);
	//Solo lo inicializo tomado para que no inicie el ciclo
	pthread_mutex_lock(&lock2);

	int var = 0;

	while(1){

		pthread_mutex_lock(&lock);

		printf("Dentro de los locks del main - Numero: %d\n", var);
		sleep(10);

		pthread_mutex_unlock(&lock2);

		var++;
	}

	return EXIT_SUCCESS;
}
