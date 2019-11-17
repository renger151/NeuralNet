#pragma once
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

extern void FeedForward(vector<vector<Neuron>>& NeuralNetwork);
extern void BackPropagation(vector<vector<Neuron>>& NeuralNetwork, vector<float> OutputLayerExpectingValues);
extern float NeuronWeightedSum(vector<Neuron>& layer, int connection_number);
extern float Sigmoid(float weighted_sum);
