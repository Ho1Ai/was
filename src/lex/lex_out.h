#ifndef LEXER_OUTPUT
#define LEXER_OUTPUT

typedef enum {
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_IMMED,
	TOKEN_REGISTER,
	TOKEN_STRING,
	
	TOKEN_OPCOLON,
	TOKEN_OPPLUS,
	TOKEN_OPMINUS,
	TOKEN_OPASTERISK,
	TOKEN_COMMA,

	TOKEN_DIRECTIVE, // for future development. Now WAS doesn't have any directives except .byte, .word, .long, etc.
	
	TOKEN_NEWLINE,
	TOKEN_EOF,
	TOKEN_UNRECOGNIZED,
	} TokenTypeEnum;

typedef struct {
	TokenTypeEnum type;
	char* lexeme; // text
	int line;
	int column; // for debug
	} LexerToken;


typedef struct {
	LexerToken* tokens_list;
	int tok_amount;
	} LexerOutput;

#endif
