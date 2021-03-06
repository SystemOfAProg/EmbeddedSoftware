#ifndef CODE_GENERATOR
#define CODE_GENERATOR
/* ^^ these are the include guards */

/**
 *  Generate asynchronous CDMA code.
 *  Parameters: registers, that are used to make the delay of
 *              the second mother-code
 */
void generateCode(short satteliteID, char* code, int codeLength);

#endif
