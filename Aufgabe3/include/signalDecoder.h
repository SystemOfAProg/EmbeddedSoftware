#ifndef SIGNAL_DECODER
#define SIGNAL_DECODER
/* ^^ these are the include guards */

/**
 *  Generate asynchronous CDMA code.
 *  Parameters: registers, that are used to make the delay of
 *              the second mother-code
 */
char decode(char* sumSignal, int sumSignalLength, int position, char* code, int codeLength);

#endif
