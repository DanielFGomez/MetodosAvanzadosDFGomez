#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float *reserva(int n_puntos);
void print_array(float * array, int n_puntos);
void copy(float *origen, float *destino, int n_puntos);
float fun(float x);


int main(int argc, char **argv){
	double x=atoi(argv[1]);
	return 0;
}

float fun(float x){
return x;
}



void copy(float *origen, float *destino, int n_puntos){
	int i;
	for(i=0;i<n_puntos;i++){
	destino[i] = origen[i];
	}
}

void print_array(float * array, int n_puntos){
	int i;
	for(i=0;i<n_puntos;i++){
		printf("%f\n", array[i]);
	}
}

float *reserva(int n_puntos){
	float *array;
	int i;
	if(!(array = malloc(n_puntos * sizeof(float)))){
	printf("Problema en reserva\n");
	exit(1);
	}
	for(i=0;i<n_puntos;i++){
	array[i] = 0.0;
}
return array;
}
