#include <string.h>

#define SUPPORTS_SAMESTR 0

int isDecValue (char value_to_test) {
	int result = 0;

	if (value_to_test >= '0' && value_to_test <= '9') result = 1;

	return result;
	}

int isDirective (char* string_to_check) {
	int result = 0;

	if (strcmp(string_to_check, ".byte") == SUPPORTS_SAMESTR || 
		strcmp(string_to_check, ".word") == SUPPORTS_SAMESTR ||
		strcmp(string_to_check, ".long") == SUPPORTS_SAMESTR ||
		strcmp(string_to_check, ".ascii") == SUPPORTS_SAMESTR ||
		strcmp(string_to_check, ".asciz") == SUPPORTS_SAMESTR ||
		strcmp(string_to_check, ".section") == SUPPORTS_SAMESTR ||
		strcmp(string_to_check, ".globl") == SUPPORTS_SAMESTR) {
		result = 1;
		}

	return result;
	}

int isTextChar(char test_char) {
	int result = 0;

	if ((test_char>='A' && test_char<='Z') || (test_char>='a' && test_char <= 'z')) {
		result = 1;
		}

	return result;
	}
