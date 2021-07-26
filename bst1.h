typedef struct Record record;

/*****************************************************************************/
//FUNCTION PROTOTYPES FOR DICT1
/*****************************************************************************/

record * construct_tree(record *root, char* file_name);

record *insertTree(record *root, record *curr_node);

void print_node(record *node, FILE *output_file);

void search_tree(record *root, char *string, char *output, int* comparisons);

/*****************************************************************************/
