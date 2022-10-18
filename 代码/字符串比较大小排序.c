#include <stdio.h>
#include <string.h>
int main(){
	int i;
	char a[10],b[10];
	gets(a);
	for(i=0;i<10;i++){	
		gets(b);
		if(strcmp(a,b)<0) strcpy(a,b); 		
	}
	puts(a);
}