#include "File.h"

bool ReadFile(const char* Filepath, float& ReadInArray, unsigned int ReadInArraySize) {
	FILE* f = fopen(Filepath, "r");
	if (!f) {
		printf("File opening error!");
		return false;
	}
	if (fread(&ReadInArray, sizeof(float), ReadInArraySize, f) > 0) {

	}

	fclose(f);
	return true;
}