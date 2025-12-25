#include <stdio.h>

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
	int column; // for debug
	} LexerToken;



/* Execution results (status codes):
 *  0 - OK
 * 	1 - Not defined
 */

int initializeLexer (LexerOutput* output) {
	int execution_result = 0;
	
	

	return execution_result;
	}
