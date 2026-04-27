#include "../lex/lex_out.h"
#include <stdlib.h>

#ifndef PUBLIC_STRUCTS
#define PUBLIC_STRUCTS

#include "../com_parser/parser.h"
// was tryna fix double import... lol

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
	ParserOutput* parser_state;
	ConfigState config_state;
	} WorkState;

#endif
