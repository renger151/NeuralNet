#pragma once
#include <stdio.h>
#include <vector>
#include <math.h>


using namespace std;
//This  structure discribes a connection between 2 neurons
struct Connection {
	Connection(int _ConnectionID, float _Weight, int _Neuron1ID, int _Neuron2ID) {
		this->ConnectionID = _ConnectionID;
		this->Weight = _Weight;
		this->Neuron1ID = _Neuron1ID;
		this->Neuron2ID = _Neuron2ID;
	}
	int ConnectionID = 0;
	int Neuron1ID;
	int Neuron2ID;
	float Weight = 0;
};

struct Neuron {
	int NeuronID = 0;
	float Activation = 0;
	float bias = 0;
	Neuron(int _NeuronID, float _Activation, float _bias) {
		this->NeuronID = _NeuronID;
		this->Activation = _Activation;
		this->bias = _bias;
		printf("Neuron Created!");
	}
	void FillConnection(int connection_number) {
		for (int i = 0; i < connection_number; i++) {
			this->Connections[i] = Connection(i, 1/rand(), this->NeuronID, i);
		}
	}
	vector<Connection> Connections;
};

extern void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
extern void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues);
extern float Sigmoid(float weighted_sum);
