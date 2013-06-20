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
			big->data[k++]=arr[i++];	
		}
		if(k==0){
			big->data[k++]='0';
		}
		big->data[k]='\0';
		big->length=k;
	}
	return big;
}

