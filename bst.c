/*****************************************************************************/
//BINARY SEARCH TREE LOGIC
/*****************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"
#include "bst1.h"
#include "bst2.h"
#include "structure.h"

/*****************************************************************************/

/*making a new node.*/
record *makeNode(){

  record *curr = (record*)malloc(sizeof(record));

  curr->left = NULL;
  curr->right = NULL;
  curr->next = NULL;

  return curr;
}


/*making a linked list if it is the same key and inserting into a linked list.*/
record *insertLinkedList(record *list_head, record *curr_node){

  record *temp = list_head;

  while (temp->next) {
      temp = temp->next;
    }

    temp->next = (record *)malloc(sizeof(record));
    copy_node(temp->next, curr_node);

    return list_head;
}


/*printing the linked list*/
void print_list(record *list_head, FILE* output_file) {

    while (list_head) {
        print_node(list_head, output_file);

        list_head = list_head->next;
    }
}


/*freeing linked list*/
void freeLinkedList(record *list_head) {

  while (list_head) {
    record *temp = list_head;
    list_head = list_head->next;

    free(temp);
  }
}


/*freeing roots pf the tree.*/
void free_root(record *root) {

  if (!root) return;

  free(root->left);
  free(root->right);

  freeLinkedList(root);
}


/*copying information of a node to another.*/
void copy_node(record *copy_to, record *copy_from){
    strcpy(copy_to->VendorID, copy_from->VendorID);
    strcpy(copy_to->passenger_count, copy_from->passenger_count);
    strcpy(copy_to->trip_distance, copy_from->trip_distance);
    strcpy(copy_to->RatecodeID, copy_from->RatecodeID);
    strcpy(copy_to->store_and_fwd_flag, copy_from->store_and_fwd_flag);
    strcpy(copy_to->PULocationID, copy_from->PULocationID);
    strcpy(copy_to->DOLocationID, copy_from->DOLocationID);
    strcpy(copy_to->payment_type, copy_from->payment_type);
    strcpy(copy_to->fare_amount, copy_from->fare_amount);
    strcpy(copy_to->extra, copy_from->extra);
    strcpy(copy_to->mta_tax, copy_from->mta_tax);
    strcpy(copy_to->tip_amount, copy_from->tip_amount);
    strcpy(copy_to->tolls_amount, copy_from->tolls_amount);
    strcpy(copy_to->improvement_surcharge, copy_from->improvement_surcharge);
    strcpy(copy_to->total_amount, copy_from->total_amount);
    strcpy(copy_to->PUdatetime, copy_from->PUdatetime);
    strcpy(copy_to->DOdatetime, copy_from->DOdatetime);
    strcpy(copy_to->trip_duration, copy_from->trip_duration);
}

/*****************************************************************************/
