#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(const char* fileName, char* separator, char* arr){
  // File to read
	FILE *fs;
	printf("[Reader]: Read interger values of sum signal from file %s\n",  fileName);
  // Current character in File
	char ch;
  // Buffer for reading multi-char integer values
  char buffer[32];
  int charBufferIndex = 0;
  int integerValueArrayIndex = 0;
  fs = fopen(fileName, "r");
	if(fs == NULL) {
		printf("[Reader]: File with name %s could not be opened. Please check if the file exists.", fileName);
	} else {
		printf("[Reader]: File with name %s could be opened. Start reading integer values.", fileName);
	}
  while(fs != NULL){
		ch = fgetc(fs);
    if(ch == EOF){
			break;
		} else if(ch == *separator){
			if(buffer[0] == '-') {
      	arr[integerValueArrayIndex] = - atoi((const char*)buffer + sizeof(char));
			} else {
				arr[integerValueArrayIndex] = atoi((const char*)buffer);
			}
      integerValueArrayIndex++;
      bzero(buffer, 32);
      charBufferIndex = 0;
      continue;
		} else{
			buffer[charBufferIndex] = ch;
      charBufferIndex++;
		}
	}
}
