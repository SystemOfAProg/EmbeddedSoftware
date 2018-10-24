#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(const char* fileName, char* separator, int* arr){
  // File to read
	FILE *fs;
	printf("Read interger values of sum signal from file %s\n", fileName);
  // Current character in File
	char ch;
  // Buffer for reading multi-char integer values
  char* buffer[32];
  int i = 0;
  // Current index for Integer Value Storage
  int j = 0;
  fs = fopen(fileName, "r");
	int negativeInteger = 0;
  while(fs != NULL){
		ch = fgetc(fs);
    if(ch == EOF){
			break;
		} else if(ch == *separator){
			if(negativeInteger > 0) {
      	arr[j] = atoi(buffer);
			} else {
				arr[j] = -atoi(buffer);
			}
			printf("%s\n", buffer);
      j++;
			negativeInteger = 0;
      bzero(buffer, 32);
      i = 0;
      continue;
		} else{
			buffer[i] = ch;
      i++;
		}
	}
  for(i = 0; i < j; i++){
		printf("Number [%d]: %d\n", i, arr[i]);
	}
}
