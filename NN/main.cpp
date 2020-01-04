#include <stdio.h>
#include <math.h>
#include <vector>

#define LearningRate 0.1
#define NetworkSize 4
#define ILS 784 //Input Layer Size
#define FHLS 16 //First Hidden Layer Size
#define SHLS 16 //Second Hidden Layer Size
#define OLS 10 //Output Layer Size

unsigned i, j, y; //Variables that are beign used so many times, so i decided to define them here and just redeclare them in functions

using namespace std;

struct Connection {
    Connection(float _Weight) {
        this->Weight = _Weight;
    }
    float Weight = 0;
    float DeltaWeight = 0;
};

struct Neuron {
    Neuron(unsigned _Id, int _BIAS) {
        this->Id = _Id;
        this->BIAS = _BIAS;
        printf("Neuron Created!");
    }
    unsigned Id = 0;
    float Activation = 0;
    float Error = 0;
    int BIAS = 0;
    vector<Connection> PreviousLayerConnections;
};

struct Layer {
    Layer(unsigned _LayerSize) {
        this->LayerSize = _LayerSize;
        //Filling the layer with neurons
        for (unsigned i = 0; i < this->LayerSize; i++) {
            this->Neurons.back() = Neuron(i, rand());
        }
        printf("Layer Created!");
    }
    unsigned LayerSize;
    vector<Neuron> Neurons;
};

//This function just creates all connections in neural network
void FillNeuralNetworkWithConnections(vector<Layer>& NeuralNet) {
    for (i = 1; i < NetworkSize; i++) {
        for (j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (y = 0; y < NeuralNet[i - 1].LayerSize; y++) {
                NeuralNet[i].Neurons[j].PreviousLayerConnections[y] = Connection(1 / rand());
            }
        }
    }
}

float LayerWeightedSum(Layer layer, Neuron neuron) {
    float WeightedSum = 0.0;
    for (unsigned i = 0; i < layer.LayerSize; i++) {
        WeightedSum += layer.Neurons[i].Activation * neuron.PreviousLayerConnections[i].Weight;
    }
    return WeightedSum;
}

float Sigmoid(float x) {
    return 1 / (1 + exp((double)-x));
}

void ForwardPropagation(vector<Layer>& NeuralNet) {
    for (i = 1; i < NetworkSize - 1; i++) {
        for (j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (y = 0; y < NeuralNet[i].Neurons[j].PreviousLayerConnections.size(); y++) {
                NeuralNet[i].Neurons[j].Activation = Sigmoid(LayerWeightedSum(NeuralNet[i - 1], NeuralNet[i].Neurons[j]));
            }
        }
    }
};

void BackPropagation(vector<Layer>& NeuralNet, vector<float> ExcpectedValues) {
    //Calculating output layer erros (Formula: Output - Excepected Value)
    for (i = 0; i < NeuralNet.back().LayerSize; i++) {
        NeuralNet.back().Neurons[i].Error = NeuralNet.back().Neurons[i].Activation - ExcpectedValues[i];
    }
    //Calculating hidden errors (If you need the explanation of this calculation then ask me directly)
    for (i = NetworkSize - 1; i > 0; i--) {
        for (j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (y = 0; i < NeuralNet[i + 1].Neurons[j].PreviousLayerConnections.size(); y++) {
                NeuralNet[i - 1].Neurons[y].Error += NeuralNet[i].Neurons[j].Error * NeuralNet[i].Neurons[j].PreviousLayerConnections[y].Weight;
            }
        }
    }
}

void GradientDescent(vector<Layer>& NeuralNet) {
    for (i = NetworkSize - 1; i > 0; i--) {
        for (j = 0; j < NeuralNet[i].Neurons.size(); j++) {
            for (y = 0; y < NeuralNet[i].Neurons[j].PreviousLayerConnections.size(); y++) {
                NeuralNet[i].Neurons[j].PreviousLayerConnections[y].DeltaWeight = LearningRate * NeuralNet[i].Neurons[j].Error * (NeuralNet[i].Neurons[j].Activation + (1 - NeuralNet[i].Neurons[j].Activation)) * NeuralNet[i - 1].Neurons[y].Activation;
                NeuralNet[i].Neurons[j].PreviousLayerConnections[y].Weight += NeuralNet[i].Neurons[j].PreviousLayerConnections[y].DeltaWeight;
            }
        }
    }
}

int main() {
    printf("Dima is Gay!");
    return 0;
}
