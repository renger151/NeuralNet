#include "nn.h"

void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<Neuron> OutputLayer);
float Sigmoid(float weighted_sum);

vector<vector<Neuron>> NeuralNetwork;

void FeedForward(vector<vector<Neuron>>& NeuralNetwork) {
	float weighted_sum = 0;
	//Selecting layer
	for (int i = 0; i < NeuralNetwork.size(); i++) {
	//Selecting neuron in the next layer to pass there the squashed weighted sum
		for (int j = 0; j < NeuralNetwork[i + 1].size(); j++) {
			//Calculating weighted sum for the chosen layer
			for (int z = 0; z < NeuralNetwork[i].size(); z++) {
				weighted_sum += NeuralNetwork[i][z].Activation * NeuralNetwork[i][z].Connections[z].Weight;
			}
			//Adding bias to this weighted sum
			weighted_sum += NeuralNetwork[i + 1][j].bias;
			//Passing all of this througth the sigmoid function and applying to the target neuron
			NeuralNetwork[i + 1][j].Activation = Sigmoid(weighted_sum);
		}
	}
}

void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues) {
	//Calculating a cost function
	float CostFunction = 0;
	for (int i = 0; i < sizeof(OutputLayerExpectingValues); i++) {
		CostFunction += pow(NeuralNetwork.back()[i].Activation - OutputLayerExpectingValues[i], 2);
	}
	//Calculating weights and biases
	for (int i = 0; i < NeuralNetwork.back().size(); i++) {
		for (int i = 0; i < NeuralNetwork.back()[i].Connections.size(); i++) {

		}
		for (int i = 0; i < NeuralNetwork.back().size(); i++) {

		}
	}
	//Correcting weights
}

float Sigmoid(float x) {
	return 1 / (1 + exp((double)-x));
}