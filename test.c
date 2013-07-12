#include<stdio.h>
#include<malloc.h>
#include "Include/BIG.h"
int main(){
	char str1[1000];
	char str2[1000];
	char *value;
	printf("Enter 2 numbers\n");
	scanf("%s",str1);
	scanf("%s",str2);
	BIG *big1=newBIG(str1);
	BIG *big2=newBIG(str2);
	BIG *result=multiplyBIG(big1,big2);
	value=toStringBIG(result);
	freeBIG(&result);
	if(result!=NULL){
		printf("Some Error\n");
	}
	printf("%s\n",value);
	return 0;
}
