/*
 * main.c
 *
 *  Created on: 24 oct. 2019
 *      Author: antonio
 */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_BUFFER 10
#define NUM_ITEMS 20

typedef struct {

	char buffer [TAM_BUFFER];
	int indexP;
	int indexC;
	pthread_mutex_t mutex;
	sem_t sem_huecos;
	sem_t sem_items;


} TBuffer;

char generarItem(){
	char c;

	c = 65 + (rand()%26);
	printf("\nPROD: %c", c);
	return c;
}

void consumeItem(char c){
	printf("\nCon: %c", c);
}

void *productor(void *d){
	sem_t x = generarItem();
	TBuffer tb = c;
	sem_items = x;
	return NULL;
}

void *consumidor(void *c){
	generarItem();
	return NULL;
}

int main(){

	srand(time(0));
	TBuffer buf;
	pthread_t prod,cons;

	pthread_mutex_init(&buf.mutex, 0);
	buf.indexC = buf.indexP;
	sem_init(&buf.sem_huecos,0,TAM_BUFFER);
	sem_init(&buf.sem_items, 0, 0);

	pthread_create(&prod,0,productor, &buf);
	pthread_create(&cons,0,consumidor, &buf);

	pthread_join(prod,0);
	pthread_join(cons,0);

	sem_destroy(&buf.sem_huecos);
	sem_destroy(&buf.sem_items);
	pthread_mutex_destroy(&buf.mutex);


}


