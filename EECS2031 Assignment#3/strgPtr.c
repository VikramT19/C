/***********************************
* Filename: strgPtr.c 
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100   // DO NOT CHANGE THIS CONSTANT

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/*
 * Input: non-empty string s
 * Output: return the length of s
 */ 
int strgLen( char *s ) { // Getting length of string

  int length = 0; // Counter for number of characters in string (length)

  while (*s != '\0') { // While loop; loops until the null character is found
    length = length + 1; // Increment of the counter
    s = s + 1; // Increment of the string index
  } // End of while loop

   return length; // Returns the length of the string
} // End of function

/*
 * Input: non-empty string s
 * Output: copy the content of string s to string dest
 */ 
int strgCopy( char *s, char *dest ) { // Copy a string to another

  while (*s != '\0') { // While loop; loops until the null character is found
    *dest = *s; // Each character is copied
    s = s + 1; // Increment of string index
    dest = dest + 1; // Increment of copied string index
  } // End of while loop
  
   return 0;
} // End of function

/*
 * Input: non-empty string s
 * Output: for each character in string s, if it is an alphabet, reverse the  
 * case of the character.  Keep the non-alphabet characters as is.  
 */ 
int strgChangeCase( char *s ) { // Change case of a string

  int i = 0; // Declaration of index variable

  while (*(s+i) != '\0') { // While loop; loops until null character is found

    if (*(s+i) >= 'a'  && *(s+i)<= 'z') { // If the character located is a lowercase character
      *(s+i) = *(s+i) - 32; //  According to the ASCII, 32 will be subtracted to make uppercase
    } // End of if statement 

    else if (*(s+i) >= 'A'  && *(s+i)<= 'Z') { // If the character located is a uppercase character
      *(s+i) = *(s+i) + 32; // 32 must be added to make lowercase
    } // End of else if statement

    i++; // Increment of index variable

  } // End of while loop
   return 0;
} // End of function

/*
 * Input: non-empty strings s1 and s2
 * Output: Return the index where the first difference occurs.
 * Return -1 if the two strings are equal.
 */ 
int strgDiff( char *s1, char *s2 ) { // Find the index where string difference occurs

  int i = 0; // Index Variable
  int index; // Index where character is different
  int different = 0; // Variable to declare if the strings were equal or not
  int length = strgLen(s1); // Length of s1 string
  
  for (i = 0; i < length; i++) { // For loop to go through strings
  
    if(*(s1 + i) != *(s2 + i)) { // If index of s1 and s2 are not the same
      index  = i; // Index is assigned with the location of difference
      different = 1; // Variable is assigned with 1 to declare strings are not equal
      break; // Exits loop
    } // End of if statement
  } // End of for loop
  
  if (different != 0 ) { // If different is not equal to 0, it means strings are different
    return index; // Returns the index where character was different
  } // End of if statement

  else { // Otherwise, if strings are equal
    return -1; // Returns -1
  } // End of else statement
  
   return 0;
} // End of function


/*
 * Input: non-empty strings s1 and s2
 * Output: copy s1 and s2 to s3, interleaving the characters of s1 and s2.  
 * If one string is longer than the other, after interleaving, copy the rest 
 * of the longer string to s3.  
 */
int strgInterleave( char *s1, char *s2, char *d ) { // Interleave of two strings

  int number; // Max number used for interleave
  int len1 = strgLen(s1); // Length of first string
  int len2 = strgLen(s2); // Length of second string
  int i = 0; // Index variable for d; Used for first for loop
  int j = 0; // Index variable for s1 and s2 // Used to assign the index for the strings
  int k = 0; // Index variable used for for loop to iterate the left over characters

// Find the the max number that can merge

  if (len1 <= len2) { // If the length of first string is smaller than second string
    number = len1; // Assigns the first string's length to a variable 
  } // End of if statement

  else if (len2 < len1) {  // If the length of second string is smaller than first string
    number = len2; // Assigns the second string's length to a variable
  } // End of else statement

// Merging strings until both strings are equal and one of them has a index of '\0' located
    
  for (i = 0; i < number*2; i++) { // For loop to merge both strings until number is met
      if (i % 2 == 0) {  // If the index is a even position (number)
        *(d + i) = *(s1 + j); // Assigns the position
      } // End of if statement
      
      else if (i % 2 != 0) { // If the index is a odd position (number)
        *(d + i) = *(s2 + j++); // Assigns the position
      } // End of else statement
  } // End of for loop

// Iterate the left over of the merge of the two strings

  if (len1 < len2) { // If length of first string is smaller than the second string

    for(k = 0; k < (len2 - number); k++) { // Adding the left over numbers
      *(d + (number*2) + k) = *(s2 + len1 + k); // Assigns the numbers to the positions after merge
    } // End of for loop

  } // End of if statement 

  else if (len2 < len1) { // If the length of second string is smaller then the first string

    for (k = 0 ; k < (len1 - number); k++) { // Adding the left over numbers
      *(d + (number*2) + k) = *(s1 + len2 + k);  // Assigns the numbers to the position after merge
    } // End of for loop
    
  } // End of else if statement
  
  *(d + (number*2) + k) = '\0'; // Adding the null character to the end of the string

  return 0;
} // End of function

/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* main() function 
 */
int main()
{
  char *op, *str1, *str2, *str3;
  int index;
  
  op = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str1 = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str2 = ( char* ) malloc ( MAX_LENGTH * sizeof( char ) );
  str3 = ( char* ) malloc ( 2 * MAX_LENGTH * sizeof( char ) );
  
  if( !op || !str1 || !str2 || !str3 ) {
    printf( "Memory allocation failed.\n" );
    exit( 1 );
  }
  
  do {
    scanf( "%s %s", op, str1 );
    switch( *op )
    {
    case 'l':   // length
    case 'L':
      printf( "%d\n", strgLen( str1 ) );
      break;
          
    case 'c':   // copy
    case 'C':
      strgCopy( str1, str2 );
      printf( "%s\n", str2 );
      break;
      
     case 'h':   // cHange case
     case 'H':
      strgChangeCase( str1 );
      printf( "%s\n", str1 );
      break;     
                
    case 'd':  // difference  
    case 'D':
      scanf( "%s", str2 );
      index = strgDiff( str1, str2 );
      if ( index < 0 )
        printf( "Equal strings\n" );
      else
        printf( "%d\n", index );      
      break;    
    
    case 'i':  // interleave
    case 'I':
      scanf( "%s", str2 );    
      strgInterleave( str1, str2, str3 );
      printf( "%s\n", str3 );      
      break;

    case 'q':  // quit
    case 'Q':
      /* To quit, enter character (action) 'q' or 'Q' and an arbitrary string.
         This is not elegant but makes the code simpler.  */  
      /* Do nothing but exit the switch statement */    
      break;
            
    default:  
      printf( "Invalid operation %c\n", *op );         
    }  // end switch
  } while ( *op != 'q' && *op != 'Q' );
  
  return 0;
}

