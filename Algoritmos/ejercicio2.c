#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
int cont=0;
void contador();
void cow();
pid_t pid1;
char* ar[]={"cowsay","hola",NULL};
int main(){
signal(SIGTERM,contador);
signal(SIGUSR2,cow);
printf("Señales SIGTERM y SIGUSR2.\n");
while(1);
signal(SIGTERM,SIG_IGN);
exit(0);
}
void contador(){
signal(SIGTERM,SIG_IGN);
cont++;
printf("Has usado SIGTERM %d veces\n",cont);
signal(SIGTERM,contador);
}
void cow(){
signal(SIGUSR2,SIG_IGN);
if((pid1=fork())==0)
execvp("cowsay",ar);
signal(SIGUSR2,cow);
}
