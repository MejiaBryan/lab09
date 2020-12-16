#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
void manejador(int);
main(){
	if(signal (SIGINT, manejador) == SIG_ERR);
		perror("No se puede cambiar signal");
	while(1){
		printf("Voy a para de ejecutarme...\n");
		pause();
	}
}

void manejador(int nsenial) {
	printf("Pues no me salgo\n");
	printf("Intentalo otra vez\n");
	signal (SIGINT, SIG_DFL);
}
