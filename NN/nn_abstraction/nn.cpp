#include "nn.h"


void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<Neuron> OutputLayer);
float NeuronWeightedSum(vector<Neuron>& layer, int connection_number);
float Sigmoid(float weighted_sum);

vector<vector<Neuron>> NeuralNetwork;

void FeedForward(vector<vector<Neuron>>& NeuralNetwork) {
	for (int i = 0; i < NeuralNetwork.size(); i++) {
		for (int j = 0; j < NeuralNetwork[i].size(); j++) {
			NeuralNetwork[i + 1][j].Value = Sigmoid(NeuronWeightedSum(NeuralNetwork[i], NeuralNetwork[i][j].Connections[i].Weight));
		}
	}
}

void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues) {
	//Calculating a cost function
	vector<Neuron> DeltaLayer; //Actually a cost function for every output neuron
	for (int i = 0; i < sizeof(OutputLayerExpectingValues); i++) {
		DeltaLayer[i] = Neuron(i, (NeuralNetwork.back()[i].Value - OutputLayerExpectingValues[i])* (NeuralNetwork.back()[i].Value - OutputLayerExpectingValues[i]));
	}
	//Calculating weights that have the most influence on each output values

	//Correcting weights
}

float NeuronWeightedSum(vector<Neuron>& layer, int connection_number) {
	float weighted_sum = 0;
	for (int i = 0; i < layer.size(); i++) {
		weighted_sum += layer[i].Value * layer[i].Connections[connection_number].Weight;
	}
	return weighted_sum;
}

float Sigmoid(float x) {
	float exp_val, return_val;
	exp_val = exp((double)-x);
	return_val = 1 / (1 + exp_val);
	return return_val;
}