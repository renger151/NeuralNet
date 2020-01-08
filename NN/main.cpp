#include "NN_ABSTRACTIONS/NN.h"

int main() {
	vector<Layer> NeuralNetwork = vector<Layer>();
	FillNeuralNetworkWithConnections(NeuralNetwork);
	for (int i = 0; i < 20000; i++) {
		ForwardPropagation(NeuralNetwork);
		BackPropagation(NeuralNetwork);
		GradientDescent(NeuralNetwork);
	}
}