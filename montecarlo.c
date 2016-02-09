#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float *reserva(int n_puntos);
void print_array(float * array, int n_puntos);
void copy(float *origen, float *destino, int n_puntos);
float fun(float x);

int main(int argc, char **argv){
  
  int n_iterations=atoi(argv[1]);
  int n_puntos=1000;

  int i;
  int j;
  float *valores=reserva(n_iterations);
  float suma;


  for (j=0;j<n_iterations;j++){
  	suma=0;
 	 srand48(time(NULL)+1000*j);
  	for (i=0;i<1000;i++){
		suma=suma+fun(drand48());
		}
  	valores[j]=suma/1000.0;
	}
  print_array(valores, n_iterations);
  


  return 0;
}


float fun(float x){
	return pow(x,-1.0/3.0)+x/10;
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
