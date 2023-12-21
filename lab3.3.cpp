#include <stdio.h>

struct student {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
} ;

struct student upgrade( struct student child ) ;

int main() {
	 struct student aboy ;
	 aboy.sex = 'M' ;
	 aboy.gpa = 3.00 ;
	 aboy = upgrade( aboy ) ;
	 printf( "from >> |%.2f|", aboy.gpa ) ;
	 
	
	 struct student agirl  ;
	 agirl.sex = 'F' ;
	 agirl.gpa = 2.00 ;
	 agirl =  upgrade( agirl ) ;
	 printf( "from >> |%.2f|", agirl.gpa ) ;
	 
	 return 0 ;	
	 
}//end function
struct student upgrade( struct student child ){
	float  allsum ;
	
	if( child.sex == 'M' ) {
		allsum = child.gpa + ( child.gpa *10 ) / 100 ;
		printf( "----|Show Boys|---- \n" ) ;
		printf( "gpa + 10%% : %.2f\n", allsum ) ;
		
		
	} else if( child.sex == 'F' ) {
		allsum = child.gpa + ( child.gpa *20 ) / 100 ;
		printf( "\n----|Show Girls |---- \n" ) ;
		printf( "gpa + 20%% : %.2f\n", allsum ) ;
		
	}
	return child;
}
