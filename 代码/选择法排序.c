#include <stdio.h>
int main(){
	int a[10]={1,5,75,65,54,43,21,10,9,2};
	int i,j,l,min=a[0],x;
	l=sizeof(a)/sizeof(a[0]);
	for(j=0;j<l;j++){
		for(i=j;i<l;i++){
			if(a[i]<min){
				min = a[i];
				x = i;
			}
		}
		if(a[j]!=min){
			min = a[j];
			a[j] = a[x];
			a[x] = min;
		}
		min = a[j+1];
	}
	for(i=0;i<l;i++){
		printf("%d\n",a[i]);
	}
}