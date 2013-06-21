#include<stdio.h>
#include<malloc.h>
#include "Include/BIG.h"
int main(){
	char *str1;
	char *str2;
	str1=(char *)malloc(sizeof(str1));
	str2=(char *)malloc(sizeof(str2));	
	printf("Enter 2 numbers\n");
	scanf("%s",str1);
	scanf("%s",str2);
	BIG *big1=newBIG(str1);
	BIG *big2=newBIG(str2);
	if(equalBIG(big1,big2)){
		printf("The two are equal\n");
	}
	else{
		printf("The two are different\n");
	}
	return 0;
}
