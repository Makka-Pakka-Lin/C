#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#ifndef _MY_H_
#define	_MY_H_
#endif



int  MAX(int n){
    int a,max,i;
    scanf("%d",&max);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a>max)max=a;
    }
    return max;
 	
}


int  MIN(int n){
	int a,min,i;
    scanf("%d",&min);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a<min)min=a;
    }
    return min;	
}

int  MIN_MAX(int n){	//n是需要比较的数字的个数 
	int a,i,min,max;
    scanf("%d",max=&min);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a<min)min=a;
        else max=a;
    }
    printf("MAX=%d,MIN=%d",max,min);
    return 0;	
}

int  MAX_MIN(int n){
	int a,i,min,max;
    scanf("%d",max=&min);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        if(a<min)min=a;
        else max=a;
    }
    printf("MAX=%d,MIN=%d",max,min);
    return 0;	
}

int maopao(void){
	int i,j,x,n,m,avg=0;
	long int a[avg];
	printf("请输入一共几个数");
	scanf("%d",&avg);
	for(i=0;i<avg;i++){
		printf("请输入第%d位数\n",i+1); 
		scanf("%d",&x);
		a[i] = x;
		printf("\n");
	}
	for(n=0;n<avg;n++){
		for(i=0;i<avg;i++){
			if(a[i]>a[i+1]){
				j = a[i];
				for(m=0;m<avg;m++){
					//printf("%d",a[m]);	
				}
				a[i] = a[i+1];
				for(m=0;m<avg;m++){
					//printf("%d\n",a[m]);	
				}
				a[i+1] = j;
				for(m=0;m<avg;m++){
					//printf("%d\n",a[m]);	
				}
			}
		}
	}
	for(i=0;i<avg;i++){
		printf("%d,",a[i]);
	}
}



int xuanze(){
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



int erfen(){
	int a[9]={1,12,23,45,56,78,89,90,100};
	int i,j=0,x,on,left=0,right;
	right = sizeof(a)/sizeof(a[0])-1;
	printf("请输入一个想要查询的数");
	scanf("%d",&x);
	while(left<=right){
		on=(left+right)/2;
		
		if(x<a[on])
			{
			
			right=on-1;
			
			}
			
		else{
			
			if(x>a[on]){
				
				left=on+1;
				}
			
			else{
			
				j=on+1;
				break;
				
				}
		}
	}
	if(j==0)printf("这个数不在这个数组\n");
	else 	printf("%d",j);
}











