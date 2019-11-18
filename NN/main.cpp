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
	//Filling layers with neurons
	for (int i = 0; i < InputLayerSize; i++) {
		NN[0][i] = Neuron(i, 0);
		NN[0][i].FillConnection(FirstHiddenLayerSize);
	}
	for (int i = 0; i < FirstHiddenLayerSize; i++) {
		NN[1][i] = Neuron(i, 0);
		NN[1][i].FillConnection(SecondHiddenLayerSize);
	}
	for (int i = 0; i < SecondHiddenLayerSize; i++) {
		NN[2][i] = Neuron(i, 0);
		NN[2][i].FillConnection(OutputLayerSize);
	}
	for (int i = 0; i < OutputLayerSize; i++) {
		NN[3][i] = Neuron(i, 0);
	}
	//LoadOutputFromFile("Data.mat");
	FeedForward(NN);
	BackPropagation(NN, OutputLayerExpectingValues);
	return 0;
}