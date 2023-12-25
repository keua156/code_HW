#include <stdio.h>

struct student {
	char name[ 20 ] ;
};

void GetStudent( struct student child[][ 10 ], int *room ) ;

int main() {
	 struct student children[ 20 ][ 10 ] ;
	 int group ;
	 GetStudent( children, &group ) ;
	 
	 for( int i = 0 ; i < group ; i++ ) {
	 	printf("------------------------------\n");
		printf( "|Show student data Room %d |\n", i + 1 ) ;
		for( int j = 0 ; j < 10 ; j++ ) {
			printf( "student name[ %d ] = %s\n", j + 1, children[i][j] ) ;
		}
		printf("------------------------------\n");
	}
	 
	 return 0 ;
 
}//end function

void GetStudent( struct student child[][ 10 ], int *room ){
	
	printf( "Enter All Room : " );
	scanf( "%d",&(*room) );
	
	for(int i = 0; i < *room ; i++){
		printf( "Room [%d] \n",i+1 );

		for(int j = 0; j < 10 ; j++){
			printf( "Enter student |%d| name : ", j+1 );
			scanf("%s",child[ i ][ j ].name);
		}
	}
}

