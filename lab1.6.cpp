#include <stdio.h>

int* GetMatrix( int *row, int *col ) ;

int main() {
 int *data, m, n ;
 data = GetMatrix( &m, &n ) ;
 
 printf("row = [%d] colum =[%d] \n",m,n);
 
 	for( int i = 0 ; i < m; i++ ) {
		for( int j = 0 ; j < n ; j++ ){
			printf( "Data[ %d ][ %d ] = (%d) \n", i, j, data[i * n+ j] ) ;
	} //end j	
} //end i
 delete[] data;
 return 0 ;
}
int* GetMatrix( int *row, int *col ){
	int *data;
	printf( "----|Input Row and Column|----\n" ) ;
	printf( "Enter row : " ) ;
	scanf( "%d", row ) ;
	printf( "Enter col : " ) ;
	scanf( "%d", col ) ;

	data = new int[*row* *col];
	for(int i = 0; i < *row; i++){
		for(int j = 0; j < *col; j++){
			printf("Data row & column |%d| |%d|  : ", i,j );
        	scanf("%d", &data[i* *col + j]);
		} //end j
	}//end i
	return data ;
}

