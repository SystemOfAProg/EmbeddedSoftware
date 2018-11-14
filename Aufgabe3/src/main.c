#include <stdio.h>
#include "../include/reader.h"
#include "../include/codeGenerator.h"
#include "../include/correlationCalculator.h"
#include "../include/signalDecoder.h"

#define satteliteCount 24
#define sumSignalLength 1023
#define codeLength 1023

void printResult(char* messagedBits) {
	int satteliteID;
	for(satteliteID=1; satteliteID <= satteliteCount; satteliteID++) {
		printf("Sattelite-ID \t Messaged Bit");
		if(messagedBits[satteliteID -1] != -1) {
			printf("%d \t %d", satteliteID, messagedBits[satteliteID - 1]);
		}
	}
}

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
	for(satteliteID=1; satteliteID <= satteliteCount; satteliteID++) {
		generateCode(satteliteID, code, codeLength);
		correlationShiftIndex = correlate(sumSignal, code, codeLength, sumSignalLength);
		if (correlationShiftIndex != -1) {
			codeFoundInSignalIndex[satteliteID - 1] = correlationShiftIndex;
			messagedBits[satteliteID - 1] = decode(sumSignal, sumSignalLength, correlationShiftIndex, code, codeLength);
		} else {
			messagedBits[satteliteID - 1] = -1;
		}
	}
	printResult(messagedBits);
	return 0;
}
