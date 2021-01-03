/***********************************
*
* Filename: dmain.c	  	
* 
************************************/

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int main()
{
   DList *p;
   int i;

   if ( (p = init()) == NULL )
	exit( 1 );

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = insertLast( i*5 )) == NULL )
	   exit( 1 );
	prtList();
   }

   while ( removeFirst() > 0 )
      	prtList();

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = insertFirst( i*5 )) == NULL )
	   exit( 1 );
	prtList();
   }

   while ( removeLast() > 0 )
      	prtList();

   for ( i = 1; i <= 10; i++ ) {
	if ( (p = insertFirst( i*10 )) == NULL )
	   exit( 1 );
	prtList();
   }
   
   for ( i = 1; i <= 10; i++ ) {
	if ( ( p = search( i*5 )) )  
	   printf( "search %d found %d\n", i*5, p->data );
	else
	   printf( "search %d not found\n", i*5 );
   }
     	   	        
   return 0;
}
	