#include <stdio.h>

int GetSet( int **data) ;

int main() {
	
 	int *data, num ;
 	num = GetSet( &data) ;
 		printf("All Member Input = [%d] \n",num);	
    	 for (int i = 0; i < num; i++){
	printf("Member[%d]:(%d)\n",i+1,data[i]);
	}
    delete []data;
 	return 0 ;
}

int GetSet( int **data )
{
	int *num;
    printf("Input Member : ");
    scanf("%d", num) ;
    
    *data = new int[*num];
    
    for (int i = 0; i < *num; i++) {
    	printf("Data  member %d:", i+1 );
        scanf("%d", &(*data)[i]);
    }
    return *num;
}
