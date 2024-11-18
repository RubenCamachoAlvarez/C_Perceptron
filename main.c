#include "modelo/Perceptron.h"

int main(void) {

	Perceptron perceptron = crearPerceptron(2, 0.2f);

	imprimirInformacionPerceptron(&perceptron);

	float matriz[4][2] = {
	
		{0,0},
		{0,1},
		{1,0},
		{1,1}
	
	};

	float vectorSalidas[4] = {1,0,0,0};

	entrenamiento(&perceptron, (float*)matriz, vectorSalidas, 4,100);

	imprimirInformacionPerceptron(&perceptron);

	ejecutarEntradasPrueba(&perceptron, (float*)matriz, 4);

	return 0;

}
