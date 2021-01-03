/***********************************
* Filename: arrayStruct.c
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/

#include <stdio.h>

/*********  DO NOT CHANGE THESE CONSTANTS IN THE FINAL SUBMISSION *********/

#define MAX_SIZE 20
#define SUCCESS 0

typedef struct {		// DO NOT CHANGE the struct definition
  int arr[MAX_SIZE];	// actual array for integers
  int size;				// number of integers in array
} Array;


/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/* 
   Input: array A with "size" elements and an integer d
   Output: d is added to the array.
   Return 0 if the addition is successful.
   Return a negative number if the addition is unsuccessful.
   Error condition(s): fill in the error condition(s).
 */
 
int myAdd( Array *myArr, int d ) { // Add integers to array
  
  int i; // Declaration of index variable
  
  if(myArr->size < MAX_SIZE) { // Checking if size of array is less than the max size, if so, array will add elements
  
    for (i = myArr->size-1; i >= 0 && myArr->arr[i] > d; i--) { // For loop to iterate through the array
    // Two conditions:
    // If the index is greater or equal to 0 & if the index is bigger than the number to insert  
      myArr->arr[i+1] = myArr->arr[i]; // Cell blocks are shifted in order to insert the number in sorted way
    } // End of for loop

    myArr->size = myArr->size+1; // The size of array is increased 
    myArr->arr[i+1] = d; // Now, the number can be inserted in the right location
   
    return SUCCESS; //Return 0 if successful
  } // End of if statement

  else { // Else statement
    return -1; //Return negative number if unsuccessful
  } // End of else statement

} // End of function


/* 
   Input: array A with "size" elements and an integer d
   Output: If d is found in the array, return the index of the cell containing d.
   Otherwise return a negative number if d is not found.
   Error condition(s): fill in the error condition(s).
 */
 
int search( Array *myArr, int d ) { // Search for array for number

  int i; // Declaration of index variable

  for (i = 0; i < myArr->size; i++) { // For loop to iterate through array

    if (myArr->arr[i] == d) { // If the number is found in the array
      return i;// Index of the number found will be returned
    } // End of if statement 

  } // End of for loop
   
   return -1; // Returns negative number if number not found
} // End of function

/* 
   Input: array A with "size" elements and an integer d
   Output: Return a negative number if d is not found.
   Otherwise d is removed from the array and return 0.
   Error condition(s): fill in the error condition(s).
 */

int myRemove( Array *myArr, int d ) { // Remove number from array

  int number  = search(myArr, d); // Number that we need to remove
  int i; // Declaration of index variable

  if (number < 0) { // If the number is not found
    return -1; // Negative number will be returned
  } // End of if statement

  else { // Else statement

    for (i = number; i < (myArr->size-1); i++) { // For loop to iterate from pocation number was found
      myArr->arr[i] = myArr->arr[i+1]; // Cell blocks are shifted
    } // End of for loop

    myArr->size = myArr->size-1; // Array size is decreased
    return SUCCESS; // Return 0 if removal is successful
  } // End of else statement
  
} // End of function


/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* 
   Input: array A with "size" elements
   Output: Display the array on the standard output with one space between every two numbers. 
   Print a new line after the last element.
   If the array is empty, print "Empty array" and a new line.
 */

int printArray( Array *myArr )
{
  int i;
  if ( myArr->size == 0 )
    printf( "Empty array\n" );
  else {
  for ( i = 0; i < myArr->size; i++ )
     printf("%d ", myArr->arr[ i ] );
  printf( "\n" );
  }
  return 0;
}



/* ***** main() function ******
 */
 
int main()
{
Array myArray;
int retCode, data;
char action;

myArray.size = 0;
do {
  scanf( "%d %c", &data, &action );
  switch( action )
  {
    case 'a': /* add */
    case  'A':
      retCode = myAdd( &myArray, data );
      if ( retCode == SUCCESS ) {
        printArray( &myArray ); 
      }
      else
        printf( "Failed to add %d.\n", data );  
      break; 
        
    case 'r': /* remove */
    case 'R':
      retCode = myRemove( &myArray, data );
      if ( retCode == SUCCESS ) {
        printArray( &myArray ); 
      }
      else
        printf( "Failed to remove %d.\n", data );    
      break;  
                    
    case 's': /* search */
    case 'S':
      retCode = search( &myArray, data );
      if( retCode >= 0 )
        printf( "Found %d at index %d.\n", data, retCode );
      else 
        printf( "Not found %d.\n", data );        
      break;
      
    case 'q':  /* quit */
    case 'Q':
      /* do nothing but exit the switch statement */
      break; 
    
    default:
      printf( "Invalid operation %c\n", action );  
  }
} while ( action != 'q' && action != 'Q' );

return 0; 
} // end main