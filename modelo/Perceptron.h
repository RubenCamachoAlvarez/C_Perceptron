#ifndef PERCEPTRON_H

#define PERCEPTRON_H

typedef struct {

	float * pesos;

	float umbral;

	float factorAprendizaje;

	int numeroEntradas;

} Perceptron;

Perceptron crearPerceptron(int numeroEntradas, float factorAprendizaje);

void imprimirInformacionPerceptron(Perceptron * perceptron);

float computarSalida(Perceptron * perceptron, float * vectorEntradas);

void entrenamiento(Perceptron * perceptron, float * matrizEntradas, float * vectorSalidas, int numeroRegistrosEntrada, int epoch);

void ejecutarEntradasPrueba(Perceptron * perceptron, float * matrizEntradas, int numeroRegistrosEntrada);

#endif
