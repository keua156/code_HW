#include<stdio.h>

char* reverse( char str1[]) ;

int main() {
	char text[ 50 ] = "I Love You" ;
	char *out ;
	printf("Input : %s \n",text);
	out = reverse( text ) ;
}
char* reverse( char str1[]) {
	int length = 0;
	char str2[50];
    while (str1[length] != '\0') {
        length++;
    } 
    	printf("output : ");
    for(int i = 0; i < length; i++) {
        str2[i] = str1[length - 1 -i];
		printf("%c",str2[i]);
    }
    
}
