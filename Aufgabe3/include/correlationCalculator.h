#ifndef CORRELATION_CHECKER
#define CORRELATION_CHECKER
/* ^^ these are the include guards */

/**
 *  Calculates the correlation product of a chip-sequence and
 *  a sum signal
 */
int correlate(char vector1[], char vector2[], int codeLength, int sumSignalLength, int highestNonPeakValue, int lowestNonPeakValue);

#endif
