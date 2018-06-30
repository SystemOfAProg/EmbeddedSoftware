#include <stdio.h>

struct e {
	int a;
    char b;
    long c;
    short d;
};

void initStruct(struct e *myStruct);
void printStruct(struct e *myStruct);

int main(int argc, char *argv[]) {
    struct e myStruct;
    initStruct(&myStruct);
    myStruct.a = 3;
    myStruct.b = 3;
    myStruct.c = 3;
    myStruct.d = 3;
    printStruct(&myStruct);
    printf("\n");
    return 1;
}

void initStruct(struct e *myStruct) {
    int i;
    for (i=0; i<sizeof(*myStruct); i++) {
        ((char *)myStruct)[i] = 6;
    }
}

void printStruct(struct e *myStruct) {
    int i;
    for (i=0; i<sizeof(*myStruct); i++) {
        if(i%4 == 0)
            printf(" ");
        char j = ((char *)myStruct)[i];
        if(j == 0 || j == 3)
            printf("%d", ((char *)myStruct)[i]);
        else
            printf("-");
    }
}