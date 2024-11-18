#include "modelo/Perceptron.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Perceptron crearPerceptron(int numeroEntradas, float factorAprendizaje) {

	Perceptron perceptron = {};

	perceptron.factorAprendizaje = factorAprendizaje;

	perceptron.numeroEntradas = numeroEntradas;

	srand(time(NULL));

	perceptron.umbral = rand() / (float)(RAND_MAX);

	perceptron.pesos = (float*)malloc(sizeof(float) * numeroEntradas);

	while(numeroEntradas--) {
	
		perceptron.pesos[numeroEntradas] = rand() / (float)(RAND_MAX);
	
	}

	return perceptron;

}

void imprimirInformacionPerceptron(Perceptron * perceptron) {

	puts("{");

	printf("Factor de aprendizaje: %f\n", perceptron->factorAprendizaje);

	printf("Umbral: %f\n", perceptron->umbral);

	printf("Número de entradas: %d\n", perceptron->numeroEntradas);

	int indice = 0;

	while(indice < perceptron->numeroEntradas) {
	
		printf("Peso %d: %f\n", indice, perceptron->pesos[indice]);

		indice++;
	
	}

	puts("}");

}

float computarSalida(Perceptron * perceptron, float * vectorEntrada) {

	float salida = 0.0f;

	int indice = perceptron->numeroEntradas;

	while(indice--) {
	
		salida += vectorEntrada[indice] * perceptron->pesos[indice];
	
	}

	salida -= perceptron->umbral;

	return salida >= 0.0f ? 1.0f : 0.0f;

}

void ajustarPesos(Perceptron * perceptron, float * vectorEntradas, float salidaEsperada, float salidaComputada) {

	float error = salidaEsperada - salidaComputada;

	float deltaUmbral = -(perceptron->factorAprendizaje * error);

	perceptron->umbral += deltaUmbral;

	int indice = perceptron->numeroEntradas;

	while(indice--) {
	
		float deltaPeso = perceptron->factorAprendizaje * error * vectorEntradas[indice];

		perceptron->pesos[indice] += deltaPeso;
	
	}

}

void entrenamiento(Perceptron * perceptron, float * matrizEntradas, float * vectorSalidas, int numeroRegistrosEntrada, int epoch) {

	while(epoch--) {
	
		int indice = numeroRegistrosEntrada;

		while(indice--) {
		
			float * vectorEntradas = matrizEntradas + (perceptron->numeroEntradas * indice);

			float salidaEsperada = vectorSalidas[indice];

			float salidaComputada = computarSalida(perceptron, vectorEntradas);

			if(salidaComputada != salidaEsperada) {
			
			
				ajustarPesos(perceptron, vectorEntradas, salidaEsperada, salidaComputada);
			
			}
		
		}
	
	}	

}

void ejecutarEntradasPrueba(Perceptron * perceptron, float * matrizEntradas, int numeroRegistrosPrueba) {

	int indice = 0;

	while(indice < numeroRegistrosPrueba) {

		float * vectorEntradas = matrizEntradas + (perceptron->numeroEntradas * indice);
	
		float salida = computarSalida(perceptron, vectorEntradas);

		indice++;

		int indiceEntrada = 0;

		while(indiceEntrada < perceptron->numeroEntradas) {
		
			printf("%f%s", vectorEntradas[indiceEntrada], (indiceEntrada == perceptron->numeroEntradas - 1) ? ": " : ",");

			indiceEntrada++;
		
		}

		printf("%f\n", salida);
	
	}

}
