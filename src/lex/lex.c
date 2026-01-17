#include <stdio.h>
#include "../globalStructures/full_public.h"

typedef enum {
	TOKEN_IDENTIFIER,
	TOKEN_NUMBER,
	TOKEN_REGISTER,
	TOKEN_STRING,
	
	TOKEN_OPCOLON,
	TOKEN_OPPLUS,
	TOKEN_OPMINUS,
	TOKEN_OPASTERISK,

	TOKEN_DIRECTIVE, // for future development. Now WAS doesn't have any directives except .byte, .word, .long, etc.
	
	TOKEN_NEWLINE,
	TOKEN_EOF,
	} TokenTypeEnum;



typedef struct {
	TokenTypeEnum type;
	char* lexeme;
	int line;
	int column; // for debug
	} LexerToken;

typedef struct {
	LexerToken** tokens_list;
	} LexerOutput;



/* Execution results (status codes):
 *  0 - OK
 * 	1 - Not defined
 */
int startLexer (LexerOutput* output, WorkState* work_state) {
	int execution_result = 0;
	
	size_t j = 0;

	for (size_t i = 0; i < work_state->instances.len; ++i) {
		//printf("%s\n", work_state->instances.content[i]);

		size_t curr_start_pos = 0;

		while(work_state->instances.content[i][j]) {
			char curr_char = work_state->instances.content[i][j];
			switch(curr_char) {
				case '[':
					
				}
			}
		} 

	return execution_result;
	}


// directives:
//		.byte
//		.word
//		.long
//		.ascii
//		.asciz
