/*这是我用C编的第一个大点的程序 

结构和注释都不太好 

但功能已经能实现了，请大家指点一下： 

游戏任务： 

找到画面上的十个小旗！ 

玩法： 

1：可用方向键移动人 

2：可以推开箱子 

3：有十个炸弹，可炸掉周围的箱子，并有可能，爆出炸弹，捡起可以增加炸弹数 

4：按esc,出现退出提示时，按N键退出 */

#include<graphics.h> 
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<bios.h> 
#define ESC   0x011b 
#define UP    0x4800 
#define DOWN  0x5000 
#define LEFT  0x4b00 
#define RIGHT 0x4d00 
#define ENTER 0x1c0d 
#define MX 28 
#define MY 24 
#define BOXLONG 20 
#define SQI 10 
#define SZADAN 10 
struct point 
{ 
int x; 
int y; 
}zaboxxy[4]={-1,0,1,0,0,-1,0,1}; 
int x,y,map[MX+1][MY+1],szadan,sqi,szuan=0,mx,my,mc; 
void *tx[5]; 
char sc[10]; 



/****************************** 
change a intnumber to a char [] 
*******************************/ 

char *ntos(int n, char *c) 
{long i=0,j,k; 
for(j=5;j>=0;j--) 
{k=n/pow(10,j); 
if(k>0||n==0) 
{c[i++]=k+'0'; 
n=n-k*pow(10,j);} 
} 
c[i]=0; 

return?; 
} 






main() 
{ 
int dr=DETECT,mode=0,i; 
long key=0; 
initgraph(&dr,&mode,""); 
mx=getmaxx(); 
my=getmaxy(); 
mc=getmaxcolor(); 

for(i=1;i<5;i++) tx[i]=malloc(imagesize(1,1,BOXLONG,BOXLONG)); 

loadmap(); 
again: 

gamemessage(); 

  sqi=SQI;szadan=SZADAN; 
  definemap(); 
do 
{  while(bioskey(1)==0); 
           key=bioskey(0); 
   move(key); 
}while(key!=ESC && sqi>0); 

if(sqi==0)message("you are winer!!!!"); 
if(message("do you want play again ?")==1)goto again; 

for(i=1;i<5;i++) free(tx[i]); 
closegraph(); 
} 

/******************* 
SEND A message 
*******************/ 


int message(char *s) 
{ char c; 
setfillstyle(1,4); 
setcolor(1); 
bar(mx/2-200,my/2-50,mx/2+250,my/2+50); 
outtextxy(mx/2-200,my/2-20,s); 
c=getch(); 

if(c=='n'|| c=='N')return(0);else return(1); 

} 



/******************* 
draw map 
*******************/ 
 loadmap() 
{ 
cleardevice(); 
setcolor(1); 
rectangle(1,1,BOXLONG,BOXLONG); 
setcolor(3); 
setfillstyle(1,4); 
bar(5,3,6,18); 
setcolor(4); 
line(6,3,15,13); 
line(6,13,15,13); 
floodfill(14,12,4); 
getimage(1,1,BOXLONG,BOXLONG,tx[1]); 
putimage(1,1,tx[1],1); 


setcolor(4); 

rectangle(1,1,BOXLONG,BOXLONG); 
circle(10,10,9); 
circle(5,5,3); 
circle(15,5,3); 
line(8,15,12,15); 
getimage(1,1,BOXLONG,BOXLONG,tx[2]); 
putimage(1,1,tx[2],1); 

setcolor(1); 
setfillstyle(1,4); 
bar(1,1,BOXLONG,BOXLONG); 
line(1,BOXLONG/3,BOXLONG,BOXLONG/3); 
line(1,BOXLONG/3*2,BOXLONG,BOXLONG/3*2); 
line(BOXLONG/2,1,BOXLONG/2,BOXLONG/3); 
line(BOXLONG/2,BOXLONG/3*2,BOXLONG/2,BOXLONG); 
line(BOXLONG/3,BOXLONG/3,BOXLONG/3,BOXLONG/3*2); 
line(BOXLONG/3*2+2,BOXLONG/3,BOXLONG/3*2+2,BOXLONG/3*2); 

getimage(1,1,20,20,tx[3]); 
putimage(1,1,tx[3],1); 

rectangle(1,1,BOXLONG,BOXLONG); 
setcolor(4); 
circle(10,10,6); 
line(10,3,10,5); 
getimage(1,1,BOXLONG,BOXLONG,tx[4]); 
putimage(1,1,tx[4],1); 
} 

/******************* 
random map 
*******************/ 

definemap() 
{int i,j,x1,y1,x2[SQI+1],y2[SQI+1]; 
randomize(); 
for (i=0;i<=MX;i++) 
for (j=0;j<=MY;j++) 
map[i][j]=0; 
cleardevice(); 
 setlinestyle(5,0,0); 
setcolor(5); 
setfillstyle(1,1); 
bar(BOXLONG*MX+2,2,BOXLONG*MX+10,mx); 


for (i=0;i<SQI+1;i++) 
{ 
   rnd: x1=random(MX-1)+1; 
y1 =random(MY-1)+1; 
for(j=0;j<i-1;j++) 
if (x1==x2[j]&&y1==y2[j]) goto rnd; 
x2[i]=x1;y2[i]=y1; 
if (i!=SQI) 
  {map[x1][y1]=1; 
putimage((x1-1)*BOXLONG,(y1-1)*BOXLONG,tx[1],1); 
}else 
{map[x1][y1]=2; 
putimage((x1-1)*BOXLONG,(y1-1)*BOXLONG,tx[2],1); 
x=x1;y=y1; 
} 
}/* end of for*/ 




for(i=1;i<=MX;i++) 
{for (j=1;j<=MY;j++) 
{if (map[i][j]==0&&(random(10000)%2==0||random(1221)%6==0)) 
{map[i][j]=3;szuan++; 
putimage((i-1)*BOXLONG,(j-1)*BOXLONG,tx[3],1);} 
  } 
}/* end of for i */ 

putimage(610,1,tx[4],1); 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,30,640,50); 
outtextxy(610,30,ntos(szadan,sc)); 

