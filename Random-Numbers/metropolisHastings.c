#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float *reserva(int n_puntos);
void print_array(float * array, int n_puntos);
void copy(float *origen, float *destino, int n_puntos);
float fun(float x);


int main(int argc, char **argv){
	
	srand48(time(NULL));
	int n_iterations=10000;
	int i;	
	float a,r,xNew;
	
	float *x=reserva(n_iterations+1);
	x[0]=0;
	
	for(i=0;i<n_iterations;i++){
		xNew=x[i]+drand48()-0.5;
		r=fun(xNew)/fun(x[i]);
		if(r > 1){r=1;}
		a=drand48();

		if(r>a){
			x[i+1]=xNew;
		}
		else{
			x[i+1]=x[i];
		}
	}

	print_array(x,n_iterations+1);

	return 0;
}

float fun(float x){
	return ( 1 / (sqrt(2*3.14156) ) ) * exp( -0.5 * x*x );
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
