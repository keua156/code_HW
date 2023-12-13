#include <stdio.h>
void GetMatrix( int **value, int *row, int *col ) ;

int main() {
 int *data, m, n ;
 GetMatrix( &data, &m, &n ) ;
 
 printf("row = [%d] colum =[%d] ",m,n);
 
 	for( int i = 0 ; i < m; i++ ) {
		for( int j = 0 ; j < n ; j++ ){
			printf( "Data[ %d ][ %d ] = (%d) ", i, j, data[i * n+ j] ) ;
	} //end j
} //end i
 delete[] data;
 return 0 ;
}
void GetMatrix( int **value, int *row, int *col ) {
	
	printf( "----|Input Row and Column|----" ) ;
	printf( "Enter row : " ) ;
	scanf( "%d", row ) ;
	printf( "Enter col : " ) ;
	scanf( "%d", col ) ;
	
	*value = new int[*row* *col];
	
	for(int i = 0; i < *row; i++){
		for(int j = 0; j < *col; j++){
			printf("Data row & column |%d| |%d|  : ", i,j );
        	scanf("%d", &(*value)[i* *col + j]);
		} //end j
	}//end i
	
}
