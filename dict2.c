/*****************************************************************************/
//Name: Girish Madnani
//StudentID: 934130
/*****************************************************************************/

/*****************************************************************************/
//STAGE 2
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "bst2.h"
#include "structure.h"

int main(int argc, char **argv){

  /*first and second words after the directory to run program for input and output*/
  char* file_name = argv[1];
  char* output = argv[2];

  char buffer[MAX_LINE];

  int comparisons = 0;

  record *root = NULL;

  /*constructing nodes and inserting them into a tree.*/
  root = construct_tree(root, file_name);

  while (fgets(buffer, MAX_LINE, stdin)) {

    /*removes the next line (i.e. newline) from stdin*/
    int len = strlen(buffer);

    if (len > 0 && buffer[len-1] == '\n') {
      buffer[--len] = '\0';
    }

    /*searching the tree for similar PULocationID.*/
    search_tree(root, buffer, output, &comparisons);
  }

  return 0;
}
