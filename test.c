#include<stdio.h>
#include<malloc.h>
#include "Include/BIG.h"
int main(){
	char *str1;
	char *str2;
	char *value;
	str1=(char *)malloc(sizeof(str1));
	str2=(char *)malloc(sizeof(str2));	
	printf("Enter 2 numbers\n");
	scanf("%s",str1);
	scanf("%s",str2);
	BIG *big1=newBIG(str1);
	BIG *big2=newBIG(str2);
	BIG *sum=addBIG(big1,big2);
	value=toStringBIG(sum);
	BIG *diff=subBIG(big1,big2);
	printf("%s\n",value);
	value=toStringBIG(diff);
	printf("%s\n",value);
	return 0;
}
