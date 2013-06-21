#include<stdio.h>
#include "Include/BIG.h"
int main(){
	char *str;
	scanf("%s",str);
	BIG *big=newBIG(str);
	return 0;
}
