#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "../Include/BIG.h"
#include "../Include/bool.h"
#define MAX(M,N) M>N?M:N
BIG* newBIG(char *arr){
	BIG *big=(BIG*)malloc(sizeof(BIG));
	if(big==NULL){
		printf("Memory Allocation Error for BIG\n");
		exit(1);
	}
	int i=0;
	int k=0;
	int j;
	int len=strlen(arr);
	j=len-1;
	if(arr[i]!='\0'){
		if(arr[i]=='-'){
			big->sign=-1;
			i++;
		}
		else{
			big->sign=1;
		}
	}
	while(arr[i]=='0'){
		i++;
	}
	len=len-i;
	big->length=len;	
	big->data=(char *)malloc((len+1)*sizeof(char));
	if(big->data=='\0'){
		printf("Memory Allocation Error for Big's Data\n");
		exit(1);
	}
	while(j>=i){
		big->data[k++]=arr[j--];	
	}
	if(k==0){
		big->data[k++]='0';
	}
	big->data[k]='\0';
	return big;
}
char* toStringBIG(BIG *big){
	char *str;
	int k,i;
	k=0;
	if(big->sign==-1){
		str=(char *)malloc(((big->length)+2)*sizeof(char));		
		str[k++]='-';
	}
	else{
		str=(char *)malloc(((big->length)+1)*sizeof(char));		
	}
	i=big->length -1;
	while(i>=0){
		str[k++]=big->data[i--];
	}
	str[k]='\0';
	return str;
}
int compareMagnitudeBIG(BIG *big1,BIG *big2){
	int j;
	if(big1->length==big2->length){
		j=big1->length -1 ;
		while(j>=0){
			if((big1->data)[j]>(big2->data)[j]){
				return 1;	
			}
			else if((big1->data)[j]<(big2->data)[j]){
				return -1;
			}
			j--;
		}
		return 0;
	}
	else{
		if(big1->length > big2->length){
			return 1;
		}
		else{
			return -1;
		}
	}
}
bool equalBIG(BIG *big1, BIG *big2){
	int i,j;
	if(big1->sign != big2->sign){
		return false;
	}
	else{
		if(big1->length != big2->length){
			return false;
		}
		i=0;
		while(i<(big1->length)){
			if(big1->data[i] != big2->data[i]){
				return false;
			}
			i++;
		}
		return true;
	}
}
BIG* addBIG(BIG *big1,BIG *big2){
	printf("1st Number %s\n",toStringBIG(big1));
	printf("2nd Number %s\n",toStringBIG(big2));
	BIG *sum;
	BIG temp1,temp2;
	temp1=*big1;
	temp2=*big2;
	int carry;
	int len;
	int i,j;
	if((temp1.sign * temp2.sign)==-1){
		if(temp1.sign==-1){
			temp1.sign=1;
			sum=subBIG(&temp2,&temp1);
		}
		else{
			temp2.sign=1;
			sum=subBIG(&temp1,&temp2);
		}
	}
	else{
		if(temp1.sign==-1 && temp2.sign==-1){
			temp1.sign=1;
			temp2.sign=1;
			sum=addBIG(&temp1,&temp2);
			sum->sign=-1;
		}
		else{
			sum=(BIG *)malloc(sizeof(sum));
			len=MAX(big1->length,big2->length);
			carry=0;
			sum->data=(char *)malloc((len+2)*sizeof(char));
			i=0;
			while(((big1->data)[i]!='\0') && ((big2->data)[i]!='\0')){
				(sum->data)[i]= (((big1->data)[i]+(big2->data)[i]+carry-2*'0')%10)+'0';
				carry=((big1->data)[i]+(big2->data)[i]+carry-2*'0')/10; 
				i++;
			}
			if((big1->data)[i]=='\0'){
				while((big2->data)[i]!='\0'){
					(sum->data)[i]=(((big2->data)[i]+carry-'0')%10)+'0';
					carry=((big2->data)[i]+carry-'0')/10;
					i++;
				}
			}
			if((big2->data)[i]=='\0'){
				while((big1->data)[i]!='\0'){
					(sum->data)[i]=(((big1->data)[i]+carry-'0')%10)+'0';
					carry=((big1->data)[i]+carry-'0')/10;
					i++;
				}
			}
			if(carry!=0){
				(sum->data)[i]=carry+'0';
				i++;
			}
			(sum->data)[i]='\0';
			sum->length=i;
		}
	}
	return sum;
}
BIG* subBIG(BIG *big1,BIG *big2){
	BIG *sub;
	return sub;
}
