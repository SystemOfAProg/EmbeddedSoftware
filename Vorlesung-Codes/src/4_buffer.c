#include <stdio.h>

char buffer[8]; // Ring buffer with 8 elements
char *writePtr = buffer;

void advance(int bytes) { // Advance write pointer by a number of bytes
    writePtr += bytes;
    if ((writePtr - buffer) >= sizeof(buffer))
        writePtr = buffer;
}

void putChar(char item) { // Write character value into ring buffer
    *writePtr = item;
    advance(1);
}

void putInt(int item) { // Write integer value into ring buffer
    *((int *)writePtr) = item;
    advance(sizeof(int));
}

void putLong(long item) { // Write long value into ring buffer
    *((long *)writePtr) = item;
    advance(sizeof(long));
}

int main(int argc, char **argv) {
    unsigned i;
    putLong(1); putInt(2); putChar(3);
    // print ringbuffer contents
    for (i = 0; i < sizeof(buffer); i++)
        printf("%2X ", buffer[i]); // Note: %2X means "two digit hexadecimal output“
    printf("\n");
    return 1;
}