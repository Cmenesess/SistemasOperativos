#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1
#include <sys/resource.h>
int main ( int argc, char *argv[] ){
  double duracion=0;
  double promedio=0;
  int fd[2];
  double numero;
  struct timeval t1,t2,tresult;
  for(int i=0;i<atoi(argv[1]);i++){
  	pipe(fd);
  	gettimeofday(&t1,NULL);
   	pid_t c=fork();
    if(c == 0){
  	   gettimeofday(&t2,NULL);
       timersub(&t2, &t1, &tresult);
  	   numero =(1.0 * tresult.tv_usec) / 1000;
  	   close(fd[READ_END]);
  	   write(fd[WRITE_END], &numero, sizeof(numero)); 
  	   exit(0);
    }
  	wait(NULL);
  	close(fd[WRITE_END]);
  	read(fd[READ_END],&numero,sizeof(numero));
  	duracion+=numero;
    }
  wait(NULL);
  promedio= (double)duracion/atoi(argv[1]);
  printf("El tiempo promedio de creacion de %d procesos es de %f \n",atoi(argv[1]),promedio);
} 
