/* my first graphic program under TurboC
time:2005/10/24
by Chiron
*/
#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

#define N 15
struct pot
{
    int x;
    int y;
    struct pot* nextPtr;
};
typedef struct pot Pot;
typedef Pot* PotPtr;

void initMap(int (*map)[N]);
void init();                                  /*init graph*/
void print(int (*map)[N]);
Pot findWay(PotPtr* tempPtr,PotPtr* pathPtr,int (*map)[N]);
int len(PotPtr*);                            /*get the stack lenth*/
Pot pop(PotPtr*);
void push(PotPtr*,Pot);
void drawR(Pot);
void drawPath(PotPtr);                      /*draw the way to pathPtr*/
Pot getTop(PotPtr*);
void printList(PotPtr);
void test(PotPtr*);

int main()
{
    int map[N][N];
    PotPtr pathPtr,tempPtr;
    Pot pot;

    pathPtr=tempPtr=NULL;

    clrscr();
    /*star pot*/
    pot.x=1;
    pot.y=1;
    push(&tempPtr,pot);
    init();
    initMap(map);
    #if 1
    print(map);
    #endif
    #if 1
    while(pot.x!=N-2||pot.y!=N-2)    /*end pot*/ 
    { 
    pot=findWay(&tempPtr,&pathPtr,map); 
    } 
    #endif 
     
    
     
    #if 0 
    drawPath(&pathPtr); 
    #endif 
    getch(); 
}     
void init() 
{ 
    int drive=DETECT,mod; 
    initgraph(&drive,&mod,""); 
} 

void initMap(int (*map)[N]) 
{ 
    int i,j; 
    
    srand((int)time()); 
    for(i=0;i<N;i++) 
    { 
    for(j=0;j<N;j++) 
    { 
        if(i==0||j==0||i==N-1||j==N-1) 
        { 
        map[i][j]=1; 
        }else if(i==1&&j==1||i==N-2&&j==N-2) 
        { 
        map[i][j]=0; 
        }else{ 
        map[i][j]=rand()%2; 
        } 
    } 
    } 
} 

void print(int (*map)[N]) 
{ 
    Pot pot; 
     int i,j; 
     for(i=0;i<N;i++) 
     { 
    for(j=0;j<N;j++) 
    { 
        if(i==1&&j==1||i==N-2&&j==N-2) 
        { 
        pot.x=i; 
        pot.y=j; 
        drawR(pot); 
        } 
        if(map[i][j]==1) 
        { 
        setfillstyle(SOLID_FILL,WHITE); 
        bar(100+20*i-8,100+20*j-8,100+20*i+8,100+20*j+8); 
        } 
    } 
    printf("\n"); 
     } 
     
} 




