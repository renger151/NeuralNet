#include "NN_ABSTRACTIONS/NN.h"

#define USE_MNIST_LOADER
#include <mnist.h>

void ArrayToVector(mnist_data* arr, vector<mnist_data>& vector);

unsigned int image_count;
int isopen;
vector<mnist_data> input;
vector<float> ExpectedValues;

int main() {
	mnist_data* data;
	if (isopen = mnist_load("assets/train-images-idx3-ubyte", "assets/train-labels-idx1-ubyte", &data, &image_count)) {
		printf("An error occured: %d\n", isopen);
	}
	else {
		printf("image count: %d\n", image_count);
		ArrayToVector(data, input);
		free(data);
	}
	vector<Layer> NeuralNetwork = vector<Layer>();
	FillNeuralNetworkWithConnections(NeuralNetwork);
	for (int i = 0; i < 10000; i++) {
		ForwardPropagation(NeuralNetwork, *input[i].data);
		for (int j = 0; j < 10; j++) {
			if (j = input[i].label) {
				ExpectedValues.push_back(1);
			}
			else {
				ExpectedValues.push_back(0);
			}
		}
		float nn_guess = GetResults(NeuralNetwork.back());
		printf("Actual number is: " + input[i].label, "%f");
		printf("Neural network guess: %f", nn_guess);
		BackPropagation(NeuralNetwork, ExpectedValues);
		GradientDescent(NeuralNetwork);
	}
	return 0;
}

void ArrayToVector(mnist_data* arr, vector<mnist_data>& vector) {
	for (int i = 0; i < sizeof(arr); i++) {
		vector.push_back(arr[i]);
	}
}