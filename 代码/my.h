#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#ifndef _MY_H_
#define	_MY_H_
#endif



int  MAX(){
int main()
{
    int n,a,max,i;
    scanf("%d",&n);
    scanf("%d",&max);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a>max)max=a;
    }
    printf("%d",max);
    return 0;
} 	
}


int  MIN(int a,int b){
	int min=b;
	if (a<b) {
		min=a;
	}
	printf("%d",min);	
}

















