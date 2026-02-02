#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../globalStructures/full_public.h"
#include "../supports/supports.h"
#include "./lex_out.h"

/* Execution results (status codes):
 *  0 - OK
 * 	1 - Not defined
 */

/* I use integers here instead of enum... Never mind, gonna replace in the nearest future. I just like using integers instead of enums, so on first prototype version it will be okay to use this stuff just to make it usable
 * 0 - immediate
 * 1 - value
 * -1 - undefined (the assembler will crash)
 */

typedef struct {
	TokenTypeEnum ttype; // TType - Token Type
	int vector; // vector - length of current lexeme. This name was taken cuz vector has length: l = sqrt(a_1 * a_1 + a_2 * a_2 + ... + a_n * a_n). Also I thought the structure would keep start position and end position, but then I understood that it is unnecessary, cuz I can count positions somewhere else in the nearest future after the lexer
	} DefinersResponseStructure;










DefinersResponseStructure defineDollarTokenType(WorkState* work_state, size_t i, size_t j) { // i and j are positions
	DefinersResponseStructure result = {TOKEN_UNRECOGNIZED, 0};

	char* test_line = malloc(sizeof(char));

	int position_adder = 0;
	int possible_to_proceed = 1;

	while(possible_to_proceed) {
		char curr = work_state->instances.content[i][j+position_adder];
		if (curr != ' ' && curr != '\t' && curr != '\0' && curr != ';' && curr != ',' && curr != '\n' && curr != '#') { // is it necessary to have \n here?
			test_line = realloc(test_line, sizeof(char)*(position_adder+1));
			test_line[position_adder] = curr;
			}
		else {
			possible_to_proceed = 0;
			
			result.vector = position_adder;
			if(isDecValue(test_line[1])) {
				result.ttype = TOKEN_IMMED;
				printf("immediate in %d - %d\n", i, j);
				} else {
				result.ttype = TOKEN_IDENTIFIER;
				}
		}
		position_adder++;
	}
	
	free(test_line);

	return result;
	}

DefinersResponseStructure defineDotTokenType(WorkState* work_state, size_t i, size_t j) {
	DefinersResponseStructure result = {TOKEN_UNRECOGNIZED, 0};

	char* test_line = malloc(sizeof(char));

	int position_adder = 0;
	int possible_to_proceed = 1;

	while(possible_to_proceed) {
		char curr = work_state->instances.content[i][j+position_adder];
		if (curr != ' ' && curr != '\t' && curr != '\0' && curr != ';' && curr != ',' && curr != '\n' && curr != '#') {
			test_line = realloc(test_line, sizeof(char)*(position_adder+1));
			test_line[position_adder] = curr;
			} else {
			result.vector = position_adder;
			possible_to_proceed = 0;
			if(test_line[position_adder-1] == ':') {
				result.ttype = TOKEN_IDENTIFIER;
				printf("identifier (label) on: %d - %d\n", i, j);
				} else if (isDirective(test_line)) {
				result.ttype = TOKEN_DIRECTIVE;
				printf("directive on: %d - %d\n", i, j);
				} else {
				result.ttype = TOKEN_IDENTIFIER;
				printf("identifier on: %d - %d\n", i, j);
				}
			}
			position_adder++;
		}


	return result;
	}

/*
int definePercentTokenType(WorkState* work_state, size_t i, size_t j) {
	int result = 0;
	
	

	return result;
	} */

