/*****************************************************************************/
//BINARY SEARCH TREE LOGIC FOR DICT2
/*****************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"
#include "bst2.h"
#include "structure.h"

/*****************************************************************************/

/*tree construction.*/
record *construct_tree(record *root, char* file_name){

  FILE *input = fopen(file_name, "r");
  assert(input);

  char buffer[MAX_LINE];

  while (fgets(buffer, MAX_LINE, input)) {
    char *token;
    record *curr = makeNode();

    /*check if token has ','- seperate.*/
    token = strtok(buffer, ",");

    /*copying value into a new node that is to be inserted to a tree.*/
    strcpy(curr->VendorID, token);
    token = strtok(NULL, ",");

    strcpy(curr->passenger_count, token);
    token = strtok(NULL, ",");

    strcpy(curr->trip_distance, token);
    token = strtok(NULL, ",");

    strcpy(curr->RatecodeID, token);
    token = strtok(NULL, ",");

    strcpy(curr->store_and_fwd_flag, token);
    token = strtok(NULL, ",");

    strcpy(curr->PULocationID, token);
    token = strtok(NULL, ",");

    strcpy(curr->DOLocationID, token);
    token = strtok(NULL, ",");

    strcpy(curr->payment_type, token);
    token = strtok(NULL, ",");

    strcpy(curr->fare_amount, token);
    token = strtok(NULL, ",");

    strcpy(curr->extra, token);
    token = strtok(NULL, ",");

    strcpy(curr->mta_tax, token);
    token = strtok(NULL, ",");

    strcpy(curr->tip_amount, token);
    token = strtok(NULL, ",");

    strcpy(curr->tolls_amount, token);
    token = strtok(NULL, ",");

    strcpy(curr->improvement_surcharge, token);
    token = strtok(NULL, ",");

    strcpy(curr->total_amount, token);
    token = strtok(NULL, ",");

    strcpy(curr->PUdatetime, token);
    token = strtok(NULL, ",");

    strcpy(curr->DOdatetime, token);
    token = strtok(NULL, ",");

    strcpy(curr->trip_duration, token);
    token = strtok(NULL, ",");
    /*ending it with '\0'.*/
    curr->trip_duration[strlen(curr->trip_duration) - 1] = '\0';

    root = insertTree(root, curr);
  }
    fclose(input);

    return root;
}


/*inserting node into a tree.*/
record *insertTree(record *root, record *curr_node) {

    if (!root){

      root = makeNode();
      copy_node(root, curr_node);
    }

     else if (strcmp(curr_node->PULocationID, root->PULocationID) > 0) {

      root->right = insertTree(root->right, curr_node);
    }

    else if (strcmp(curr_node->PULocationID, root->PULocationID) < 0) {

      root->left = insertTree(root->left, curr_node);
    }
    else {

      root = insertLinkedList(root, curr_node);
    }

    return root;
}


/*searching PULocationID in the tree.*/
void search_tree(record *root, char *string, char *output, int* comparisons){

  FILE *output_file = fopen(output, "a+");

  int num_comparisons = 0;
  int found = 0;

  /*loop to check all roots.*/
  while(root != NULL){

    /*comparing between stdin and root's PULocationID.*/
    if(strcmp(string, root->PULocationID) == 0){
      num_comparisons+=1;
      found = 1;

      /*printing to node to output file and iterating the root in the linked list.*/
      while(root != NULL){

        print_node(root, output_file);
        root = root->next;
      }

      printf("%s --> %d\n", string, num_comparisons);
      *comparisons += num_comparisons;
      return;
    }

    /*shifting root to left or right based on the PULocationID.*/
    else if(strcmp(string, root->PULocationID) < 0){
      root = root->left;
      num_comparisons++;
      continue;
    }

    else{
      root = root->right;
      num_comparisons++;
      continue;
    }
  }

  *comparisons += num_comparisons;

  /*if nothing found.*/
  if(found == 0){
    fprintf(output_file, "%s --> NOTFOUND\n", string);
  }

  /*print to stdout.*/
  printf("%s -->%d\n", string, num_comparisons);
  fclose(output_file);
}


/*printing node*/
void print_node(record *node, FILE *output_file){

    fprintf(output_file, "%s --> %s\n ", node->PULocationID, node->PUdatetime);
}

/*****************************************************************************/
