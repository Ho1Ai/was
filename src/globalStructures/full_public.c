#include "../lex/lex_out.h"
#include "../com_parser/parser.h"

typedef struct {
	size_t adder;
	} ConfigState;

typedef struct {
	char** content;
	size_t len;
	
	} WorkingInstance;

typedef struct {
	WorkingInstace instances;
	char* final_name;
	int name_free_need;
	LexerOutput* lexer_state;
	ParserOutput* parser_output;
	ConfigState config_state;
	} WorkState;

