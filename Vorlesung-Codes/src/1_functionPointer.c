#include <stdio.h>

void (*_tmp)(); // Ersatz für die statische Adresse 0xFFFF
unsigned int *fp = (unsigned int *)&_tmp;

// Funktion die ausgeführt werden soll
void f(void) {
  printf("Hello world\n");
}

int main(int argc, char *argv[]) {
  *fp = (unsigned int)f;
  printf("f=  0x%x\n", f);
  printf("fp= 0x%x\n", *fp);
  (*(void(*)())(*fp))(); // Simulierter Funktionsaufruf
  return 1;
}
