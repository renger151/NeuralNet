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
	Neuron(int _NeuronID, float _Value) {
		this->NeuronID = _NeuronID;
		this->Value = _Value;
		printf("Neuron Created!");
	}
	void FillConnection(int connection_number) {
		for (int i = 0; i < connection_number; i++) {
			this->Connections[i] = Connection(i, 1/rand(), this->NeuronID, i);
		}
	}
	int NeuronID = 0;
	float Value = 0;
	vector<Connection> Connections;
};

extern void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
extern void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues);
extern float NeuronWeightedSum(vector<Neuron>& layer, int connection_number);
extern float Sigmoid(float weighted_sum);
