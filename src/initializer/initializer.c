#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../globalStructures/full_public.h"
#include "../reader/reader.h"
#include "../lex/lex.h"
#include "../lex/lex_out.h"

#define STRING_COMPARISON_TRUE 0
#define NAME_POS_UNDEFINED -1





int initializeReader(WorkState* work_state, char* args) {
	int state = readSource(work_state, args);
	
	return state;
	}



int initializeLex(WorkState* work_state) { // Lex - Lexer. Don't know why, but somewhere there is another initializeLexer function. Strange, lol
	int status_code = 0;

	LexerOutput* lexeme_list = (LexerOutput*) malloc(sizeof(LexerOutput));
	lexeme_list->tok_amount = 0;

	printf("starting lexer\n");

	startLexer(lexeme_list, work_state);

	work_state->lexer_state = lexeme_list;

	return status_code;
	}




int freeEverything(WorkState* work_state) {
	for (int i = 0 ; i < work_state->instances.len; ++i) {
		free(work_state->instances.content[i]);
		}

	for (int i = 0 ; i < work_state->lexer_state->tok_amount; ++i) {
		free(work_state->lexer_state->tokens_list[i].lexeme);
		printf("Dobby is free! :,)\n");
	}

	free(work_state->lexer_state->tokens_list);


	free(work_state);
	return 0;
	}




void dropContent (WorkState* work_state) { // debug function for file reader
	for (size_t i = 0 ; i < work_state->instances.len; ++i) {
		printf("%ld:\t\t%s\n", i, work_state->instances.content[i]);
		}
	}





int getNameNumber(int argc, char** argv) {
	int response = NAME_POS_UNDEFINED;
	for (int i = 1 ; i < argc ; ++i) {
		if (strcmp(argv[i], "-o")==STRING_COMPARISON_TRUE) {
			response = i+1; // if we found -o, that means only that after this stuff goes final name
			break;
			}
		}

	return response;
	}





int startWork(int argc, char** argv) {
	WorkState* work_state = (WorkState*) malloc(sizeof(WorkState));
	work_state->config_state.adder = 32;
	work_state->instances.content = malloc(sizeof(char*));

	int name_position = getNameNumber(argc, argv);

	if (name_position == NAME_POS_UNDEFINED|| name_position >= argc) {
		char* new_name = "output.wase\0";
		work_state->final_name = new_name;
	} else {
		work_state->final_name = argv[name_position];
		}

	initializeReader(work_state, argv[1]);

	initializeLex(work_state);

	//dropContent(work_state); // debug function for file reader

	freeEverything(work_state);
	}
	
