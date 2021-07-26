typedef struct Record record;

/*****************************************************************************/
//FUNCTION PROTOTYPES
/*****************************************************************************/

record *makeNode();

record *insertLinkedList(record *list_head, record *curr_node);

void print_list(record *list_head, FILE* output_file);

void freeLinkedList(record *list_head);

void free_root(record *root);

void copy_node(record *copy_to, record *copy_from);

/*****************************************************************************/
