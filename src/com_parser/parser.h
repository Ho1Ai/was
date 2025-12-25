#ifndef COMMAND_PARSER
#define COMMAND_PARSER

typedef enum {
	EAX, EBX, ECX, EDX, 
	} ParserRegisterListEnum;

typedef struct {
	char* name;
	ParserListEnum to_parsed;
	} PARSER_LIST[];

#endif
