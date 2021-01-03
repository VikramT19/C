/***********************************
* Filename: dlist.c
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

/* Two dummy nodes that keeps track of the front and the rear of the list */

DList *head, *tail;

/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}


/* Create an empty list. */
/* Create two dummy nodes to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the 2 dummy nodes. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node "head". */

DList *init( )
{
   head = ( DList * ) malloc( sizeof( DList ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   }
   
   tail = ( DList * ) malloc( sizeof( DList ) );
   if ( tail == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   } 
     
   head->data = -1;
   tail->data = -1;   
   head->next = tail;
   head->prev = NULL;  
   tail->next = NULL; 
   tail->prev = head;
   return ( head );  /* indicates no error */ 
}


/* Return the content (data) of the first element right behind the dummy node. */
/* Return -1 if the list is empty. */

int getFirst()
{
   if ( head->next != tail )	// non-empty list
      return( head->next->data );
   else							// empty list
      return -1;
}


/* Return the content (data) of the last element right in front of dummy node "tail" */
/* Return -1 if the list is empty. */

int getLast()
{
   if ( head->next != tail )	// non-empty list
      return( tail->prev->data );
   else							// empty list
      return -1;
}


/* Print the content of the list (ignoring the dummy node). */

void prtList( )
{
   DList *p;
   for ( p = head->next; p != tail; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node "head". */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

DList *insertFirst( int d ) { // Insert node in front of head node
  DList *insert = (DList*) malloc(sizeof(DList)); // New node and allocating its memory
  if(!insert) { // If new node can't be created
    prtError("Insufficient memory!"); // Error message is printed
    return (NULL); // Returns null
  } else { // Else statement
      insert->data = d; // Element's value is added to data part of node
      insert->next = head->next; // Make next of new node as next of head node
      head->next = insert; // Make next of head node as the new node
      insert->prev = head; // Make previous of new node as head Node
      if(insert->next != NULL){ // If next of new node is not null
        insert->next->prev = insert; // Previous of new node's next node is changed
      } // End of if statement
    } // End of else statement
  return insert; // Node is returned
} // End of function

/* Insert a new data element d into the list. */
/* Insert at the rear of the list, right in front of the dummy node "tail". */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

DList *insertLast( int d ) { // Node is added before tail node
  DList *insert = (DList*) malloc(sizeof(DList)); // New node and allocating its memory
  if(!insert) { // If new node can't be created
    prtError("Insufficient memory!"); // Error message is printed
    return (NULL); // Returns null
  } else {
      insert->data = d; // Element's value is added to data part of node
      insert->prev = tail->prev; // Previous of new node is made as previous of tail node
      tail->prev = insert; // Previous of tail node is made as new node
      insert->next = tail; // Next of new node is made as tail node
      if (insert->prev != NULL) { // If previous of new node is not null
        insert->prev->next = insert; // Next of new node's previous is changed
      } else { // Else
          head = insert; // Head node is the new node 
        } // End of else statement
    } // End of else statement
  return insert; // Node is returned
} // End of function

/* Remove the first element of the list, the node right behind the dummy node "head". */
/* Return -1 if the list is empty, i.e., containing only the two dummy nodes, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be removed. */

int removeFirst() { // Remove node behind head node
DList *node; //Node to remove
  int remove; // Data of node
  if (head->next == tail) { // If list is empty (Only dummy nodes)
    prtError("Empty list!"); // Error message is printed
    return -1; // -1 is returned
  } else { // Else statement
      node = head; // Node made as head
      head = head->next; // Head is made as next of head
      remove = head->data; // Data of node is assigned
      free(node); // Node is freed
    } // End of else statement
  return remove; // Data of removed node is returned
}

/* Remove the last element,  the node right in fromt of the dummy node "tail". */
/* Return -1 if the list is empty, i.e., containing only the two dummy nodes, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be removed. */

int removeLast() { // Remove node before tail node
  int remove = tail->prev->prev->next->data; // Data of removed node
  if (head->next == tail) { // If list is empty (Only dummy nodes)
    prtError("Empty list!"); // Error message is printed
    return -1; // -1 is returned
  } else { // Else statement
      tail->prev->prev->next = tail; // Tail's previous previous next pointer points to Tail node
      tail->prev = tail->prev->prev; // Previous of tail is made as previous's previous of tail
      // Pointer to second last node is gone (Node is removed)
    } // End of else statement
    return remove; // Return data of removed node
} // End of function

/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

DList *search( int k ) { // Searches list for node with k as data
  DList *current = head->next; // First node of list
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
