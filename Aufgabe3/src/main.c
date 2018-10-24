#include <stdio.h>
#include "../include/reader.h"
#include "../include/codeGenerator.h"

#define satteliteCount 1
#define sumSigCount 1023

int main (int argc, const char* argv[]) {
	const char *fileName = argv[1];
	char sumSignal [sumSigCount];
	char* currentCode;
	int i;
	int correlationProduct = 0;
	// Check codes of all 24 sattelites
	for(i=1; i <= satteliteCount; i++) {
		currentCode = generateCode(i);
		correlationProduct = correlate(sumSignal, currentCode);
		if (correlationProduct != 0) {
			printf("[Main]:\t\t Autocorrelation happened -> Bit Sequence found\n");
		} else {
			printf("[Main]:\t\t No bit-sequence found for sattelite #%d\n", i);
		}
	}
	//read(fileName, " ", sumSignal);
}
