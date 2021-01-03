/***********************************
* Filename: strg.c 
* Author: Thangavel, Vikram
* Email: vikram19@my.yorku.ca
* Login ID: vikram19
************************************/

#include <stdio.h>
#define MAX_LENGTH 100   // DO NOT CHANGE THIS CONSTANT

/******************  YOUR CODE STARTS HERE ******************/
/************************************************************/

/*
 * Input: non-empty string s
 * Output: return the length of s
 */ 
int strgLen( char s[ ] ) {
  
  int length = 0; // Variable for length of string
  int i; // Index variable

  for (i = 0; s[i] != '\0'; i++) { // For loop to go through string; At the end of a string, there is always a null character by default which is '\0' so, when this is found, for loop will exit
    length = length + 1; // Increment of variable every time there is a character
  }
  
  return length; // Return length of string
}

/*
 * Input: non-empty string s
 * Output: copy the content of string s to string dest
 */ 
int strgCopy( char s[ ], char dest[ ] ) {
  
  int i; // Index variable
  
  for (i = 0; s[i] != '\0'; i++) { // For loop to go through string; At the end of a string, there is always a null character by default which is '\0' so, when this is found, for loop will exit
    dest[i] = s[i]; // Each character in the s string is copied to dest string
  }

  dest[i] = '\0'; // After string is copied, null character must be added at the end to initiate the end of string
  
  return 0;
}

/*
 * Input: non-empty string s
 * Output: for each character in string s, if it is an alphabet, reverse the  
 * case of the character.  Keep the non-alphabet characters as is.  
 */ 
int strgChangeCase( char s[ ] ) {

  int i; // Index variable

  for (i = 0; s[i] != '\0'; i++) { // For loop to go through string

    if(s[i] >= 'a' && s[i] <= 'z') { // If the character is in between a & z, it will substract 32 since the ASCII value of a lower case alphabet is 97 to 122 and the difference to the upper case character is 32. So, for example, to make 'a' to 'A', we substract 32 from 97 to get 65 which is 'A'.
      s[i] = s[i] - 32; // Changing the case to upper case
    }

    else if (s[i] >= 'A' && s[i] <= 'Z') { // In this case, we have to add 32 since the difference is again 32. For example, to go from 'A' to 'a', it would have to change from 65 to 97 which is 32. 
      s[i] = s[i] + 32; // Changing the case to lower case
    }

  }
  return 0;
}


/*
 * Input: non-empty strings s1 and s2
 * Output: Return the index where the first difference occurs.
 * Return -1 if the two strings are equal.
 */ 
int strgDiff( char s1[ ], char s2[ ] ) {

  int i = 0; // Index Variable
  int index; // Index where character is different
  int different = 0; // Variable to declare if the strings were equal or not
  int length = strgLen(s1); // Length of s1 string
  
  for (i = 0; i < length; i++) { // For loop to go through strings

    if(s1[i] != s2[i]) { // If index of s1 and s2 are not the same
       index  = i; // Index is assigned with the location of difference
        different = 1; // Variable is assigned with 1 to declare strings are not equal
       break; // Exits loop
    }
  }
  
  if (different != 0 ) { // If different is not equal to 0, it means strings are different
    return index; // Returns the index where character was different
  }

  else { // Otherwise, if strings are equal
    return -1; // Returns -1
  }

}


/*
 * Input: non-empty strings s1 and s2
 * Output: copy s1 and s2 to s3, interleaving the characters of s1 and s2.  
 * If one string is longer than the other, after interleaving, copy the rest 
 * of the longer string to s3.  
 */
int strgInterleave( char s1[ ], char s2[ ], char d[ ] ) {

  int number; // Max number used for interleave
  int len1 = strgLen(s1); // Length of first string
  int len2 = strgLen(s2); // Length of second string
  int i = 0; // Index variable for d; Used for first for loop
  int j = 0; // Index variable for s1 and s2 // Used to assign the index for the strings
  int k = 0; // Index variable used for for loop to iterate the left over characters

// Find the the max number that can merge

  if (len1 <= len2) { // If the length of first string is smaller than second string
    number = len1; // Assigns the first string's length to a variable 
  }

  else if (len2 < len1) {  // If the length of second string is smaller than first string
    number = len2; // Assigns the second string's length to a variable
  }

// Merging strings until both strings are equal and one of them has a index of '\0' located
    
  for (i = 0; i < number*2; i++) { // For loop to merge both strings until number is met
      if (i % 2 == 0) {  // If the index is a even position (number)
        d[i] = s1[j]; // Assigns the position
      }
      
      else if (i % 2 != 0) { // If the index is a odd position (number)
        d[i] = s2[j++]; // Assigns the position
      }
  }

// Iterate the left over of the merge of the two strings

   if (len1 < len2) { // If length of first string is smaller than the second string

    for(k = 0; k < (len2 - number); k++) { // Adding the left over numbers
      d[(number*2) + k] = s2[len1 + k]; // Assigns the numbers to the positions after merge
    }

  }

  else if (len2 < len1) { // If the length of second string is smaller then the first string

    for (k = 0 ; k < (len1 - number); k++) { // Adding the left over numbers
      d[(number*2) + k] = s1[len2 + k];  // Assigns the numbers to the position after merge
    }
    
  }
  
  d[(number*2) + k] = '\0'; // Adding the null character to the end of the string
  return 0;
}

/*******************  YOUR CODE ENDS HERE *******************/
/************************************************************/

/*********  DO NOT CHANGE ANYTHING BELOW THIS LINE IN THE FINAL SUBMISSION *********/

/* main() function 
 */
int main()
{
  char op[ MAX_LENGTH ]; 
  char str1[ MAX_LENGTH ]; 
  char str2[ MAX_LENGTH ];
  char str3[ MAX_LENGTH ];  
  int index;
  
  do {
    scanf( "%s %s", op, str1 );
    switch( op[ 0 ] )
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
      printf( "Invalid operation %c\n", op[0] );         
    }  // end switch
  } while ( op[ 0 ] != 'q' && op[ 0 ] != 'Q' );
  
  return 0;
}

