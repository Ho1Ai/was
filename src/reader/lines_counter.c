#include <stdio.h>

size_t getLinesAmount(char* filename) {
	FILE* file_instance = fopen(filename, "r");
	
	size_t response = 0;

	char ch;
	while((ch = getc(file_instance))!=EOF) {
		if(ch == '\n') {
			response++;
			}
		}

	return response;
	}
