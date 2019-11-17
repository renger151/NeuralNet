#pragma once
#include <fstream>
#include <nn_abstraction/nn.h>


extern bool LoadOutputFromFile(const char* filepath, vector<Neuron>& WriteInLayer);