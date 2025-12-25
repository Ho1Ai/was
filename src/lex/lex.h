#ifndef LEXER
#define LEXER

typedef enum {
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_REGISTER,
	TOKEN_STRING,

	TOKEN_COMMA,
	TOKEN_COLON,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_ASTERISK,
	
	TOKEN_DIRECTIVE,
	
	TOKEN_NEWLINE,
	TOKEN_EOF,
	} TokenTypeEnum;

typedef struct {
	TokenTypeEnum type;
	char* lexeme;
	int line;
	int column;
	} LexerToken;

typedef struct {
	LexerToken** tokens_list;
	} LexerOutput;

int initializeLexer(LexerOutput* output);

#endif
