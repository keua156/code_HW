#include <stdio.h>
#include <string.h>

void GetSet( int array[], int *N ) ;

int main() 
{
	
   int data[20],num;
   GetSet(data, &num );
   
    printf("|--- Mamber ---|\n");
    for (int i = 0; i < num; i++) {
        printf("Member[%d] : %d \n",i+1,data[i]);
    }
    printf("|--- ALL Mamber Input : %d ---|", num);
 
 return 0 ;
 	
}//end function

void GetSet( int array[], int *N ) {
	int i;
	
	 printf("Number Member : ");
 	 scanf("%d",N);
 	 
 	 printf("INPUT Data :\n");
    for (i = 0; i < *N; i++) {
        printf("Member %d : ", i+1);
        scanf("%d", &array[i]);
    }

 
}
