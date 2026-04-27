#include "../globalStructures/full_public.h"
#include "../lex/lex_out.h"
#include "./parser.h"
#include <string.h>

#include <stdio.h>

/*
int recognizeParserStruct() {
	
	}
*/

// movb, movl, movd, movq (not ready yet), push, pop, int, addb, addw, addl, jmp, call, ret, je, jne, jg, jge, jl, jle, jz, jnz, and, or, xor, not, leal, cmp // is it enough for start version?

const char* instructionsList[] = {"movb", "movl", "movd", "push", "pop", "int", "addb", "addw", "addl", "jmp", "call", "ret", "je", "jne", "jg", "jge", "jl", "jle", "jz", "jnz", "and", "or", "xor", "not", "leal", "cmp", "\0"}; // at the moment there is only these commands. Gonna add a lot of other stuff. For example, there is no lea, xlat, xchg, in, out and other stuff at the moment.

int checkLabel(LexerToken entry) {
	int status_code = 0;
	//printf("%s\n", entry.lexeme);
	
	//printf("%c", entry.lexeme[strlen(entry.lexeme)-1]);
	if(entry.lexeme[strlen(entry.lexeme)-1] == ':') {
		status_code = 1;
		//printf("label:: %s\n", entry.lexeme);
		}

	return status_code;
	}

int checkInstruction(LexerToken entry) {
	int status_code = 0;
	
	size_t i = 0;
	while(instructionsList[i][0]) {
		if(strcmp(instructionsList[i], entry.lexeme) == 0) {
			//printf("%s - %d\n", entry.lexeme, i);
			status_code = 1;
			goto leaveCI;
		}
		i++;
		}
	
leaveCI:
	return status_code;
	}

ParserEntryType getIdentifierType(LexerOutput* lexer_state, int position, int max_position) {
	ParserEntryType result = PE_FATAL_ERROR;
	if (checkInstruction(lexer_state->tokens_list[position])) {
		//printf("Instruction %d %d\n", position, max_position);
		result = PE_INSTRUCTION;
		goto getIDT_end;
		}

	if(checkLabel(lexer_state->tokens_list[position])) {
		//printf("label");
		result = PE_LABEL;
		}
	
getIDT_end:
	return result;
	}

int startParser(WorkState* work_state) {
	int status_code = 0; // 0 - OK

	int token_amount = work_state->lexer_state->tok_amount;

	for(int i = 0 ; i < token_amount ; ++i) {
		//int recognizeParserStruct()
		LexerToken curr = work_state->lexer_state->tokens_list[i];
		
		if (curr.type == TOKEN_IDENTIFIER) {
			printf("identifier\n");
			ParserEntryType type_test = getIdentifierType(work_state->lexer_state, i, token_amount);
			}
		}
	} 
