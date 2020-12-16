//fork.c
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	pid_t pid_hijo;
	pid_t pid_nieto;
	printf("EL pid del programa principal es %d\n", (int)getpid());
	
	pid_hijo=fork();
	pid_nieto=fork();
	if(pid_hijo!=0){
		printf("ESte es el proceso padre con ID %d\n", (int)getpid());
		printf("El ID del hijo es %d\n", (int) pid_hijo);
		if(pid_nieto!=0){
		printf("El ID del nieto es %d\n", (int) pid_nieto);
		system("Script01.sh");	
}
	}
	else
		printf("Este es el proceso hijo, con ID %d\n", (int)getpid());
}
