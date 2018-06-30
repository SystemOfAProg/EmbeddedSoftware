#include "stdio.h"
#include "inttypes.h"

// A 16-bit shift register
uint16_t shiftreg;

// Load shift register with value
// void load(uint16_t value) {
//     shiftreg = value;
// }

// Version that does not depend on little- / Big Endian
void load(uint16_t value) {
    shiftreg = value;
    char *shiftregPointer = &shiftreg;
    // Write left byte of value in left byte of buffer
    shiftregPointer = (value & 0xFF00);
    // Point to right byte of shiftregister
    shiftregPointer++;
    // Write right byte of value in right byte of buffer
    shiftregPointer = (value & 0x00FF);
}

// Shift one bit left
void shift() {
    shiftreg <<= 1;
}

// Pick leftmost bit
unsigned pick() {
    return (shiftreg & 0x8000) ? 1 : 0;
}

// Main function: Should output 0000000001000010
int main(int argc, char* argv[]){
    load(0x42); // 0000 0000 0100 0010
    for (unsigned i = 0; i < 16; i++, shift())
        printf("%d", pick());
    printf("\n");
    return 0;
}