#include <stdio.h>
int main(){
	printf("2\n");
	int i,j,a[100];
	for(i=1;i<=100;i++) a[i-1]=i;
	for(i=2;i<100;i++){
		for(j=i;j<100;j++){
			if(a[j]%i==0)a[j]=0;
		}
		if(a[i]!=0) printf("%d\n",a[i]);
	}	
}