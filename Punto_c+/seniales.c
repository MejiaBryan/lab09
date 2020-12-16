//seniales.c
//Hecho por: Bryan Mejia Manzanares
#define SIGTERM 15
#define SIGINT 2
#define SIGILL 4
#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
void controlador(int);
void imprime(int);
int main(){
	signal(SIGINT,controlador);
	signal(SIGILL,controlador);
	signal(SIGTERM,controlador);
	pid_t pid_hijo;
	printf("EL pid del programa principal es %d\n", (int)getpid());
	printf("EL pid del programa hijo es %d\n", (int)pid_hijo());	
	pid_hijo=fork();
	if(pid_hijo!=0){
		while(5)
			signal(SIGUSR2,imprime);
	}
	else
		printf("Todavia no hay proceso hijo");
}
void controlador(int nsenial){
	if(nsenial = 4){
		//signal(SIGILL,SIG_IGN);
		printf("SIGILL Proceso %d : SIGILL recibida",(int)getpid());	
	}
	if(nsenial = 2){
		//signal(SIGINT,SIG_IGN);
		printf("SIGINT Proceso %d : SIGINT recibida",(int)getpid());
	}
	if(nsenial = 15){
		//signal(SIGTERM,SIG_IGN);
		printf("SIGTERM Proceso %d : SIGTERM recibida",(int)getpid());
	}	
}
void imprime(int nsenial){
	printf("ls");	
	system("ls");
}
