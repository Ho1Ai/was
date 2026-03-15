#ifndef COMMAND_PARSER
#define COMMAND_PARSER

typedef enum {
	AH, AL, BH, BL, 
	CH, CL, DH, DL,
	AX, BX, CX, DX,
	EAX, EBX, ECX, EDX,
	CS, DS, ES, SS,
	SP, SI, IP, ESI,
	EIP
	} REGISTER_LIST;

/*
typedef struct {
	char* name
	ParserListEnum to_parsed;
	} Mnemonic;
*/

typedef enum {
	LABEL, INSTRUCTION
	} MN_TYPE;

typedef struct {
	MN_TYPE
	} ParserMn;

typedef struct {
	ParserMn* parser_mn_list;
	} ParserOutput;

#endif
