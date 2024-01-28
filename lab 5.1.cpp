#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[20] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **walk, char *name, int age, char sex, float gpa );
void InsertNode( struct studentNode *now, char *name, int age, char sex, float gpa );
void DelNode( struct studentNode *now );

int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsertNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsertNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 DelNode( now ) ; ShowAll( start ) ;
 return 0 ;
}//end main

void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end showAll

struct studentNode *AddNode( struct studentNode **walk, char *name, int age, char sex, float gpa ){
	
	while( *walk != NULL){
		walk = &(( *walk )->next);
	}
	
	*walk = new struct studentNode;
	strcpy( ( *walk )->name, name ) ;
	( *walk )->age = age;
	( *walk )->sex = sex;
	( *walk )->gpa = gpa;
	( *walk )->next = NULL ;
	
	return *walk;
	
}//end AddNode

void InsertNode( struct studentNode *now, char *name, int age, char sex, float gpa ) {
	
	struct studentNode *Node = new struct studentNode;
    strcpy( Node->name, name ) ;
    Node->age = age ;
    Node->sex = sex ;
    Node->gpa = gpa ;
    Node->next = now->next ;  
    now->next = Node ;  
	
}//end InsertNode

void DelNode( struct studentNode *now ){
	
	struct studentNode *temp = now->next;
    now->next = temp->next;
    delete temp ;
    
}//end DelNode

