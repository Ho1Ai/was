#ifndef COMMAND_PARSER
#define COMMAND_PARSER
#include "../globalStructures/full_public.h"
/*
typedef enum {
	AH, AL, BH, BL, 
	CH, CL, DH, DL,
	AX, BX, CX, DX,
	EAX, EBX, ECX, EDX,
	CS, DS, ES, SS,
	SP, SI, IP, ESI,
	EIP
	} REGISTER_LIST;
*/
/*
typedef struct {
	char* name
	ParserListEnum to_parsed;
	} Mnemonic;
*/
/*
typedef enum {
	LABEL, INSTRUCTION
	} MN_TYPE;

typedef struct {
	MN_TYPE
	} ParserMn;

typedef struct {
	ParserMn* parser_mn_list;
	} ParserOutput;
*/

typedef enum { 
	PE_INSTRUCTION, PE_DIRECTIVE, PE_LABEL, PE_FATAL_ERROR
	} ParserEntryType; 

typedef enum {
	OP_REGISTER,
	OP_LABEL,
	OP_MEMORY,
	OP_IMMED
	} OperandType;

typedef enum { 
	AH, AL, BH, BL, 
	CH, CL, DH, DL, 
	AX, BX, CX, DX, 
	EAX, EBX, ECX, EDX, 
	CS, DS, ES, SS, 
	SP, BP, SI, IP, 
	ESI, ESP, EBP, EIP,
	DI, EDI, FS, GS // hope, that's all I have to use 
	} RegisterList; 

typedef struct { 
	OperandType operand_type; 
	union{ 
		int immed_number; 
		RegisterList reg;
		// memory is still not ready
		}; 
	} EntryOperand; 

typedef struct { 
	ParserEntryType pe_type;
	union{
		struct {
			int opcode;
			EntryOperand ops[3];
			int operands_amount;
			} instruction; 

		struct {
			char* name;
			} label;

		struct {
			char* name;
			} directive;
		}; 
	} ParserEntry; 

typedef struct { 
	ParserEntry* parser_content; 
	int length; 
	int cap; 
	} ParserOutput;

#endif
