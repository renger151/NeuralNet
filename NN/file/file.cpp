#include "file.h"

bool LoadOutputFromFile(const char* filepath, vector<Neuron>& WriteInLayer) {
	FILE* file = fopen(filepath, "r");
	if (!file) {
		printf("Couldnt open file!");
		return false;
	}
	//Reading data from file and writing it to the WriteInLayer

}