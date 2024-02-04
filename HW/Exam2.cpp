#include <stdio.h>
#include <string.h>

struct dNode {
 	int data;
 	struct dNode *back;
 	struct dNode *next;
} ;

struct dNode *AddNode( struct dNode **walk, int data );
void swapnode ( dNode **walk ,int data1,int data2 );
void ShowAll( struct dNode *walk );

int main() {
 
 struct dNode *start, *now ;
 start = NULL ;
 
 now = AddNode( &start, 10) ;  
 now = AddNode( &start, 20) ; 
 now = AddNode( &start, 30) ;
 now = AddNode( &start, 40) ; 
 now = AddNode( &start, 50) ; ShowAll( start ) ;
 
 printf("-------------------------\n");
 printf("After swap\n");
 swapnode(&start,10,30); ShowAll(start);
 swapnode(&start,20,20); ShowAll(start);
 swapnode(&start,20,40); ShowAll(start);
 swapnode(&start,10,50); ShowAll(start);
 swapnode(&start,50,50); ShowAll(start);
 swapnode(&start,50,30); ShowAll(start);
 printf("-------------------------");
 
 return 0 ;
 
}//end main

void ShowAll( struct dNode *walk ) {
	
 while( walk != NULL ) {
  printf( "%d ", walk->data ) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end showAll

struct dNode *AddNode( struct dNode **walk, int data ){
	
	struct dNode *temp = NULL;
	while( *walk != NULL){
		temp = *walk;
		walk = &(*walk)->next;
	}
	*walk =new struct dNode;
	(*walk)->data = data;
	(*walk)->next = NULL;
	(*walk)->back = temp;
	
	return *walk;
	
}//end AddNode

void swapnode ( dNode **walk ,int data1,int data2 ) {
	
	// data node1 equl(=) data in node2 exite fuction
	if( data1 == data2 ) {
		printf("!");
		return; 
	}
	
	// search data1 keep tranck in node1
	dNode *node1 = *walk;
	dNode *back1 = NULL ;
	while ( node1 && node1 -> data != data1 ) { 
		
		back1 = node1;
		node1 = node1 -> next;
	} 
	// end while
	
	// search data2 keep in node2
	dNode *back2 = NULL;
	dNode *node2 = *walk;
	while ( node2 && node2 -> data != data2 ) {
		
		back2 = node2;
		node2 = node2 -> next;
	}// end while
	
	if ( node1 == NULL || node2 == NULL ) {
		return;
	}
	
	if ( back1 != NULL ) {
		
		back1 -> next = node2;	
		
	}else{
		*walk = node2;
	}
	
	if ( back2 != NULL ){
		back2 -> next = node1; 
		
	}else{
		
		*walk = node1;
	}
	
	dNode *temp = node2 -> next;
	node2 ->next = node1 -> next;
	node1 ->next = temp;
	
}//end swapnode

