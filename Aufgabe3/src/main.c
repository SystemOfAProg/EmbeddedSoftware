#include <stdio.h>
#include <stdlib.h>
#include "../include/reader.h"
#include "../include/codeGenerator.h"
#include "../include/correlationCalculator.h"
#include "../include/signalDecoder.h"

#define satteliteCount 24
#define sumSignalLength 1023
#define codeLength 1023
#define maxNoise 63

int main (int argc, const char* argv[]) {
	// sum signal read from text file
	char sumSignal [sumSignalLength];
	int codeFoundInSignalIndex [satteliteCount];
	char messagedBits[satteliteCount];
	read((const char*)argv[1], " ", sumSignal);
	// generatede code for the sattelite
	char code[codeLength];
	int satteliteID;
	int correlationShiftIndex = 0;
	// Check codes of all 24 sattelites
	printf("\nSattelite-ID \t Code-Shift \t Messaged Bit\n");
	for(satteliteID=1; satteliteID <= satteliteCount; satteliteID++) {
		generateCode(satteliteID, code, codeLength);
		correlationShiftIndex = correlate(sumSignal, code, codeLength, sumSignalLength, 5*maxNoise, -5*maxNoise);
		codeFoundInSignalIndex[satteliteID - 1] = correlationShiftIndex;
		if (correlationShiftIndex != -1) {
			messagedBits[satteliteID - 1] = decode(sumSignal, sumSignalLength, correlationShiftIndex, code, codeLength);
			printf("%d \t\t %d \t\t %d\n", satteliteID, codeFoundInSignalIndex[satteliteID - 1], messagedBits[satteliteID - 1]);
		} else {
			messagedBits[satteliteID - 1] = -1;
		}
	}
	return 0;
}
