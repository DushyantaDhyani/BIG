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
void freeBIG(BIG** big){
	if(big){
		free((*big)->data);
		free(*big);
	}
}
BIG* newNULL(BIG* big1){
	big1=(BIG *)malloc(sizeof(big1));
	big1->data=(char *)malloc(1*sizeof(char));
	big1->length=0;
	big1->sign=1;
	(big1->data)[0]='\0';
	return big1;
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
	BIG temp1,temp2;
	temp1=*big1;
	temp2=*big2;
	int i;
	int flag=compareMagnitudeBIG(big1,big2);
	if(flag==1){
		if(big1->sign==1){
			if(big2->sign==1){
				sub=(BIG *)malloc(sizeof(BIG));
				sub->data=(char *)malloc(sizeof(big1->length+1));
				i=0;
				while((big2->data)[i]!='\0' && (big1->data)[i]!='\0'){
					if((big1->data)[i]>=(big2->data)[i]){
						(sub->data)[i]=((big1->data)[i]-(big2->data)[i]+'0');
					}
					else{
						(big1->data)[i+1]--;
						(sub->data)[i]=10+(big1->data)[i]-(big2->data)[i]+'0';
					}
					i++;
				}
				while((big1->data)[i]!='\0'){
					(sub->data)[i]=(big1->data)[i];
					i++;
				}
				(sub->data)[i]='\0';
				(sub->length)=i;
				sub->sign=1;
			}
			else{
				temp2.sign=1;
				sub=addBIG(&temp1,&temp2);
				sub->sign=1;
			}
		}
		else{
			if(big2->sign==1){
				temp1.sign=1;
				sub=addBIG(&temp1,&temp2);		
				sub->sign=-1;
			}
			else{
				temp1.sign=1;
				temp2.sign=1;
				sub=subBIG(&temp1,&temp2);
				sub->sign=-1;
			}
		}
	}
	else if(flag==-1){
		if(big1->sign==1){
			if(big2->sign==1){
				sub=subBIG(&temp2,&temp1);
				sub->sign=-1;
			}
			else{
				temp2.sign=1;
				sub=addBIG(&temp1,&temp2);
				sub->sign=1;
			}
		}
		else{
			if(big2->sign==1){
				temp1.sign=1;
				sub=addBIG(&temp1,&temp2);
				sub->sign=-1;
			}
			else{
				temp1.sign=1;
				temp2.sign=1;
				sub=subBIG(&temp2,&temp1);
				sub->sign=1;
			}
		}
	}
	else{
		if((big1->sign * big2->sign)==1){
			sub=(BIG*)malloc(sizeof(BIG));
			sub->data=(char*) malloc(2*sizeof(char));
			(sub->data)[0]='0';
			(sub->data)[1]='\0';
			sub->sign=1;
		}
		else{
			if(big1->sign==1){
				sub=addBIG(&temp1,&temp1);
				sub->sign=1;
			}
			else{
				temp1.sign=1;
				sub=addBIG(&temp1,&temp2);
				sub->sign=-1;
			}
		}
	}
	return sub;
}
BIG* absBIG(BIG *big1){
	big1->sign=1;
	return big1;
}
BIG* negateBIG(BIG *big1){
	big1->sign *=-1;
	return big1;
}
BIG* multiplyBIG(BIG *big1,BIG *big2){
	BIG *result;
	BIG *product;
	result=(BIG *)malloc(sizeof(BIG));
	if((big1->sign * big2->sign)==1){
		result->sign=1;
	}
	else{
		result->sign=-1;
	}
	result->data=(char *)malloc((big1->length+big2->length+1)*sizeof(char));
	memset(result->data,'0',sizeof(result->data));
	int offset=0;
	int i,j;
	i=0;
	j=0;
	int carry;
	while(i< big2->length){
		product=multiplyDigitBIG(big1,((big2->data)[i]-'0'));
		j=0;
		if(offset==0){
			while((result->data[j]=product->data[j])!='\0'){
				j++;
			}
			result->length=j;
		}
		else{
			carry=0;
			while(result->data[offset+j]!='\0' && product->data[j]!='\0'){
				result->data[offset+j]=(carry+product->data[j]+result->data[offset+j]-2*48)%10+'0';
				carry=(carry+product->data[j]+result->data[offset+j]-2*48)/10;
				j++;
			}
			if(result->data[offset+j]=='\0'){
				result->data[offset+j]=(carry+product->data[j]+'0'-2*48)%10+'0';
				carry=(carry+product->data[j]+'0'-2*48)/10;
				j++;
				if(carry!=0){
					result->data[offset+j]='0'+carry;
					j++;
				}
			}
			result->data[offset+j]='\0';
			result->length=offset+j;
		}
		offset++;
		i++;
	}
	return result;
}
BIG* multiplyDigitBIG(BIG *big1,int num){
	char *value=toStringBIG(big1);
	BIG *result;
	result=(BIG *)malloc(sizeof(BIG));
	result->data=(char *)malloc((2+big1->length)*sizeof(char));
	int carry=0;
	int i=0;
	while(i< big1->length){
		(result->data)[i]=((((big1->data)[i]-'0')*num+carry)%10)+'0';
		carry=(((big1->data)[i]-'0')*num+carry)/10;
		i++;
	}
	if(carry!=0){
		(result->data)[i]=carry+'0';
		i++;
	}
	result->length=i;
	(result->data)[i]='\0';
	return result;
}
