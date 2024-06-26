/*学无止境*/


#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>

#define ESC 27
#define UP 328
#define DOWN 336
#define LEFT 331
#define RIGHT 333
#define BLANK 32
#define BOTTOM 2
#define CANNOT 1
#define CAN 0
#define MAX 30
#define F1 315
#define ADD 43
#define EQUAL 61
#define DEC 45
#define SOUNDs 115
#define SOUNDS 83
#define PAUSEP 80
#define PAUSEp 112

void Init();
void Down();
void GoOn();
void ksdown();
void Display(int color);
void Give();
int Touch(int x,int y,int dx,int dy);
int GeyKey();
void Select();
void DetectFill();
void GetScores();
void Fail();
void Help();
void Quit();
void DrawBox(int x,int y,int Color);
void OutTextXY(int x,int y,char *String);
void DispScore(int x,int y,char Ch);
void DrawNext(int Color);

int Heng=12,Shu=20; /*横竖*/
int Position[MAX][MAX];
int middle[MAX][MAX];
int ActH,ActS;
int Act,Staus;
int i,j,k;
int Wid=10;
int NoPass=CAN;
float Delays=15000;
int BeginH=250,BeginS=7;
float Seconds=0;
int Scores=0;
int flag=1;
int Sounds=CAN;
int PreAct,NextAct;
int a[8][4][4][4]={{{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0}},
{{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0}},
{{1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
{0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0}},
{{1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0},
{0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0}},
{{0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0},
{1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
{0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0},
{1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0}},
{{1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
{1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0},
{1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0}},
{{0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0},
{1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
{1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0}},
{{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}};
int b[4][4];

main(int argc,char *argv[])
{
if (argc!=1)
{
if (argv[1]!="")
Heng=atoi(argv[1]);
if (argv[2]!="")
Shu=atoi(argv[2]);
}
Init(); /*初始化界面*/
PreAct=random(8); /*取得当前的方块*/
for(;;) /*以下是游戏流程*/
{
NextAct=random(8); /*取得下一个方块*/
DrawNext(1); /*画出下一个方块*/
Act=PreAct;
if (Heng%2==0) ActH=Heng/2;
else ActH=(Heng-1)/2;
ActS=0; /*方块开始从游戏空间的中间下落*/
Staus=0; /*取开始的状态*/
NoPass=CAN; /*物体可以下落*/
Give(); /*取得当前的方块*/
Display(Act+1); /*显示当前的方块，每种方块的颜色不同*/
GoOn(); /*游戏的算法精髓所在*/
PreAct=NextAct; /*方块下落完毕，取得下一个方块*/
DrawNext(0);
}
}
void Init()
{
int GraphDriver=DETECT,GraphMode;
registerbgidriver(EGAVGA_driver);
initgraph(&GraphDriver,&GraphMode,"");
if (kbhit()) Sounds=CANNOT;
setcolor(1);
OutTextXY(10,10,"Tetris");
OutTextXY(30,30,"Version 2.0");
OutTextXY(10,120,"Help:");
OutTextXY(20,140,"+ :Faster");
OutTextXY(20,160,"- :Slower");
OutTextXY(20,180,"Esc :Quit");
OutTextXY(20,200,"F1 :Help"); 
OutTextXY(10,310,"Copyright(c) 1998.2.22"); 
OutTextXY(10,320,"By Mr. Unique"); 
outtextxy(10,250,"Score: 00000"); 
rectangle(BeginH-3,BeginS-3,BeginH+Heng*(Wid+2)+2,BeginS+Shu*(Wid+2)+2); 
rectangle(BeginH-5,BeginS-5,BeginH+Heng*(Wid+2)+4,BeginS+Shu*(Wid+2)+4); 
rectangle(BeginH+(Heng+4)*(Wid+2)-2,BeginS+10,BeginH+(Heng+8)*(Wid+2)+2,BeginS+12+4*(Wid+2)); 
for (i=0;i<MAX;i++) 
for (j=0;j<MAX;j++) 
{Position[i][j]=1; 
middle[i][j]=-1; 
} 
for (i=0;i<Heng;i++) 
for (j=0;j<Shu;j++) 
Position[i][j]=0; 

for (i=0;i<Heng;i++) 
for (j=0;j<Shu;j++) 
DrawBox(i,j,0); 
randomize(); 
} 
void GoOn() 
{ 
for(;;) 
{ 
Seconds+=0.2; /*控制方块的下落速度*/ 
if (Seconds>=Delays) 
{ 
Down(); 
Seconds=0; 
if (NoPass==BOTTOM) 
{ 
DetectFill(); 
middle[ActH][ActS]=Act; 
if (ActS==0) 
Fail(); 

return; 
} 
} 
if (kbhit()) 
Select(); 
} 
} 
void Down() /*方块下降*/ 
{ 
Display(0); 
if (Touch(ActH,ActS,0,1)==CAN) 
ActS++; 
else 
middle[ActH][ActS]=Act; 
Display(Staus+1); 
} 
int Touch(int x,int y,int dx,int dy) 
{ 
NoPass=CAN; 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
Position[x+dx+i][y+dy+j]+=b[i][j]; 
for (i=0;i<MAX;i++) 
for (j=0;j<MAX;j++) 
if (Position[i][j]>1) 
NoPass=CANNOT; 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
{ 
Position[x+dx+i][y+dy+j]-=b[i][j]; 
middle[x+dx+i][y+dy+j]=Act; 
} 
if (NoPass==CANNOT && dx==0 && dy==1) 
{ 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
Position[x+i][y+j]+=b[i][j]; 
NoPass=BOTTOM; 
} 
return NoPass; 
} 
int GetKey(void) 
{ 
int Ch,Low,Hig; 
Ch=bioskey(0); 
Low=Ch&0x00ff; 
Hig=(Ch&0xff00)>>8; 
return(Low==0?Hig+256:Low); 
} 
void Select() 
{ 
int OldStaus,acts=ActS; 
switch(GetKey()) 
{ 
case ESC :Quit();break; 
case DOWN :Seconds+=14500;break; 
case LEFT :Display(0); 
if (ActH>0 && Touch(ActH,ActS,-1,0)==CAN) 
{ ActH--;} 
Display(Act+1);break; 
case RIGHT :Display(0); 
if (ActH<Heng && Touch(ActH,ActS,1,0)==CAN) 
{ ActH++;} 
Display(Act+1);break; 
case BLANK : Display(0); 
ksdown(); 
Display(Act+1); 
break; 
case F1 :Help();break; 
case EQUAL : 
case ADD :if (Delays>300) Delays-=100;break; 
case DEC :if (Delays<3000) Delays+=100;break; 
case PAUSEP : 
case PAUSEp :getch();break; 
case SOUNDS : 
case SOUNDs :if (Sounds==CAN) 
Sounds=CANNOT; 
else 
Sounds=CAN;break; 
case UP :if(Act==7) 
{ 
while(acts<Shu-1&&Position[ActH][acts]!=1) 
acts++; 
Position[ActH][acts]=0; 
DrawBox(ActH,acts,0); 
acts=ActS; 
break; 
} 
else 
{ 
Display(0); 
OldStaus=Staus; 
switch(Act) 
{ 
case 0: 
case 3: 
case 4:if (Staus==1) Staus=0;else Staus=1;break; 
case 1:break; 
case 2: 
case 5: 
case 6:if (Staus==3) Staus=0;else Staus++;break; 
} 
Give(); 
if (Touch(ActH,ActS,0,0)==CANNOT) 
{ 
Staus=OldStaus; 
Give(); 
} 
Display(Act+1); 
break; 
} 
} 
} 
void ksdown() 
{ 
while(flag){ 
if(Touch(ActH,ActS,0,0)==CAN){ActS++;} 
else { 
ActS--; 
flag=0; 
} 
} 
flag=1; 
} 
void Quit() 
{ 
int ch,TopScore; 
FILE *fp; 
if ((fp=fopen("Russian.scr","r+"))!=NULL) 
{ 
fscanf(fp,"%d",&TopScore); 
if (Scores>TopScore) 
{ 
setcolor(1); 
outtextxy(470,80,"Hello !"); 
outtextxy(470,100,"In all the players,"); 
outtextxy(470,120,"You are the First !"); 
outtextxy(470,140,"And your score will"); 
outtextxy(470,160,"be the NEW RECORD !"); 
fseek(fp,0L,0); 
fprintf(fp,"%d",Scores); 
} 
fclose(fp); 
} 
setcolor(1); 
OutTextXY(470,220,"Are You Sure (Yes/no)?"); 
ch=getch(); 
if (ch=='y'||ch=='Y') 
{ 
closegraph(); 
delay(20); 
exit(0); 
} 
setcolor(0); 
outtextxy(470,220,"Are You Sure (Yes/no)?"); 
} 
void OutTextXY(int x,int y,char *String) 
{ 
int i=0; 
char a[2]; 
moveto(x,y); 
a[1]='\0'; 
while (*(String+i)!='\0') 
{ 
a[0]=*(String+i); 
outtext(a); 
if (Sounds==CAN && a[0]!=' ') 
{ 
sound(3000); 
delay(50); 
nosound(); 
} 
i++; 
} 
} 
void Help() 
{ 
unsigned Save; 
void *Buf; 
Save=imagesize(160,120,500,360); 
Buf=malloc(Save); 
getimage(160,120,500,360,Buf); 
setfillstyle(1,1); 
bar(160,120,500,280); 
setcolor(0); 
OutTextXY(170,130," About & Help"); 
OutTextXY(170,150," # # # ########## # # # "); 
OutTextXY(170,160," # ## # # # # # # ###### ### "); 
OutTextXY(170,170," ########## ########## ## # # "); 
OutTextXY(170,180," # # # # # # # ## #### "); 
OutTextXY(170,190," # ## # #### ## # # # "); 
OutTextXY(170,200," # ## # # # # # ## # # # "); 
OutTextXY(170,210," # # # ## ## # ###### # # # "); 
OutTextXY(170,220," ## # ## # ## # # # # "); 
OutTextXY(170,230," # ## # #### # ## # "); 
OutTextXY(170,260," Good Luckly to You !!! "); 
getch(); 
putimage(160,120,Buf,0); 
free(Buf); 
} 
void GetScores() 
{ 
int Sec10000,Sec1000,Sec100,Sec10,Sec1; 
setfillstyle(0,1); 
bar(60,250,109,260); 
Sec1=Scores%10; 
Sec10=(Scores%100-Scores%10)/10; 
Sec100=(Scores%1000-Scores%100)/100; 
Sec1000=(Scores%10000-Scores%1000)/1000; 
Sec10000=(Scores%100000-Scores%10000)/10000; 
DispScore(60,250,'0'+Sec10000); 
DispScore(70,250,'0'+Sec1000); 
DispScore(80,250,'0'+Sec100); 
DispScore(90,250,'0'+Sec10); 
DispScore(100,250,'0'+Sec1); 
DispScore(110,250,'0'); 
DispScore(120,250,'0'); 
} 
void DispScore(int x,int y,char Ch) 
{ 
char a[2]; 
a[1]='\0'; 
a[0]=Ch; 
outtextxy(x,y,a); 
} 
void Give() 
{ 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
b[i][j]=a[Act][Staus][i][j]; 
} 
void Display(int color) 
{ 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
if (b[i][j]==1) DrawBox(ActH+i,ActS+j,color); 
} 
void DrawBox(int x,int y,int Color) 
{ 
x=BeginH+x*(Wid+2); 
y=BeginS+y*(Wid+2); 
setfillstyle(1,Color); 
bar(x+2,y+2,x+Wid-1,y+Wid-1); 
if (Color==0) 
setcolor(9); 
else 
setcolor(Act+1); 
rectangle(x+4,y+4,x+Wid-4,y+Wid-4); 
} 
void DrawNext(int Color) 
{ 
for (i=0;i<4;i++) 
for (j=0;j<4;j++) 
if (a[NextAct][0][i][j]==1) DrawBox(Heng+4+i,1+j,Color); 
} 
void DetectFill() 
{ 
int Number,Fall,FallTime=0; 
for (i=Shu-1;i>=0;i--) 
{ 
Number=0; 
for (j=0;j<Heng;j++) 
if (Position[j][i]==1) Number++; 
if (Number==Heng) 
{ 
FallTime++; 
if (Sounds==CAN) 
{ 
sound(500); 
delay(500); 
nosound(); 
} 
for (Fall=i;Fall>0;Fall--) 
for (j=0;j<Heng;j++) 
{ 
Position[j][Fall]=Position[j][Fall-1]; 
middle[j][Fall]=middle[j][Fall-1]; 
if (Position[j][Fall]==0) DrawBox(j,Fall,0); 
else DrawBox(j,Fall,middle[j][Fall]+1); 
} 
i++; 
} 
} 
switch(FallTime) 
{ 
case 0:break; 
case 1:Scores+=1;break; 
case 2:Scores+=3;break; 
case 3:Scores+=6;break; 
case 4:Scores+=10;break; 
} 
if (FallTime!=0) 
{ 
GetScores(); 
if (Scores%100==0) Delays-=100; 
} 
} 
void Fail() 
{ 
if (Sounds==CAN) 
{ 
for (k=0;k<3;k++) 
{ 
sound(300); 
delay(200); 
nosound(); 
} 
} 
setcolor(1); 
OutTextXY(440,200,"Game over!"); 
Quit(); 
closegraph(); 
exit(0); 
} 

