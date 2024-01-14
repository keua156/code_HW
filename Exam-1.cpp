#include <stdio.h>

int main() {
	
	int A[6], B[6] ; // int A & B be array
	int i = 0 , j = 0 ; // num
	char Operator ; // Operator >> + or -
	int Answer[7]; // int Answer be array
	
	printf( "Enter Number A : \n" );
	//start do..while A <---( order 1 )
	do{
		printf( "A[%d] : ",i ); //show A
		scanf( "%d",&A[i] ); // input data in array A
		if(A[i] >= 10){
			printf( "Input Olny 0 - 9 \n" ); //if input number more 9 process not continue
		}else{
			i++; // if input 0 - 9 i++
		}
		
	}while( i < 6 ); //end do..while A
		
	printf( "Enter Number B : \n" );
	//start do..while B <---( order 2 )
	do{
		printf( "B[%d] : ",j ); //show B
		scanf( "%d",&B[j] ); // input data in array B
		if(B[j] >= 10){
			printf( "Input Olny 0 - 9 \n" ); // if input number more 9 process not continue
		}else{
			j++; //if input 0 - 9 j++
		}
	}while( j < 6 ); //end do..while B
	
	//start do..while Operator <---( order 3 )
	do{
		printf("\nOperator |+ or -|: ");
		scanf(" %c",&Operator);
			// if Operator are =  ' + '	 <---( order 3.1)
			if(Operator == '+'){
				int Count = 5 ; // sum A + B
				int Collect = 0 ; // Roll up the numbers
				do{	
				int Sum = A[Count] + B[Count] + Collect; // value in A & B = A + B and Roll up the numbers form Collect
				Answer[ Count + 1 ] = Sum % 10; 
				Collect = Sum / 10; // if more 10 Collect the value to  variable collect
				Count --;
				}while( Count >= 0 ); //end do while for find plus number
				Answer[ 0 ] = Collect ; 
					
				printf("\nIndex\t\tx\t0\t1\t2\t3\t4\t5 \n\n");
				printf( "Number A :\t\t%d\t%d\t%d\t%d\t%d\t%d \n" ,A[ 0 ], A[ 1 ], A[ 2 ], A[ 3 ], A[ 4 ], A[ 5 ] ) ; // show data in array A
				printf("\t\t\t\t\t\t\t\t\t+\n"); // Operator +
				printf( "Number B :\t\t%d\t%d\t%d\t%d\t%d\t%d \n" , B[ 0 ] , B[ 1 ] , B[ 2 ] , B[ 3 ] , B[ 4 ] , B[ 5 ] ) ; //show data in array B
				printf( "\n\t\t____________________________________________________\n") ;
				printf( "ANS  :\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d \n" , Answer[ 0 ] , Answer[ 1 ] , Answer[ 2 ] , Answer[ 3 ] , Answer[ 4 ] , Answer[ 5 ], Answer[ 6 ] ) ;//show sum between A+B
				printf( "\n\t\t====================================================\n") ;
			break; //end if
			}
			// if Operator are =  ' - ' <---( order 3.2 )
			else if(Operator == '-'){
				int Count = 5 ; // sum A + B
				int Collect = 0 ; // Roll up the numbers
				do{	
					if(A[0] >= B[0]){
						int Sum = A[Count] - B[Count] - Collect; //value in A & B = A - B and Borrow array previous
						if ( Sum < 0 ) { 
							Sum += 10 ; //if 
							Collect = 1 ;
						} else {
							Collect = 0 ;
						}
					Answer[ Count + 1 ] = Sum; // input sum value to array Answer
					}else if(A[0] < B[0]){
						int Sum = B[Count] - A[Count] - Collect; //value in A & B = A - B and Borrow array previous
						if ( Sum < 0 ) { 
							Sum += 10 ; //if 
							Collect = 1 ;
						} else {
							Collect = 0 ;
						}
					Answer[ Count + 1 ] = Sum; // input sum value to array Answer
					}
				Count -- ;
				}while( Count >= 0 ); //end do while for find minus number
				Answer[ 0 ] = Collect;
			printf("\nIndex\t\tx\t0\t1\t2\t3\t4\t5 \n\n");
			printf( "Number A :\t\t%d\t%d\t%d\t%d\t%d\t%d \n" ,A[ 0 ], A[ 1 ], A[ 2 ], A[ 3 ], A[ 4 ], A[ 5 ] ) ; // show data in array A
			printf("\t\t\t\t\t\t\t\t\t-\n");
			printf( "Number B :\t\t%d\t%d\t%d\t%d\t%d\t%d \n" , B[ 0 ] , B[ 1 ] , B[ 2 ] , B[ 3 ] , B[ 4 ] , B[ 5 ] ) ; // show data in array B
			printf( "\n\t\t____________________________________________________\n") ;
			if(A[0] >= B[0]){
				printf( "ANS  :\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d \n" , Answer[ 0 ] , Answer[ 1 ] , Answer[ 2 ] , Answer[ 3 ] , Answer[ 4 ] , Answer[ 5 ], Answer[ 6 ] ) ; //show sum between A-B
			}else if(A[0] < B[0]){
				printf( "ANS  :\t\t%c\t%d\t%d\t%d\t%d\t%d\t%d \n" ,Operator, Answer[ 1 ] , Answer[ 2 ] , Answer[ 3 ] , Answer[ 4 ] , Answer[ 5 ], Answer[ 6 ] ) ;
			}
			printf( "\n\t\t====================================================\n") ;
			break;//end if
			}
			else{
			printf ("!! No Operator Try Again !!"); // if Operator not |+ or -|
			}
	}while(true); //end do..while Operator
		
}
