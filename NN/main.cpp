#include <file/file.h>
#include <nn_abstraction/nn.h>

int main() {
	//Generating 4 layer(1 input, 2 hidden and 1 ouput layer)
	vector<vector<Neuron>> NN;
	vector<float> OutputLayerExpectingValues;
	int InputLayerSize = 784;
	int FirstHiddenLayerSize = 16;
	int SecondHiddenLayerSize = 16;
	int OutputLayerSize = 10;

	for (int i = 0; i < InputLayerSize; i++) {
		NN[0][i] = Neuron(i, 0);
	}
	for (int i = 0; i < FirstHiddenLayerSize; i++) {
		NN[1][i] = Neuron(i, 0);
	}
	for (int i = 0; i < SecondHiddenLayerSize; i++) {
		NN[2][i] = Neuron(i, 0);
	}
	for (int i = 0; i < OutputLayerSize; i++) {
		NN[3][i] = Neuron(i, 0);
	}
	LoadOutputFromFile("Data.mat", )
	FeedForward(NN);
	BackPropagation(NN, );
	return 0;
}