#include<stdio.h>
#include<malloc.h>
#include "../Include/BIG.h"
#include "../Include/bool.h"
BIG* newBIG(char *arr){
	BIG *big=(BIG*)malloc(sizeof(BIG));
	int i=0;
	int k=0;
	while(arr[i]=='0'){
		i++;
	}
	if(arr[i]!='\0' && arr[i]=='-'){
		big->sign=-1;
		i++;
	}
	else{
		while(arr[i]!='\0'){
			big->data=(char *)malloc(sizeof(big->data));
			big->data[k]=arr[i];	
			k++;
			i++;
		}
		if(k==0){
			big->data[k++]='0';
		}
		big->data[k]='\0';
		big->length=k;
	}
	return big;
}
char* toString(BIG *big){
	char *str=(char *)malloc(big->size*sizeof(char));
	int i=0;
	while(big->data[i]!='\0'){
		str[i]=big->data[i];
		i++;
	}
	str[i]='\0';
	return str;
}

