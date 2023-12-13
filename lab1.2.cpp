#include <stdio.h>

int *GetSet( int *num ) ;

int main() {
 int *data, num ;
 data = GetSet(&num) ;
 	
 printf("All Member Input = [%d]\n",num);
 
 for (int i = 0; i < num; i++){
	printf("Member[%d] : %d\n",i+1,data[i]);
}

 delete[] data;
 return 0 ;
 
}//end function
int *GetSet( int *num ) {
	int *n;
	printf("Input Member : ");
	scanf("%d",num);
	n = new int[*num];
	for(int i = 0; i < *num; i++){
		printf("Data member %d : ", i+1 );
        scanf("%d", &n[i]);
	}
	return n;
}
