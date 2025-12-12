#include <stdio.h>
#include <stdlib.h>

#include "./reader/lines_counter.h"
#include "./globalStructures/full_public.h"
#include "./initializer/initializer.h"

int main(int argc, char** argv) {
	if(argc < 2) {
		printf("write `was --help` in order to read help list\n");
		goto err_leave;
	} else {
		startWork(argc, argv);
		}
	//printf("%d\n", linesAmount(argv[1]));

err_leave:

	return 0;
	}
