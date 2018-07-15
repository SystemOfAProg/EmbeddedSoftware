#include "stdio.h"
#include "string.h"
 
int main(int argc, char* argv[]) {
    typedef struct {
        short *dog[2]; // Hinweis: ’*’ beachten 
        short cat;
    } A; typedef struct {
        short *dog[2]; // Hinweis: ’*’ beachten 
        short cat; 
        long mouse;
    } B;
    A a[2]; B b[2];
    printf("sizeof(a) = %ld\n", sizeof(a));
    printf("sizeof(b) = %ld\n", sizeof(b));
    return 0;
}

