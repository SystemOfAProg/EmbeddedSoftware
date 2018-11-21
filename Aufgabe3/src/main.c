#include <stdio.h>
#include <stdlib.h>
#include "../include/reader.h"
#include "../include/codeGenerator.h"
#include "../include/correlationCalculator.h"
#include "../include/signalDecoder.h"

#define satteliteCount 24
#define sumSignalLength 1023
#define codeLength 1023
// Values taken from observation, TODO: check if they are correct
#define maxNoise 1024
#define minNoise -1024

int main (int argc, const char* argv[]) {
	// sum signal read from text file
	char sumSignal [sumSignalLength];
	int codeFoundInSignalIndex [satteliteCount];
	int messagedBits[satteliteCount];
	read((const char*)argv[1], " ", sumSignal);
	// generatede code for the sattelite
	char code[codeLength];
	int satteliteID;
	int correlationShiftIndex = 0;
	// Check codes of all 24 sattelites
	printf("\nSattelite-ID \t Code-Shift \t Messaged Bit\n");
	for(satteliteID=0; satteliteID < satteliteCount; satteliteID++) {
		generateCode(satteliteID, code, codeLength);
		correlationShiftIndex = correlate(sumSignal, code, codeLength, sumSignalLength, maxNoise, minNoise);
		codeFoundInSignalIndex[satteliteID] = correlationShiftIndex;
		if (correlationShiftIndex != -1) {
			messagedBits[satteliteID] = decode(sumSignal, sumSignalLength, correlationShiftIndex, code, codeLength);
			printf("%d \t\t %d \t\t %d\n", satteliteID, codeFoundInSignalIndex[satteliteID], messagedBits[satteliteID]);
		} else {
			messagedBits[satteliteID] = -1;
		}
	}
	return 0;
}
