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
void swap ( struct studentNode **start, int A, int B );

int main() {
 int A;
 int B;
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, "One", 6, 'M', 3.11 ) ;  
 now = AddNode( &start, "Two", 8, 'F', 3.22 ) ;  
 now = AddNode( &start, "Three", 10, 'M', 3.33 ) ; 
 now = AddNode( &start, "Four", 12, 'F', 3.44 ) ; 
 
 printf("before : ");
 now = AddNode( &start, "Five", 8, 'M', 3.55 ) ; ShowAll( start ) ;
	
 while( 1 ){
 	
 	printf("\nSwap Node ? : ");
 	scanf("%d",&A);
 	
		 
 	printf("\nAND Node ? : ");
 	scanf("%d",&B);
 	
 		if(B >= 1 && B <= 5 && A >= 1 && A <= 5){
			break;
 		}else{
 			printf("Can't do (have 5 Node)");
		}
 }	 
 
 printf( "After swap : " ) ;
 swap( &start, A, B );ShowAll( start ) ;
 
 return 0 ;
 
}//end main

void ShowAll( struct studentNode *walk ) {
	
 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
  
 }//end while
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

void swap ( struct studentNode **start, int A, int B ){
	if( *start == NULL || ( *start )->next == NULL ) {
		printf( "Empty node or less then one node.\n" ) ;
		return ;
	}
	
	if( A == B ) {
		printf( "Can't swap it same position \n" ) ;
		return ;
	}
	
	struct studentNode *BeforeA = NULL, *AfterA = *start ;
	struct studentNode *BeforeB = NULL, *AfterB = *start ;
	
	for( int i = 1 ; AfterA != NULL && i < A ; ++i ) {
		BeforeA = AfterA ;
		AfterA = AfterA->next ;
	}
	
	for( int i = 1 ; AfterB != NULL && i < B ; ++i ) {
		BeforeB = AfterB ;
		AfterB = AfterB->next ;
	}
	
	if( BeforeA != NULL ) {
		BeforeA->next = AfterB ;
	} else {
		*start = AfterB ;
	}
	
	if( BeforeB != NULL ) {
		BeforeB->next = AfterA ;
	} else {
		*start = AfterA ;
	}
	
	struct studentNode *temp = AfterA->next ;
	AfterA->next = AfterB->next ;
	AfterB->next = temp ;
	
	if( AfterA == NULL || AfterB == NULL ) {
		printf( "Error.\n" ) ;
		return ;
	}
	
}


