#include "../lex/lex_out.h"

#ifndef PUBLIC_STRUCTS
#define PUBLIC_STRUCTS

typedef struct {
	size_t adder;
	} ConfigState;

typedef struct {
	char** content;
	size_t len;
	} WorkingInstance;

typedef struct {
	WorkingInstance instances;
	char* final_name;
	LexerOutput* lexer_state;
	ConfigState config_state;
	} WorkState;

#endif
