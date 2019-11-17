#include "nn.h"


void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<Neuron> OutputLayer);
Neuron GetMaxActivatedNeuron(vector<vector<Neuron>>& NeuralNetwork);
float NeuronWeightedSum(vector<Neuron>& layer, int connection_number);
float Sigmoid(float weighted_sum);

vector<vector<Neuron>> NeuralNetwork;

void FeedForward(vector<vector<Neuron>>& NeuralNetwork) {
	for (int i = 0; i < NeuralNetwork.size(); i++) {
		for (int j = 0; j < NeuralNetwork[i].size(); j++) {
			NeuralNetwork[i + 1][j].value = Sigmoid(NeuronWeightedSum(NeuralNetwork[i], NeuralNetwork[i][j].Connections[i].weight));
		}
	}
}

void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues) {
	//Calculating the differnce between right answer and the neural network output
	vector<Neuron> DeltaLayer;
	for (int i = 0; i < sizeof(OutputLayerExpectingValues); i++) {
		DeltaLayer[i] = Neuron(i, (NeuralNetwork.back()[i].value - OutputLayerExpectingValues[i])* (NeuralNetwork.back()[i].value - OutputLayerExpectingValues[i]));
	}
	//Calculating a cost function

	//Correcting weights
}

float NeuronWeightedSum(vector<Neuron>& layer, int connection_number) {
	float weighted_sum = 0;
	for (int i = 0; i < layer.size(); i++) {
		weighted_sum += layer[i].value * layer[i].Connections[connection_number].weight;
	}
	return weighted_sum;
}

float Sigmoid(float x) {
	float exp_val, return_val;
	exp_val = exp((double)-x);
	return_val = 1 / (1 + exp_val);
	return return_val;
}