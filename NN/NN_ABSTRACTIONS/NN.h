#pragma once

#include <stdio.h>
#include <math.h>
#include <vector>

#define LearningRate 0.1f

using namespace std;

struct Connection {
    Connection(float _Weight) {
        this->Weight = _Weight;
    }
    float Weight = 0;
    float DeltaWeight = 0;
};

struct Neuron {
    Neuron(float _BIAS) {
        this->BIAS = _BIAS;
        printf("Neuron Created!");
    }
    float Activation = 0;
    float Error = 0;
    float BIAS = 0;
    vector<Connection> PreviousLayerConnections;
};

struct Layer {
    Layer(unsigned _LayerSize) {
        this->LayerSize = _LayerSize;
        //Filling the layer with neurons
        for (unsigned i = 0; i < this->LayerSize; i++) {
            this->Neurons.back() = Neuron(float(rand()));
        }
        printf("Layer Created!");
    }
    unsigned LayerSize;
    vector<Neuron> Neurons;
};

void FillNeuralNetworkWithConnections(vector<Layer>& NeuralNet);
float LayerWeightedSum(Layer layer, Neuron Neuron);
float Sigmoid(float x);
void ForwardPropagation(vector<Layer>& NeuralNet, unsigned char *InputVals);
void BackPropagation(vector<Layer>& NeuralNet, vector<float> &ExcpectedValues);
void GradientDescent(vector<Layer>& NeuralNet);
float GetResults(Layer OutputLayer);

