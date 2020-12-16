#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t conA = PTHREAD_COND_INITIALIZER;;
pthread_cond_t conB = PTHREAD_COND_INITIALIZER;;
pthread_cond_t conC = PTHREAD_COND_INITIALIZER;;

int ini = 20;
int fin = 15;
int i = 0;
void *funcion01(void *arg) { 
	if(ini > fin){
		i++;
	}
	for (i; i<20; i++) {
        	printf("+");
        	fflush(stdout);
    	}
	ini = ini -1;
	printf("\n");
    	pthread_cond_signal(&conA);
    	return NULL;
}
void *funcion02(void *arg) {
	if(ini > fin){
		i++;
	}
    	for (i; i<20; i++) {
        	printf("o");
        	fflush(stdout);
    	}
	ini = ini -1;
	printf("\n");
	pthread_cond_wait(&conB, &mutex2);
  	return NULL;
}
int main() {
	
    pthread_t mihilo01, mihilo02;

while(1){
    if (pthread_create(&mihilo01,NULL,funcion01,NULL)) {
        printf("Error creando el hilo.");
        abort();
    }
    if (pthread_create(&mihilo02,NULL,funcion02,NULL)) {
        printf("Error creando el hilo.");
        abort();
    }


    pthread_cond_wait(&conA, &mutex);
	if(ini > fin){
	i++;
	}
    for (i; i<20; i++) {
        printf("x");
        fflush(stdout);
    }
	ini = ini -1;
	printf("\n");

    pthread_cond_signal(&conB);
    pthread_join(mihilo01, NULL);
    pthread_join(mihilo02, NULL);
}
    exit(0);
}
