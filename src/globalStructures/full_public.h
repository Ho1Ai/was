#ifndef PUBLIC_STRUCTS
#define PUBLIC_STRUCTS

typedef struct {
	size_t adder;
	} ConfigState;

typedef struct {
	char** content;
	size_t len;
	} WorkingInstance;

typedef struct {
	WorkingInstance instances;
	ConfigState config_state;
	char* final_name;
	} WorkState;

#endif
