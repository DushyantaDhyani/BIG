#include<stdio.h>
#include<malloc.h>
#include "Include/BIG.h"
int main(){
	char *str;
	str=(char *)malloc(sizeof(str));
	scanf("%s",str);
	BIG *big=newBIG(str);
	char *eqStr;
	eqStr=toStringBIG(big);
	return 0;
}
