#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read(const char* fileName, char* separator, char* arr){
  // File to read
	FILE *fs;
  // Current character in File
	char ch;
  // Buffer for reading multi-char integer values
  char buffer[32];
  int charBufferIndex = 0;
  int integerValueArrayIndex = 0;
  fs = fopen(fileName, "r");
	if(fs == NULL) {
		return -1;
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
	return 0;
}
