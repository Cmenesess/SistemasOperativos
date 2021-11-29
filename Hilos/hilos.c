#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <semaphore.h>
#include <pthread.h>

double global_time = 0;
sem_t mutex;

void *thread(void *tiempo){
	struct timeval t2;
	gettimeofday(&t2, NULL);
	struct timeval t1 = *(struct timeval *) tiempo;
	struct timeval tresult;
	timersub(&t2, &t1, &tresult);
	double numero =(tresult.tv_sec) * 1000 + (1.0*tresult.tv_usec) / 1000;
	printf("%f \n",numero);
	sem_wait(&mutex);
	global_time += numero;
	sem_post(&mutex);
	return NULL;
}

int main(int argc, char **argv){
	sem_init(&mutex, 0, 1);
	pthread_t *id;
	int cant_hilos=atoi(argv[1]);
	id=malloc(sizeof(pthread_t)*cant_hilos);
	if (cant_hilos <= 0)
	{
		fprintf(stderr, "No se ha especificado el numero de hilos.\n");
	}

	for (int i = 0; i < cant_hilos; i++)
	{
		//pthread_t id;
		struct timeval t1;
		gettimeofday(&t1, NULL);
		pthread_create(&id[i], NULL, thread, &t1);
		//pthread_join(id,NULL);
	}
	for (int i = 0; i < cant_hilos; i++){
       		pthread_join(id[i], NULL);
	}
	printf("Promedio de: %f [ms]\n", global_time / cant_hilos);
	sem_destroy(&mutex);
	return 0;

}