int startLexer (LexerOutput* output, WorkState* work_state) {
	int execution_result = 0;

	size_t reallocation_size = 100;

	output->tokens_list = realloc(output->tokens_list, sizeof(LexerToken) * reallocation_size);

	size_t j = 0;
	size_t last_lexeme_index = 0;

	for (size_t i = 0; i < work_state->instances.len; ++i) {

		size_t curr_start_pos = 0; // why?

		while(work_state->instances.content[i][j]) {
			char curr_char = work_state->instances.content[i][j];
			switch(curr_char) {
				case '%':
					int test_len = 0;
					while (1) {
						test_len++;
						char tchar = work_state->instances.content[i][j+test_len];
						if(isTextChar(tchar) == 0) {
							break;
							}
						}
					if(output->tok_amount+1 > reallocation_size) {
						reallocation_size += 100;
						output->tokens_list = realloc(output->tokens_list, sizeof(LexerToken) * reallocation_size);
						}
					
					output->tokens_list[output->tok_amount].lexeme = malloc(sizeof(char) * (test_len+1));
					for (int k = 0; k < test_len; k++) {
						output->tokens_list[output->tok_amount].lexeme[k] = work_state->instances.content[i][j+k];
						}
					output->tokens_list[output->tok_amount].lexeme[test_len] = '\0';
					output->tokens_list[output->tok_amount].type = TOKEN_REGISTER;
					output->tokens_list[output->tok_amount].line = i;
					output->tokens_list[output->tok_amount].column = j;
					output->tok_amount++;

					printf("register on: %d - %d\n", i, j);

					break;
				case '$':
					DefinersResponseStructure token_type_check_dlr = defineDollarTokenType(work_state, i, j);
					if(output->tok_amount+1>reallocation_size) {
						reallocation_size+=100;
						output->tokens_list = realloc(output->tokens_list, sizeof(LexerToken) * reallocation_size);
						}
					//printf("%d\n", token_type_check_dlr.vector);
					output->tokens_list[output->tok_amount].lexeme = malloc((token_type_check_dlr.vector + 1) * sizeof(char));
					for (int k = 0; k < token_type_check_dlr.vector; k++) {
						output->tokens_list[output->tok_amount].lexeme[k] = work_state->instances.content[i][j+k];
						}
					output->tokens_list[output->tok_amount].lexeme[token_type_check_dlr.vector] = '\0';
					output->tokens_list[output->tok_amount].type = token_type_check_dlr.ttype;
					output->tokens_list[output->tok_amount].line = i;
					output->tokens_list[output->tok_amount].column = j;
					output->tok_amount++;
					break;
				case '.':
					// let's just call it identifier... Gonna recognize everything in parser, cuz by that time I'll have already had tokens and content, so it would be easier to work.
					DefinersResponseStructure token_type_check_dot = defineDotTokenType(work_state, i, j);
					if(output->tok_amount+1>reallocation_size) {
						reallocation_size+=100;
						output->tokens_list = realloc(output->tokens_list, sizeof(LexerToken) * reallocation_size);
						}
					output->tokens_list[output->tok_amount].lexeme = malloc((token_type_check_dot.vector + 1) * sizeof(char));
					for (int k = 0; k < token_type_check_dot.vector; k++) {
						output->tokens_list[output->tok_amount].lexeme[k] = work_state->instances.content[i][j+k];
						}
					output->tokens_list[output->tok_amount].lexeme[token_type_check_dot.vector] = '\0';
					output->tokens_list[output->tok_amount].type = token_type_check_dot.ttype;
					output->tokens_list[output->tok_amount].line = i;
					output->tokens_list[output->tok_amount].column = j;
					output->tok_amount++;
					break;
				case ',':
					if(output->tok_amount+1>reallocation_size) {
						reallocation_size+=100;
						output->tokens_list = realloc(output->tokens_list, sizeof(LexerToken) * reallocation_size);
						}
					output->tokens_list[output->tok_amount].lexeme = malloc((2) * sizeof(char)); // 2 = 1 (',') + 1 ('\0')
					
					output->tokens_list[output->tok_amount].lexeme[0] = ',';
					output->tokens_list[output->tok_amount].lexeme[1] = '\0';
					output->tokens_list[output->tok_amount].type = TOKEN_COMMA;
					output->tokens_list[output->tok_amount].line = i;
					output->tokens_list[output->tok_amount].column = j;
					output->tok_amount++;
					printf("coma on: %d - %d\n", i, j);
					break;
				case ';':
					// not a token type, just a way to skip the line
					printf("comment on: %d - %d\n", i, j);
					goto leave_inner_loop;
					break;
				case '#':
					// also not a token type, but just a way to skip the line
					printf("comment on: %d - %d\n", i, j);
					goto leave_inner_loop;
					break;
				default:
					TokenTypeEnum ttype = TOKEN_UNRECOGNIZED;
					if(curr_char == ' ' || curr_char == '\t' || curr_char == '\n') break;
					if(j>0){
						char test_char = work_state->instances.content[i][j-1];
						if ((test_char == ' ' || test_char == '\t') && (test_char != '.') && (isDecValue(curr_char) == 0)) {
							printf("identifier on: %d - %d\n", i, j);
							ttype = TOKEN_IDENTIFIER;
							} else if(isDecValue(curr_char) && (test_char == ' ' || test_char == '\t' || test_char == ',')) {
							printf("number on: %d - %d\n", i, j);
							ttype = TOKEN_NUMBER;
							}
					} else {
						printf("identifier on %d - %d\n", i, j);
						ttype = TOKEN_IDENTIFIER;
						}
					break;
				}
				// create tokens here
				j++;
			}
			leave_inner_loop:
			j = 0;
		} 

	return execution_result;
	}


// directives:
//		.byte
//		.word
//		.long
//		.ascii
//		.asciz
