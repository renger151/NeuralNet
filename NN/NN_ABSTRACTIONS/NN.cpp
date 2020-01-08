#include "NN.h"

//This function just creates all connections in neural network
void FillNeuralNetworkWithConnections(vector<Layer>& NeuralNet) {
    for (unsigned i = 1; i < NeuralNet.size(); i++) {
        for (unsigned j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (unsigned y = 0; y < NeuralNet[i - 1].LayerSize; y++) {
                NeuralNet[i].Neurons[j].PreviousLayerConnections[y] = Connection(1 / rand());
            }
        }
    }
}

float LayerWeightedSum(Layer layer, Neuron Neuron) {
    float WeightedSum = 0.0;
    for (unsigned i = 0; i < layer.LayerSize; i++) {
        WeightedSum += layer.Neurons[i].Activation * Neuron.PreviousLayerConnections[i].Weight;
    }
    WeightedSum += Neuron.BIAS;
    return WeightedSum;
}

float Sigmoid(float x) {
    return 1 / (1 + exp((double)-x));
}

void ForwardPropagation(vector<Layer>& NeuralNet) {
    for (unsigned i = 1; i < NeuralNet.size() - 1; i++) {
        for (unsigned j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (unsigned y = 0; y < NeuralNet[i].Neurons[j].PreviousLayerConnections.size(); y++) {
                NeuralNet[i].Neurons[j].Activation = Sigmoid(LayerWeightedSum(NeuralNet[i - 1], NeuralNet[i].Neurons[j]));
            }
        }
    }
};

void BackPropagation(vector<Layer>& NeuralNet, vector<float> ExcpectedValues) {
    //Calculating output layer erros (Formula: Output - Excepected Value)
    for (unsigned i = 0; i < NeuralNet.back().LayerSize; i++) {
        NeuralNet.back().Neurons[i].Error = NeuralNet.back().Neurons[i].Activation - ExcpectedValues[i];
    }
    //Calculating hidden errors (If you need the explanation of this calculation then ask me directly)
    for (unsigned i = NeuralNet.size() - 1; i > 0; i--) {
        for (unsigned j = 0; j < NeuralNet[i].LayerSize; j++) {
            for (unsigned y = 0; i < NeuralNet[i + 1].Neurons[j].PreviousLayerConnections.size(); y++) {
                NeuralNet[i - 1].Neurons[y].Error += NeuralNet[i].Neurons[j].Error * NeuralNet[i].Neurons[j].PreviousLayerConnections[y].Weight;
            }
        }
    }
}

void GradientDescent(vector<Layer>& NeuralNet) {
    for (unsigned i = NeuralNet.size() - 1; i > 0; i--) {
        for (unsigned j = 0; j < NeuralNet[i].Neurons.size(); j++) {
            for (unsigned y = 0; y < NeuralNet[i].Neurons[j].PreviousLayerConnections.size(); y++) {
                //Changing weights
                NeuralNet[i].Neurons[j].PreviousLayerConnections[y].Weight += LearningRate * NeuralNet[i].Neurons[j].Error * (NeuralNet[i].Neurons[j].Activation * (1.0 - NeuralNet[i].Neurons[j].Activation)) * NeuralNet[i - 1].Neurons[y].Activation;;
            }
            //Changing biases
            NeuralNet[i].Neurons[j].BIAS += LearningRate * NeuralNet[i].Neurons[j].Error * (NeuralNet[i].Neurons[j].Activation * (1.0 - NeuralNet[i].Neurons[j].Activation));
        }
    }
}

float GetResults(vector<Neuron> OutputLayer) {
    float MaxValue = 0.0;
    for (int i = 0; i < OutputLayer.size; i++) {
        if (OutputLayer[i].Activation > MaxValue) {
            MaxValue = OutputLayer[i].Activation;
        }
    }
    return MaxValue;
}