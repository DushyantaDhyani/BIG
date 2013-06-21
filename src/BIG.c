#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "../Include/BIG.h"
#include "../Include/bool.h"
BIG* newBIG(char *arr){
	BIG *big=(BIG*)malloc(sizeof(BIG));
	if(big==NULL){
		printf("Memory Allocation Error for BIG\n");
		exit(1);
	}
	int i=0;
	int k=0;
	int len=strlen(arr);
	while(arr[i]=='0'){
		i++;
	}
	if(arr[i]!='\0'){
		if(arr[i]=='-'){
			big->sign=-1;
			i++;
		}
		else{
			big->sign=1;
		}
		len=len-i;
	}
	//len=len-i;
	big->length=len;	
	big->data=(char *)malloc((len+1)*sizeof(char));
	if(big->data=='\0'){
		printf("Memory Allocation Error for Big's Data\n");
		exit(1);
	}
	while(arr[i]!='\0'){
		big->data[k]=arr[i];	
		k++;
		i++;
	}
	if(k==0){
		big->data[k++]='0';
	}
	big->data[k]='\0';
	return big;
}
char* toStringBIG(BIG *big){
	char *str=(char *)malloc(((big->length)+1)*sizeof(char));
	int i=0;
	while(big->data[i]!='\0'){
		str[i]=big->data[i];
		i++;
	}
	str[i]='\0';
	return str;
}

