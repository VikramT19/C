/***********************************
*
* Filename: listMain.c	  	
* 
************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Function prototypes */
List *init( );
void prtList( );
List *insertFirst( int d );
List *insertLast( int d );
int removeFirst( );
List *search( int k );

int main()
{
   List *p;
   int i;

   if ( (p = (List *) init()) == NULL )
	exit( 1 );

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) insertLast( i*5 )) == NULL )
	   exit( 1 );
	prtList();
   }

   while ( removeFirst() > 0 )
      	prtList();

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) insertFirst( i*5 )) == NULL )
	   exit( 1 );
	prtList();
   }

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = (List *) search( i*4 )) )  
	   printf( "search %d found %d\n", i*4, p->data );
	else
	   printf( "search %d not found\n", i*4 );
   }
   
   return 0;
}


