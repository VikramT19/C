/***********************************
* Filename: arrayUnsorted.c 
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/

#include <stdio.h>

/*********  DO NOT CHANGE THESE CONSTANTS IN THE FINAL SUBMISSION *********/

#define MAX_SIZE 20
#define SUCCESS 0

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/
/* 
   Input: array A with "size" elements and an integer d
   Output: d is added to the array.
   Return 0 if the addition is successful.
   Return a negative number if the addition is unsuccessful.
   Error condition(s): fill in the error condition(s).
 */
 
int myAdd( int A[], int size, int d ) {
  
  if(size < MAX_SIZE) { // If size of array is less then the max size, array will add
    A[size] = d; //Adding the integer to the array
    return SUCCESS; //Return 0 if successful
  }

  else {
    return -1; //Return negative number if unsuccessful
  }
}


/* 
   Input: array A with "size" elements and an integer d
   Output: If d is found in the array, return the index of the cell containing d.
   Otherwise return a negative number if d is not found.
   Error condition(s): fill in the error condition(s).
 */
 
int search( int A[], int size, int d ) {
  
  int i; // Index variable
  
  for (i = 0; i < size; i++) { // For loop to go through array
    if(A[i] == d) { // If integer is found in array
      return i; // Return index of the integer
	  }  
  }
return -1; // Return negative number if d not found
}

/* 
   Input: array A with "size" elements and an integer d
   Output: Return a negative number if d is not found.
   Otherwise d is removed from the array and return 0.
   Error condition(s): fill in the error condition(s).
 */

int myRemove( int A[], int size, int d ) {
  
  int number = search(A,size,d); // Find the number
  int i; // Index variable
  
  if (number < 0) { // If d is not found
    return -1; // Return negative number
  }
  
  else {

    A[number] = A[size - 1]; // The cell of number will be replaced by the last number of the array
    
  return SUCCESS; // Return success 
  }
}


/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* 
   Input: array A with "size" elements
   Output: Display the array on the standard output with one space between every two numbers. 
   Print a new line after the last element.
   If the array is empty, print "Empty array" and a new line.
   Error condition(s): fill in the error condition(s).
 */

int printArray( int A[], int size )
{
  int i;
  if ( size == 0 )
    printf( "Empty array\n" );
  else {
  for ( i = 0; i < size; i++ )
     printf("%d ", A[ i ] );
  printf( "\n" );
  }
  return 0;
}

/* main() function 
 */
int main()
{
int myArray[MAX_SIZE];
int retCode, data, size;
char action;

size = 0;
do {
  scanf( "%d %c", &data, &action );
  switch( action )
  {
    case 'a': /* add */
    case  'A':
      retCode = myAdd( myArray, size, data );
      if ( retCode == SUCCESS ) {
        size++;		// increment size after successful addition
        printArray( myArray, size ); 
      }
      else
        printf( "Failed to add %d.\n", data );  
      break; 
        
    case 'r': /* remove */
    case 'R':
      retCode = myRemove( myArray, size, data );
      if ( retCode == SUCCESS ) {
        size--;		// decrement size after successful removal
        printArray( myArray, size ); 
      }
      else
        printf( "Failed to remove %d.\n", data );    
      break;  
                    
    case 's': /* search */
    case 'S':
      retCode = search( myArray, size, data );
      if( retCode >= 0 )
        printf( "Found %d at index %d.\n", data, retCode );
      else 
        printf( "Not found %d.\n", data );        
      break;
      
    case 'q':  /* quit */
    case 'Q':
      /* To quit, enter an arbitrary integer and character (action) 'q' or 'Q'.
         This is not elegant but makes the code simpler.  */  
      /* Do nothing but exit the switch statement */
      break; 
    
    default:
      printf( "Invalid operation %c\n", action );  
  }
} while ( action != 'q' && action != 'Q' );

return 0; 
} // end main