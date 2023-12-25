#include <stdio.h>

struct student {
	char name[ 20 ] ;
};

struct student (*GetStudent( int *room ) )[ 10 ] ;

int main() {
	 struct student ( *children )[ 10 ] ;	
	 int group ;
	 children = GetStudent( &group ) ;
	 return 0 ;
}//end function

struct student (*GetStudent( int *room ) )[ 10 ]{
	
	struct student children[ 20 ][ 10 ] ;
	
	printf( "Enter All Room : " );
	scanf( "%d",&(*room) );
	
	for( int i = 0; i < *room ; i++ ){
		printf( "Room [%d] \n",i+1 );
		
		for( int j = 0; j < 2 ; j++ ){
			printf( "Enter student |%d| name : ", j+1 );
			scanf( "%s",children[ i ][ j ].name );
		}
	}
	
	for( int i = 0 ; i < *room ; i++ ) {
	 	printf( "------------------------------\n" );
		printf( "|Show student data Room %d |\n", i + 1 ) ;
		for( int j = 0 ; j < 2 ; j++ ) {
			printf( "student name[ %d ] = %s\n", j + 1, children[i][j] ) ;
		}
		printf( "------------------------------\n" );
	}	
}
