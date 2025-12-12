#include <stdio.h>
#include <stdlib.h>

#include "../globalStructures/full_public.h"
#include "./lines_counter.h"








int readSource(WorkState* work_state, char* args) {
	int status = 0;

	FILE* file_instance = fopen(args, "r");

	if (!file_instance) {
		status = 5; 
		goto error;
		}

	size_t lines_amount = getLinesAmount(args);

	work_state->instances.len = lines_amount;

	work_state->instances.content = realloc(work_state->instances.content, sizeof(char*) * work_state->instances.len);

	size_t active_line_len = 0;
	size_t pos_row = 0, pos_col = 0;

	char ch;

	while((ch = getc(file_instance))!=EOF) {
		if(ch != '\n') {
			if (pos_col >= active_line_len) {
				active_line_len+=work_state->config_state.adder;
				work_state->instances.content[pos_row] = realloc(work_state->instances.content[pos_row], sizeof(char)*active_line_len);
				}
			work_state->instances.content[pos_row][pos_col] = ch;
			pos_col++;

			
			} else {
			if (pos_col >= active_line_len) {
				work_state->instances.content[pos_row] = realloc(work_state->instances.content[pos_row], sizeof(char)*(active_line_len+1));
				}
			work_state->instances.content[pos_row][pos_col] = '\0';
			pos_col = 0;
			active_line_len = 0;
			pos_row++;
			}
		}

	error:

	if(status) {
		switch (status) {
			case 5:
				puts("Couldn't find any file with this name");
				break;
			}
		}

	return status;
	}


