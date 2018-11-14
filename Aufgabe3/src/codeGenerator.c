#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))
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

void printBit(char x) {
	(x & 1u) ? putchar('1') : putchar('0');
}

// Print lowest ten bits of short variable
void printRegister(short reg) {
	int i,j;
	for (i = 5; i < 16; i++) {
      printf("%d", !!((reg << i) & 0b1000000000000000));
  }
  printf("\n");
}

// Get specific bit value in register
// MAXIMUM = registerLength
char bitAt(short reg, short position) {
	// printRegister(reg);
	return reg >> (registerLength-position) & 1U;
}

// XOR all given bits to one result
char xorBits(short reg, short positions[], short positionsLength) {
	short i;
	char result = bitAt(reg, positions[0]);
	for (i=1; i<positionsLength; i++) {
		result = result ^ bitAt(reg, positions[i]);
	}
	return result;
}

void generateCode(short satteliteID, char* code, int codeLength) {
	short register1 = regStartValue;
	short register2 = regStartValue;
	int i;
	// printf("[Code]:\t\t Generate Code for sattelite #%d.\n", satteliteID);
	for(i=0; i<codeLength; i++) {
		char newBitReg1 = xorBits(register1, reg1positions, NELEMS(reg1positions));
		char newBitReg2 = xorBits(register2, reg2positions, NELEMS(reg2positions));
		char delayedBitFromReg2 = xorBits(register2, reg2delayPositions[satteliteID-1], NELEMS(reg2delayPositions[satteliteID]));
		code[i]=(register1 & 1) ^ delayedBitFromReg2;
		// Replace 0 with -1 for Correlation Calculation
		if(code[i] == 0) {
			code[i] = -1;
		}
		register1 = (register1 >> 1) + (newBitReg1 << (registerLength - 1));
		register2 = (register2 >> 1) + (newBitReg2 << (registerLength - 1));
	}
	return;
}
