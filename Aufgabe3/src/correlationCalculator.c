#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correlate(char vector1[], char vector2[], int codeLength, int sumSignalLength, int highestNonPeakValue, int lowestNonPeakValue) {
	int product, shift, vectorIndex, v1Value, v2Value;
	for (shift = 0; shift<sumSignalLength; shift++) {
		product = 0;
		for (vectorIndex=0; vectorIndex<codeLength; vectorIndex++) {
			v1Value = vector1[((vectorIndex + shift) % codeLength)];
			v2Value = vector2[vectorIndex];
			// printf("\n%d \t %d \t = \t %d", v1Value,v2Value, v1Value*v2Value);
			product += v1Value * v2Value;
		}
		// Check if normalized correlation product is not near 0
		if (product >= highestNonPeakValue || product <= lowestNonPeakValue) {
			return shift;
		}
	}
	return -1;
}
