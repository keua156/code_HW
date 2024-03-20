#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
 struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa);
void InsNode( struct studentNode *walk, char *name, int age, char sex, float gpa );
void GoBack(struct studentNode **walk);
void DelNode( struct studentNode **walk);


int main() {
	
 struct studentNode *start , *now;
 start = NULL ; 
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 GoBack( &now ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 return 0 ;
}//end function

void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end function

struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa) {
    struct studentNode *Node = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(Node->name, name);
    Node->age = age;
    Node->sex = sex;
    Node->gpa = gpa;
    Node->next = NULL;
    Node->back = NULL;

    if (*start == NULL) {
        *start = Node;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = Node;
        Node->back = temp;
    }

    return Node;
}

void InsNode( struct studentNode *walk, char *name, int age, char sex, float gpa ) {
    
	struct studentNode *Node = new struct studentNode;
    	
    strcpy(Node->name, name);
    Node->age = age;
    Node->sex = sex;
    Node->gpa = gpa;

    if (walk != NULL) {
        Node->next = walk;
        Node->back = walk->back;
        if (walk->back != NULL) {
            walk->back->next = Node;
        }
        walk->back = Node;
    }
    
}
//end InsertNode

void DelNode( struct studentNode **walk){
	
	 struct studentNode *temp = *walk;

    if (temp->back != NULL) {
        temp->back->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->back = temp->back;
        *walk = temp->next;
    } else {
        *walk = temp->back;
    }

    delete temp;
}
    
    
//end DelNode

void GoBack(struct studentNode **walk) {
	
    if (*walk != NULL && (*walk)->back != NULL) {
        *walk = (*walk)->back;}
    }
