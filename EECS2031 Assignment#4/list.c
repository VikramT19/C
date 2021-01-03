/***********************************
* Filename: list.c
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *head, *tail;


/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}


/* Create an empty list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node. */

List *init( )
{
   head = ( List * ) malloc( sizeof( List ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   }
   head->data = -1;
   head->next = NULL;
   tail = head;
   return ( head );
}


/* Return the content (data) of the first element right behind the dummy node. */
/* Return -1 if the list is empty. */

int getFirst()
{
   if ( head != tail )	// non-empty list
      return( head->next->data );
   else					// empty list
      return -1;
}


/* Return the content (data) of the last element at the rear of the list. */
/* Return -1 if the list is empty. */

int getLast()
{
   if ( head != tail )	// non-empty list
      return( tail->data );
   else					// empty list
      return -1;
}


/* Print the content of the list (ignoring the dummy node). */

void prtList( )
{
   List *p;
   for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertFirst( int d ) { // Insert new element at the front of list

  List *insert = (List*) malloc(sizeof(List)); // New node and allocating its memory
  
  if(!insert) { // If new node can't be created
    prtError("Insufficient memory!"); // Error message is printed
    return (NULL); // Returns null
  } // End of if statement 

  else { // Otherwise

    insert->data = d; // Element's value is added to data part of node

    if(!head) { // If list is empty
      head->next = insert; // Connects head node to insert node
      insert->next = tail; // Connects insert node to tail node
    } // End of if statement
    
    else { // Else statement (If list is not empty)
      insert->next = head->next; // Assigns pointer as first node
      head->next = insert; // Connects node to insert node
    } // End of else statement 
    
    return insert; // Returns pointer of insert node
  } // End of big else statement
} // End of function


/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertLast( int d ) { // Insert new element at the end of the list
  
  List *insert = (List*) malloc(sizeof(List)); // New node and allocating its memory
  List *temp = head; // Temp node

  if(!insert) { // If node can't be created
    prtError("Insufficient memory!"); // Error message is printed
    return (NULL); // Returns NULL
  } // End of if statement

  else { // Otherwise

    insert->data = d; // Element is added to the data part of the node

    if(!head) { // If list is empty
      head->next = insert; // Connects node to insert node
      tail = insert; // Last node becomes insert node
    } // End of if statement

    else { // Else statement

      while(temp->next != NULL) { // While loop until node becomes last node
        temp = temp->next; // Assigns node's address
      }

      temp->next = insert; // Connects node with insert node
      tail = insert; // Last node becomes insert node
    } // End of else statement 

    return insert; // Pointer of node is returned
  } // End of big else statement
} // End of function


/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* Return -1 if the list is empty, i.e., containing only the dummy node, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be remove. */

int removeFirst() { // Removes first element of the list

  List *node; // Creation of node
  int remove; // Data of removed node
  
  if (head == tail) { // If list is empty
    prtError("Empty list!"); // Error message is printed
    return -1; // -1 is returned
  } // End of if statement

  else { // Otherwise
    node = head; // Node is assigned as first node of list
    head = head->next; // Assigns pointer as first node

    remove = head->data; // Data of node is assigned to variable
    free(node); // Node is removed from list
    
    return remove; // Data of removed node is returned
  } // End of else statement
} // End of function 


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

List *search( int k ) { // Search node with k value
  
  List *current = head->next; // First node of list
  int pointer = 0; // Checking if a element contains k (flag)

  while(current != NULL) { // While loop until node equals null

    if(current->data == k) { // If the node's data equals k value
      pointer = 1; // Contains k (flagged)
      return current; // Pointer of element is returned
    } // End of if statement 

    current = current->next; // Node is linked
  } // End of while loop

  if(pointer == 1) { // If it's flagged
    return current; // The pointer is returned
  } // End of if statement

  else { // Otherwise
    return (NULL); // NULL is returned
  } // End of else statement

} // End of function


/*************************** END OF FILE ***************************/

