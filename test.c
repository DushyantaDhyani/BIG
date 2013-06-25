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
	BIG *sum=addBIG(big1,big2);
	char *value;
	value=toStringBIG(sum);
	printf("%s\n",value);
	return 0;
}
