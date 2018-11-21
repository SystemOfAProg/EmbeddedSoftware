#include <stdio.h>
#include <stdlib.h>

int setBit(char bit, short position, int value) {
	if(bit == 0 || bit == 1) {
		value |= bit << position;
	}
	return value;
}

int decode(char* sumSignal, int sumSignalLength, int position, char* code, int codeLength) {
	int messagedBits = 0;
	int result, currentBit, sumSignalIndex, codePosition, sumSignalPosition, v1, v2;
	for(sumSignalIndex=0; sumSignalIndex<sumSignalLength; sumSignalIndex++) {
		result = 0;
		currentBit = sumSignalIndex/sumSignalLength;
		codePosition = sumSignalIndex % codeLength;
		sumSignalPosition = (sumSignalIndex + position) % sumSignalLength;
		v1 = code[codePosition];
		v2 = sumSignal[sumSignalPosition];
		result += v1 * v2;
		// Divide by codeLength at the end
 		if (sumSignalIndex == (currentBit + 1)*codeLength - 1) {
			result = result/codeLength;
			if(result == -1) {
				result = 0;
			}
			setBit(result, currentBit, messagedBits);
		}
	}
	return messagedBits;
}
