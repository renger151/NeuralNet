#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

struct Connection {
	Connection(int _id, float _weight) {
		this->id = _id;
		this->weight = _weight;
	}
	int id = 0;
	float weight = 0;
};

struct Neuron {
	Neuron(int _id, float _value) {
		this->value = _value;
		printf("Neuron Created!");
	}
	int id = 0;
	float value = 0;
	vector<Connection> Connections;
};

vector<vector<Neuron>> NeuralNetwork;

void CreateInputLayer(vector<vector<Neuron>> &NeuralNetwork, float*InputData, int InputDataAmmount);
void CreateHiddenLayer(vector<vector<Neuron>>& NeuralNetwork, vector<Neuron> &PreviousLayer, int HiddenLayerSize);
void CreateOutputLayer(vector<vector<Neuron>> &NeuralNetwork, float*OutputLayerData, int OutputLayerDataSize);
void FeedForward(vector<vector<Neuron>> &NeuralNetwork);
void BackPropagation(vector<vector<Neuron>> &NeuralNetwork);
float GetMaxActivatedValue(vector<vector<Neuron>> &NeuralNetwork);
int GetMaxActivatedNeuronId(vector<vector<Neuron>>& NeuralNetwork);
float NeuronWeightedSum(vector<Neuron> &layer, int connection_number);
float Sigmoid(float weighted_sum);

int main() {
	return 0;
}

void CreateInputLayer(vector<vector<Neuron>> &NeuralNetwork, float* InputData, int InputDataAmmount) {
	NeuralNetwork.push_back(vector<Neuron>());
	for (int i = 0; i < InputDataAmmount; i ++) {
		NeuralNetwork.front().push_back(Neuron(i, InputData[i]));
	}
}

void CreateHiddenLayer(vector<vector<Neuron>> &NeuralNetwork, vector<Neuron> &PreviousLayer, int HiddenLayerSize) {
	NeuralNetwork.push_back(vector<Neuron>());
	for (int i = 0; i < HiddenLayerSize; i++) {
		float ActivationValue = Sigmoid(NeuronWeightedSum(PreviousLayer, i));
		NeuralNetwork.back().push_back(Neuron(i, ActivationValue));
		for (int j = 0; j < HiddenLayerSize; j++) {
			NeuralNetwork.back();
		}
	}
}

void CreateOutputLayer(vector<vector<Neuron>> &NeuralNetwork, float*OutputLayerData, int OutputLayerDataSize) {
	NeuralNetwork.push_back(vector<Neuron>());
	for (int i = 0; i < OutputLayerDataSize; i++) {
		NeuralNetwork.back().push_back(Neuron(i, OutputLayerData[i]));
	}
}

void FeedForward(vector<vector<Neuron>> &NeuralNetwork) {
	for (int i = 0; i < NeuralNetwork.size(); i++) {
		for (int j = 0; j < NeuralNetwork[i].size(); j++) {
			NeuralNetwork[i + 1][j].value = Sigmoid(NeuronWeightedSum(NeuralNetwork[i], NeuralNetwork[i][j].Connections[i].weight));
		}
	}
}

void BackPropagation(vector<vector<Neuron>> &NeuralNetwork, float *OutputLayerData) {
	int ActivatedNeuronId = GetMaxActivatedNeuronId(NeuralNetwork);

}

float GetMaxActivatedValue(vector<vector<Neuron>>& NeuralNetwork) {
	float MaxActivation = NeuralNetwork.back().front().value;
	for (int i = 1; i < NeuralNetwork.back().size(); i++) {
		if (NeuralNetwork.back()[i].value > MaxActivation) {
			MaxActivation = NeuralNetwork.back()[i].value;
		}
	}
	return MaxActivation;
}

int GetMaxActivatedNeuron(vector<vector<Neuron>>& NeuralNetwork) {
	int MaxActivatedNeuronId = 0;
	for (int i = 0; i < NeuralNetwork.back().size(); i++) {
		if (NeuralNetwork.back()[i].value > MaxActivatedNeuronId) {
			MaxActivatedNeuronId = NeuralNetwork.back()[i].id;
		}
	}
	return MaxActivatedNeuronId;
}

float NeuronWeightedSum(vector<Neuron> &layer, int connection_number) {
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