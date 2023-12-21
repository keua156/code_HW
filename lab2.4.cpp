#include<stdio.h>

void explode( char str1[], char splitter, char str2[][10], int *count ) ;

int main() {
 	char out[ 20 ][ 10 ] ;
 	int num ;	
 	explode( "I/Love/You", '/', out, &num ) ;
	return 0 ;	
}//end function

void explode( char str1[], char splitter, char str2[][10], int *count ) {
	 int i , j  ;
	 int length;
	
		for(i = 0 , j = 0 ; i < length ; i++ ){
			// find '/' in str1
			if(str1[i] == splitter){
				(*count)++;
				j = 0 ;
			}else{ 
				str2[*count][j]= str1[i]; // input data form str1 to str2
				j++;
			}
		} //end for 1	
		
		( *count )++ ;
		
		for(int i = 0 ; i < length ; i++ ) {
		printf( "str2[ %d ] = \" %s \"\n", i, str2[ i ] ) ;
		if( i >= *count - 1 ) {
			break ;	
		}//end if
	}//end for 2
		
		printf( "\ncount = %d", *count ) ;
	
		
	
		
}
