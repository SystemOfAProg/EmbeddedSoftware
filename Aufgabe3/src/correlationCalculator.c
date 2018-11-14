#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correlate(char vector1[], char vector2[], int codeLength, int sumSignalLength) {
	int product = 0;
	int shift, vectorIndex;
	for (shift = 0; shift<sumSignalLength; shift++) {
		product = 0;
		for (vectorIndex=0; vectorIndex<codeLength; vectorIndex++) {
			product += vector1[((vectorIndex + shift) % codeLength)] * vector2[vectorIndex];
		}
		if (product != 0) {
			return shift;
		}
	}
	return -1;
}
