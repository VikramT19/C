/*********************************** 
*
* Filename: dlist.h	 
* 	
************************************/

/* Doubly linked list node */
typedef struct dlist {
   int data;
   struct dlist *next;
   struct dlist *prev;  
} DList;

/* Function prototypes */
void prtError( char *s );
DList *init( );
int getFirst();
int getLast();
void prtList( );
DList *insertFirst( int d );
DList *insertLast( int d );
int removeFirst( );
int removeLast( );
DList *search( int k );



