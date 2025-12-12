typedef struct {
	char** content;
	size_t len;
	
	} WorkingInstance;

typedef struct {
	WorkingInstace instances;
	char* final_name;
	int name_free_need;
	} WorkState;