Pot findWay(PotPtr* tempPtr,PotPtr* pathPtr,int (*map)[N]) 
{ 
     
    Pot pot; 
    Pot tempPot; 
    int length=0; 
     
    pot=getTop(tempPtr); 
    map[pot.x][pot.y]=1; 
    push(pathPtr,pot); 
    drawR(pot); 
     
    
    if(map[pot.x-1][pot.y-1]==0) 
    { 
    tempPot.x=pot.x-1; 
    tempPot.y=pot.y-1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    }  
     
    if(map[pot.x][pot.y-1]==0) 
    { 
    tempPot.x=pot.x; 
    tempPot.y=pot.y-1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
    if(map[pot.x-1][pot.y]==0) 
    { 
    tempPot.x=pot.x-1; 
    tempPot.y=pot.y; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
     
    if(map[pot.x+1][pot.y-1]==0) 
    { 
    tempPot.x=pot.x+1; 
    tempPot.y=pot.y-1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
    if(map[pot.x-1][pot.y+1]==0) 
     { 
    tempPot.x=pot.x-1; 
    tempPot.y=pot.y+1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
     

     
        if(map[pot.x+1][pot.y]==0) 
    { 
    tempPot.x=pot.x+1; 
    tempPot.y=pot.y; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
    if(map[pot.x][pot.y+1]==0) 
    { 
    tempPot.x=pot.x; 
    tempPot.y=pot.y+1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
     if(map[pot.x+1][pot.y+1]==0) 
    { 
    tempPot.x=pot.x+1; 
    tempPot.y=pot.y+1; 
    map[tempPot.x][tempPot.y]=1; 
    push(tempPtr,tempPot); 
    length++; 
    } 
    if(length==0) 
    { 
    pot=pop(pathPtr); 
    if(pot.x==N-2&&pot.y==N-2) 
    { 
        printf("Done!\n"); 
    }else{ 
        setfillstyle(SOLID_FILL,BLACK); 
        bar(100+20*pot.x-8,100+20*pot.y-8,100+20*pot.x+8,100+20*pot.y+8); 
        pot=pop(tempPtr); 
        delay(50000); 
    } 
    } 
    if(len(tempPtr)==1) 
    { 
    printf("No way!\n"); 
    getch(); 
    exit(0); 
    } 
    return pot; 
         
} 
     
    
void push(PotPtr* sPtr,Pot t) 
{ 
    PotPtr currentPtr,previousPtr,newPtr; 
     
    newPtr=(PotPtr)malloc(sizeof(Pot)); 
     
    if(newPtr!=NULL) 
    { 
    newPtr->x=t.x; 
    newPtr->y=t.y; 
    newPtr->nextPtr=NULL; 
         
        currentPtr=*sPtr; 
        previousPtr=NULL; 
        while(currentPtr!=NULL) 
        { 
        previousPtr=currentPtr; 
        currentPtr=currentPtr->nextPtr; 
    } 
        if(previousPtr==NULL){ 
        *sPtr=newPtr; 
        
        }else{ 
        previousPtr->nextPtr=newPtr; 
        
    } 
    }else{ 
    printf("can't malloc \n"); 
    getch(); 
    exit(0); 
    } 
    
}     

   
Pot pop(PotPtr* sPtr) 
{ 
     PotPtr currentPtr,previousPtr,newPtr; 
     Pot pot; 
      
     currentPtr=*sPtr; 
     previousPtr=NULL; 
	 while(currentPtr!=NULL&&(*sPtr)->nextPtr!=NULL)
     { 
     previousPtr=currentPtr; 
     currentPtr=currentPtr->nextPtr; 
     } 
     if(currentPtr==NULL) 
     { 
     *sPtr=NULL; 
      
     
     }else if(currentPtr==*sPtr) 
     { 
     
     pot.x=currentPtr->x; 
     pot.y=currentPtr->y; 
      *sPtr=NULL; 
     }else{ 
      
     previousPtr->nextPtr=NULL; 
     pot.x=currentPtr->x; 
     pot.y=currentPtr->y; 
     
     } 
      return pot; 
} 

   
int len(PotPtr* sPtr) 
{ 
    int length=0; 
    PotPtr tempPtr; 
    tempPtr=*sPtr; 
    while(tempPtr!=NULL) 
    { 
    tempPtr=tempPtr->nextPtr; 
    length++; 
    } 
    return length; 
} 
    
void drawR(Pot pot) 
{ 
    setfillstyle(SOLID_FILL,RED); 
    bar(100+20*pot.x-8,100+20*pot.y-8,100+20*pot.x+8,100+20*pot.y+8); 
    delay(50000); 
} 

void drawPath(PotPtr sPtr) 
{ 
    while(sPtr!=NULL) 
    { 
    setfillstyle(SOLID_FILL,BLUE); 
    bar(100+20*sPtr->x-8,100+20*sPtr->y-8,100+20*sPtr->x+8,100+20*sPtr->y+8); 
    delay(50000); 
    } 
} 

void printList(PotPtr sPtr) 
{ 
    while(sPtr!=NULL) 
    { 
    printf("(%d,%d)-",sPtr->x,sPtr->y); 
    sPtr=sPtr->nextPtr; 
    } 
} 

Pot getTop(PotPtr* sPtr) 
{ 
     PotPtr currentPtr,previousPtr,newPtr; 
     Pot pot; 
      
     currentPtr=*sPtr; 
     previousPtr=NULL; 
     while(currentPtr!=NULL) 
     { 
     previousPtr=currentPtr; 
     currentPtr=currentPtr->nextPtr; 
     } 
      
     pot.x=previousPtr->x; 
     pot.y=previousPtr->y; 
      
     return pot; 
} 
  

void test(PotPtr *sPtr) 
{ 
    Pot pot; 
    int length; 
    printf("x:"); 
    scanf(" %d",&pot.x); 
    printf("y:"); 
    scanf(" %d",&pot.y); 
     
    push(sPtr,pot); 
    length=len(sPtr); 
    printf("%d\n",length); 
    pot=pop(sPtr); 
    length=len(sPtr); 
    printf("%d\n",length); 
     
    drawR(pot); 
} 

    
 
 