putimage(610,50,tx[1],1); 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,80,640,100); 

outtextxy(610,80,ntos(sqi,sc)); 

putimage(610,120,tx[3],1); 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,150,640,170); 

outtextxy(610,150,ntos(szuan,sc)); 



} 

/******************* 
chose key 
*******************/ 



move(long key) 

{ 
 switch(key) 
{ 
 case UP:    down(0,-1);break; 
 case DOWN:  down(0,1); break; 
  case LEFT:    down(-1,0);break; 
 case RIGHT:    down(1,0);break; 
 case ENTER:    zadan();} 

} 


/******************* 
help moving!!!!!!!!!! 
*******************/ 

 down(int x1 ,int y1 ) 
{ 
int fx ,fy; 
fx=x+x1; 
fy=y+y1; 
if (fx>0&&fx<=MX&&fy>0&&fy<=MY) 
{ switch(map[fx][fy]) 
{ case 0: 
putimage((x-1)*BOXLONG,(y-1)*BOXLONG,tx[2],1); 
putimage((fx-1)*BOXLONG,(fy-1)*BOXLONG,tx[2],1); 
map[x][y]=0;map[fx][fy]=2; 
x=fx;y=fy;lsound(100,500); 
break; 
case 1: 
putimage((fx-1)*BOXLONG,(fy-1)*BOXLONG,tx[1],1); 
putimage((fx-1)*BOXLONG,(fy-1)*BOXLONG,tx[2],1); 
putimage((x-1)*BOXLONG,(y-1)*BOXLONG,tx[2],1); 
        sqi--;map[x][y]=0;map[fx][fy]=2; 
        x=fx;y=fy;lsound(100,500); 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,80,640,100); 
outtextxy(610,80,ntos(sqi,sc)); 
break; 
     case 4: 
putimage((fx-1)*20,(fy-1)*20,tx[4],1); 
putimage((fx-1)*20,(fy-1)*20,tx[2],1); 
putimage((x-1)*20,(y-1)*20,tx[2],1); 
map[x][y]=0;map[fx][fy]=2; 
szadan++;x=fx,y=fy; 
lsound(100,500); 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,30,640,50); 
outtextxy(610,30,ntos(szadan,sc)); 
break; 


case 3: 
  if(x+x1*2>0&&x+x1*2<=MX&&y+y1*2>0&&y+y1*2<=MY&&map[x+x1*2][y+y1*2]==0) 
{putimage((x+x1*2-1)*BOXLONG,(y+y1*2-1)*BOXLONG,tx[3],1); 
putimage((fx-1)*BOXLONG,(fy-1)*BOXLONG,tx[3],1); 
putimage((fx-1)*BOXLONG,(fy-1)*BOXLONG,tx[2],1); 
putimage((x-1)*20,(y-1)*20,tx[2],1); 
map[x+x1*2][y+y1*2]=3; 
map[x+x1][y+y1]=2; 
map[x][y]=0; 
x=fx;y=fy; 
lsound(100,500); 

break; 
} 
/* end of if */ 
}/* end of switch*/ 

}/* end of if*/ 
}/* end of funtion*/ 
/* ************************************************ 
make a zadan 
**************************************************/ 
 zadan() 
{int x1 ,y1 ,i; 
if (szadan>0) 
{szadan--; 
for (i=0;i<4;i++) 
{x1=x+zaboxxy[i].x; 
y1=y+zaboxxy[i].y; 
if (x1>0&&x1<=MX&&y1>0&&y1<=MY&&map[x1][y1]==3) 
{putimage((x1-1)*BOXLONG,(y1-1)*BOXLONG,tx[3],1); 
szuan--; 
settextstyle(0,0,1); 
setcolor(4); 
setfillstyle(1,0); 
bar(610,150,640,170); 

outtextxy(610,150,ntos(szuan,sc)); 

if(random(10000)%4==0) 
{map[x1][y1]=4; 
putimage((x1-1)*BOXLONG,(y1-1)*BOXLONG,tx[4],1); 


}else 
                 map[x1][y1]=0; 
}/*END if */ 
settextstyle(0,0,1); 

        setfillstyle(1,0); 
bar(610,30,640,50); 


setcolor(4); 
outtextxy(610,30,ntos(szadan,sc)); 

lsound(60,500); 
} 
}else 
return(0); 

} 
/*********************************/ 
/* 
show game message 
*/ 
/*********************************/ 
gamemessage() 
{ 
cleardevice(); 
setcolor(4); 
settextstyle(0,0,7); 
outtextxy(mx/11,my/3,"MOVING BOX"); 

settextstyle(0,0,2); 
outtextxy(mx/4,400,"Write by :Liu wenjie"); 
getch(); 
} 

lsound(int x,int l) 
{ 
sound(x); 
delay(l); 
nosound(); 



} 
 
 
