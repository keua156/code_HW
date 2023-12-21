#include <stdio.h>

struct student {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
} ;

void upgrade( struct student child ) ;

int main() {
	
	 struct student aboy ;
	 aboy.sex = 'M' ;
	 aboy.gpa = 3.00 ;
	 upgrade( aboy ) ;
	 printf( "from >> |%.2f|", aboy.gpa ) ;
	 
	 struct student agirl  ;
	 agirl.sex = 'F' ;
	 agirl.gpa = 3.00 ;
	 upgrade( agirl ) ;
	 printf( "from >> |%.2f|", agirl.gpa ) ;
	 
	 
	 return 0 ;
}//end function

void upgrade( struct student child ){
	
	float sum , allsum ;
	
	if( child.sex == 'M' ) {
		sum = ( child.gpa *10 ) / 100 ; 
		allsum = child.gpa + sum ;
		printf( "----|Show Boys|---- \n" ) ;
		printf( "gpa + 10%% : %.2f\n", allsum ) ;
		
		
	} else if( child.sex == 'F' ) {
			
		sum = ( child.gpa *20 ) / 100 ; 
		allsum = child.gpa + sum ;
		printf( "\n----|Show Girls |---- \n" ) ;
		printf( "gpa + 20%% : %.2f\n", allsum ) ;
		
}
}
