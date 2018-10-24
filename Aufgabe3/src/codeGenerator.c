#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define codeLength 1023
#define registerLength 10

short reg1positions[2] = {3,10};
short reg2positions[6] = {2,3,6,8,9,10};
short reg2delayPositions[24][2] = {
	{2,  6}, //  1
	{3,  7}, //  2
	{4,  8}, //  3
	{5,  9}, //  4
	{1,  9}, //  5
	{2, 10}, //  6
	{1,  8}, //  7
	{2,  9}, //  8
	{3, 10}, //  9
	{2,  3}, // 10
	{3,  4}, // 11
	{5,  6}, // 12
	{6,  7}, // 13
	{7,  8}, // 14
	{8,  9}, // 15
	{9, 10}, // 16
	{1,  4}, // 17
	{2,  5}, // 18
	{3,  6}, // 19
	{4,  7}, // 20
	{5,  8}, // 21
	{6,  9}, // 22
	{1,  3}, // 23
	{4,  6}  // 24
};
short regStartValue = 0b1111111111;

// Get specific bit value in register
// MAXIMUM = registerLength
char bitAt(short reg, short position) {
	return reg & (1 << (registerLength-position)) >> (position-1);
}

// XOR all given bits to one result
char xorBits(short reg, short positions[]) {
	char result = bitAt(reg, positions[0]);
	short i;
	for (i=1; i<(sizeof(positions)/sizeof(positions[0])); i++) {
		result = result ^ positions[i];
	}
	return result;
}

void printBit(char x) {
	(x & 1u) ? putchar('1') : putchar('0');
}

char* generateCode(short satteliteID) {
	char code[codeLength];
	short register1 = regStartValue;
	short register2 = regStartValue;
	int i;
	printf("[Code]:\t\t Generate Code for sattelite #%d.\n", satteliteID);
	for(i=0; i<codeLength; i++) {
		char newBitReg1 = xorBits(register1, reg1positions);
		char newBitReg2 = xorBits(register2, reg2positions);
		char delayedBitFromReg2 = xorBits(register2, reg2delayPositions[satteliteID]);
		code[i]=(register1 & 1) ^ delayedBitFromReg2;
		register1 = (register1 >> 1) + (newBitReg1 << 9);
		register2 = (register2 >> 1) + (newBitReg2 << 9);
		// printBit(code[i]);
	}
	return code;
}
