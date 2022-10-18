 /*************************************************
name :泡泡 
writer: 刘文杰 
date :2005-10 
这是一个模拟泡泡堂的游戏 
有二个玩家操作  
**************************************************/ 
#include<graphics.h>/*用到的库函数*/ 
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<bios.h> 
#include<dos.h> 
#define ESC 0x011b /*定义所使用到的键值*/ 
#define UP1 0x1177 
#define DOWN1 0x1f73 
#define LEFT1 0x1e61 
#define RIGHT1 0x2064 
#define UP2 0x4800 
#define DOWN2 0x5000 
#define LEFT2 0x4b00 
#define RIGHT2 0x4d00 
#define Z 0x2c7a 
#define DEL 0x5300 
#define ENTER 0x1c0d 
#define SPACE 0x3920 

#define MX 21 /*每行的方块数*/ 
#define MY 16 /*每列的方块数*/ 
#define BOXLONG 30 /*方块的长度*/ 


typedef struct/*定义游戏 中人的结构体*/ 
{int x; 
int y;/*人的位置*/ 
int definetime; /*是否可以炸弹定时*/ 
int maxball;/*最多可以放多少炸弹*/ 
int power;/*炸弹爆炸的长度，也就是威力*/ 
int ballnum;/*现在放了多少炸弹*/ 
}human; 


typedef struct/*定义炸弹的数据结构，用来存值储敏个炸弹的信息*/ 
{ 
int used;/*该炸弹是否使用*/ 
int x; 
int y;/*炸弹位置*/ 
int man;/*谁放的炸弹*/ 
int page;/*当前炸弹是第几帧，用来产生炸弹的动态效果*/ 
int time;/*炸弹放置的时间*/ 
}tball; 


tball ball[10];/*定义10个炸弹*/ 
human man[2];/*定义2个人*/ 
void *tu[13];/*定义13个指向图像的指针，用来指向游戏中需要的图像*/ 


int map[MX][MY];/*定义存储屏莫信息的数组*/ 
int ballnum=0;/*用来保存当前所放炸弹的总个数*/ 

/*********************************** 
游戏中用到的自定义函数 
功能在函数定义处介绍 
***********************************/ 

/*
viod initgra();
int message(char *s);
viod draw();
viod initgame();
viod ZaLine(int x1,int y1,int num);
viod HuanYuan(int x1,int y1,int num);
viod BaoZa(int num);
viod PutZaDan(int mann);
viod DrawZaDan();
viod CheckZaDan();
viod DefineZa(int n);
viod move(int x1 ,int y1,int mann );
viod GameOver();

 */
/*这个函数用来，初始化屏幕*/
initgra()
{int dr=DETECT,mode=0;
registerbgidriver(EGAVGA_driver);

initgraph(&dr,&mode,""); 

} 



/*********************************** 
这个函数用来，向游戏中产生一个信息对话框 

参数为一个字符型指针 

返回值为一个整型数据 
如果按键为 “n” 
返回0 
否则返回 1 
*********************************/ 
int message(char *s) 
{ char c; 
setfillstyle(1,4); 
setcolor(1); 
settextstyle(0,0,3); 
bar(640/2-200,480/2-50,640/2+250,480/2+50); 
outtextxy(640/2-200,480/2-20,s); 
c=getch(); 
sleep(2); 
if(c=='n'|| c=='N')return(0);else return(1); 

} 



/**************************************** 


用库函数绘出游戏中所用到的图像，保存到开的中空间中  

**************************************/ 
draw() 
{int i=0; 
cleardevice(); 
for (i=0;i<13;i++) if(i!=6) tu[i]=malloc(imagesize(0,0,29,29)); 
/*因为六号指针用的是炸弹第四帧的图像，报以不用分配空间*/ 

/*把一个空白图像存到0号空间中*/ 

getimage(0,0,29,29,tu[0]); 

/*下面是画出产生炸弹的动态效果的四个图像到1~4 号空间中*/ 

setcolor(4); 
setfillstyle(1,4); 
for(i=0;i<4;i++) 
{ 
fillellipse(15,15,7+i*2,7+i*2); 
getimage(0,0,29,29,tu[i+1]); 
} 

putimage(0,0,tu[4],1);/*清除图像，以绘新图*/ 

/*画定时器的图像并存到5号空间中*/ 
 
 
setcolor(12); 
line(3,5,20,25); 
line(20,25,28,5); 
line(28,5,3,5); 
fillellipse(16,15,4,4); 
getimage(0,0,29,29,tu[5]); 
putimage(0,0,tu[5],1); 

tu[6]=tu[4];/*六号空存的是炸弹图像，吃了可以增加放的炸弹数，*/ 
  /*所以真接使用炸弹第四帧的图像*/ 



/*把闪电图像存到7号空间中*/ 

setcolor(4); 
setlinestyle(0,0,3); 
line(20,2,7,16); 
line(20,2,16,12); 
line(16,12,24,13); 
line(7,16,15,15); 
line(15,15,8,29); 
line(24,13,8,29); 
getimage(0,0,29,29,tu[7]); 
putimage(0,0,tu[7],1); 

/*把模拟爆炸效果的图像存到8号空间中*/ 

for(i=0;i<200;i++) 
putpixel(random(30),random(30),random(16)); 
getimage(0,0,29,29,tu[8]); 
putimage(0,0,tu[8],1); 



/*把可推动的箱子图像存到9号空间中*/ 

setcolor(1); 
setfillstyle(1,14); 
bar(1,1,28,28); 
setcolor(1); 
line(15,1,15,10); 
line(1,10,28,10); 
line(1,20,29,20); 
line(15,20,15,28); 
getimage(0,0,29,29,tu[9]); 
putimage(0,0,tu[9],1); 

/*把不可推动的箱子图像存到10号空间中*/ 

setcolor(9); 
setfillstyle(1,12); 
bar3d(1,1,26,26,1,1); 
getimage(0,0,29,29,tu[10]); 
putimage (0,0,tu[0],0); 


/*把第一个人脸图像存到11号空间中*/ 

setlinestyle(0,0,3); 
setcolor(4); 
circle(15,15,13); 
circle(8,13,4); 
circle(24,13,4); 
line(11,18,17,15); 
line(11,18,15,19); 
setlinestyle(0,0,3); 
arc(15,15,225,320,9); 
getimage(0,0,29,29,tu[11]); 
putimage(0,0,tu[11],1); 

/*把第二个人脸图像存到11号空间中*/ 

setlinestyle(0,0,3); 
setcolor(1); 
circle(15,15,13); 
circle(8,13,4); 
circle(24,13,4); 
line(11,18,17,15); 
line(11,18,15,19); 
setlinestyle(0,0,3); 
arc(15,15,225,320,9); 
getimage(0,0,29,29,tu[12]); 
putimage(0,0,tu[12],1); 


} 


/*************************** 
初始化游戏 
并产生随机地图 
****************************/ 
initgame() 
{int i,j; 
cleardevice(); 

randomize(); 

/*清空所有炸弹*/ 
for(i=0;i<10;i++) ball[i].used=0; 
/*先把屏幕信息数组初始化什为100*/ 
for (i=0;i<22;i++) 
for (j=0;j<16;j++) 
map[i][j]=100; 
/*先把屏幕信息数组人的位置，始初化，每次都不变*/ 


man[0].x=0; 
man[0].y=0; 
man[0].maxball=1; 
man[0].ballnum=0; 
man[0].power=2; 

man[0].definetime=0; 
man[1].x=MX-1; 
man[1].y=MY-1; 
man[1].maxball=1; 
man[1].ballnum=0; 
man[1].power=2; 
man[1].definetime=0; 
map[0][0]=11; 
map[0][1]=0; 
map[1][0]=0; 
map[MX-1][MY-1]=12; 
map[MX-1][MY-2]=0 ; 
map[MX-2][MY-1]=0; 
/*把人的图输出*/ 

putimage(0,0,tu[11],1); 

putimage(600,15*30,tu[12],0); 

/*下面产生随机地图*/ 
for (i=0;i<21;i++) 
for (j=0;j<16;j++) 
{ if (map[i][j]!=100) continue; 

if (random(1000)%2==0||random(1000)%6==0) 
{ 
map[i][j]=9; 
putimage(i*30,j*30,tu[9],0); 
}else if(random(1000)%2==0||random(1000)%5==0) 
{map[i][j]=10; 
putimage(i*30,j*30,tu[10],0); 
}else 
map[i][j]=0; 
} 


} 




/*************************************** 
向一个方向产生爆炸效果 
参数num是要爆炸的炸弹编号 
x1,y1 炸的方向 
0,1 是向下 
0,-1 向上
－1,0 向左
1,0 向右

****************************************/

ZaLine(int x1,int y1,int num)
{int x,y,x2,y2,i,l,j;
x=ball[num].x;/* 取出炸弹位置 */
y2=ball[num].y;

l=man[ball[num].man].power;/* 炸弹爆炸的长度 */
for(i=0,j=0;abs(i)<l&&abs(j)<l;i+=x1,j+=y1)/*如果没有到指定长度 */


 { x=x2+i;
 y=y2+j;/* 当前烽到的位置位置 */


if(x<0||x>20||y<0||y>15) return 0;/* 如果超出屏幕范围，退出函数执行 */

 if ((x==man[0].x&&y==man[0].y)||(x==man[1].x&&y==man[1].y))/* 如果炸到了人 */
{  if (!(x==man[0].x&&y==man[0].y))/* 如果不是一号 */
message("the red win!");/* 显示红色玩家胜的信息 */
  else
message("the green win!");/* 显示篮色玩家胜的信息 */

gameover();/* 结束游戏 */

}else if(map[x][y]==0)/* 如果为空 */

{ putimage((x)*30,(y)*30,tu[8],0);/*放爆炸效果图 */

}else if(map[x][y]==9)/* 如果为可推箱子 */

{ putimage((x)*30,(y)*30,tu[0],0);/* 清去原始图像*/

putimage((x)*30,(y)*30,tu[8],0);/*放爆炸效果图 */
if (random(1000)%4==0) /*产生爆东西的效果*/
{ int r;
r=random(3)+5;
if(r>7)r--;
map[x][y]=r;
}
else map[x][y]=0;
return 0;/* 因为炸到了东西，所以停止爆炸 */
}else if (map[x][y]>=20) BaoZa(map[x][y]%10);/* 如果烽到炸弹，继续炸 */

else if (map[x][y]==10) return 0;/* 如果如是是炸不动箱子，停止爆炸 */

else/* 如果是其它肯定是那三个，以吃的东西，就是闪电，定时器，和炸弹，所以炸掉，结束爆炸 */
{ putimage((x)*30,(y)*30,tu[0],0);
putimage((x)*30,(y)*30,tu[8],0);
if (random(1000)%3==0)
map[x][y]=random(3)+5;
else
map[x][y]=0;
  return(0);
}
}/* end of for */
}/* end of ZaLine*/

/**************************************
爆炸后清理爆炸现场
参数和Zaline()一样
把爆炸爆出的东西显示出来
并把爆炸效果图清去 
**********************************/ 
HuanYuan(int x1,int y1,int num) 
{ 
int x,y,x2,y2,l,i,j; 
x2=ball[num].x; 
y2=ball[num].y; 
l=man[ball[num].man].power; 

for(i=0,j=0;abs(i)<l&&abs(j)<l;i+=x1,j+=y1) 
{x=x2+i;y=y2+j; 
if(x<0||x>20||y<0||y>15)return 0; 
if(map[x][y]==0) 
{ putimage((x)*30,(y)*30,tu[0],0); 
map[x][y]=0; 
}else if (map[x][y]>=5&&map[x][y]<=7) 
{ putimage(x*30,y*30,tu[0],0); 
putimage(x*30,y*30,tu[map[x][y]],0); 
}else return 0; 


} 
} 

/************************ 
 利用ZALINE() 和huanyuan()函数 
产生爆炸效果 
******************************/ 
BaoZa(int num) 
{ 
map[ball[num].x][ball[num].y]=0;/* 清去游戏信息数组里的数据*/ 
man[ball[num].man].ballnum--;/* 使该人的当前放的炸弹数减1 */ 
ballnum--;/* 使前放的总炸弹数减1 */ 
ball[num].used=0;/*使编号炸弹改作末使用 */ 
/* 爆炸 */ 
ZaLine(-1,0,num); 
ZaLine(1,0,num); 
ZaLine(0,-1,num); 
ZaLine(0,1,num); 

delay(10000);/* 延时*/ 
/*还原现场*/ 

HuanYuan(-1,0,num); 
HuanYuan(1,0,num); 
HuanYuan(0,-1,num); 
HuanYuan(0,1,num); 


/*end of for */ 

} 
/*************************** 
放一个炸弹 
参数为放炸弹 的人的编 号 
**************************/ 

PutZaDan(int mann) 
{ 
int i; 
struct time s; 
gettime(&s);/* 取当前时间*/ 
if (ballnum>9 || man[mann].ballnum>=man[mann].maxball) return 0; 
/* 如果当前总炸弹 数>9或人的当前放轩的炸弹数>＝他的最大放弹数，结束函数执行*/ 


ballnum++;/* 使当前放的总炸弹数加1 */ 
man[mann].ballnum++;/* 使该人的当前放的炸弹数加1 */ 
for (i=0;i<10;i++) if (ball[i].used==0)break;/* 找当前末使用的炸弹 */ 
ball[i].man=mann;/* 设置炸弹信息*/ 
ball[i].time=s.ti_sec; 
ball[i].x=man[mann].x; 
ball[i].y=man[mann].y; 
ball[i].page=1; 
ball[i].used=1; 
 
 /* 在屏幕上放一个炸弹，位置为放弹人的位置 */ 
putimage(ball[i].x*30,ball[i].y*30,tu[1],0); 
map[ball[i].x][ball[i].y]=20+i; 
} 
/*********************** 
产生炸弹的动态显示 
*************************/ 

DrawZaDan() 
{int i; 
for (i=0;i<10;i++) 
{ if (ball[i].used==0)continue;/* 如果炸弹末使用继续循环*/ 
if (ball[i].page<4)/* 如果炸弹帧数<4，帧数加1，直接在炸弹位置放下一帧*/ 
{ball[i].page++; 
putimage(ball[i].x*30,ball[i].y*30,tu[ball[i].page],0); 
} 
else/* 把帧数置为1，清去原图，绘第一帧*/ 
{ball[i].page=1; 
putimage(ball[i].x*30,ball[i].y*30,tu[0],0); 
putimage(ball[i].x*30,ball[i].y*30,tu[1],0); 
} 
} 
} 
/***************************** 
检查是否有该炸的炸弹 
如果有则引爆它 
****************************/ 
CheckZaDan() 
{ 
int i,t; 
struct time t1; 
gettime(&t1); 
t=t1.ti_sec; 
for (i=0;i<10;i++) 
if (ball[i].used==1&&(t+60-ball[i].time)%60>=2&&man[ball[i].man].definetime==0) BaoZa(i); 
} 

/*********************** 
 定时器引爆炸弹  
参数为引爆人的编号 
*************************/ 
DefineZa(int n) 
{ 
int i; 
if (man[n].definetime==0) return 0; 
for (i=0;i<10;i++) 
if (ball[i].used==1&&ball[i].man==n)BaoZa(i); 

} 

/*************************** 
产生人的移动效果 

其中包括吃东西，推箱子等功能 

参数x1,y1为移动的方向  
和zaline()相同 
mann为要移动人的编号 
****************************/ 


 move(int x1 ,int y1,int mann ) 
{ 
int fx ,fy,x,y;/*x,y 为现在的位置，fx,fy,存放要移动到的位置*/ 

x=man[mann].x;/*取要移动人的位置*/ 
y=man[mann].y; 

fx=x+x1;/*要移动到 的位置为*/ 
fy=y+y1; 

if ((fx>=0&&fx<MX&&fy>=0&&fy<MY))/*要移动到的位置是否在允许范围内*/ 

{ switch(map[fx][fy]) 
{ case 0:/*如果要移动到的位置为空*/ 

putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 

break; 
case 5:/*如果要移动到的位置为定时器*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].definetime=1; 
break; 
  case 6:/*如果要移动到的位置为爆出的炸弹*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].maxball++; 
break; 

  case 7:/*如果要移动到的位置为闪电，则*/ 
putimage(x*BOXLONG,y*BOXLONG,tu[0],0); 
putimage(fx*BOXLONG,fy*BOXLONG,tu[11+mann],0); 
man[mann].power++; 
break; 

case 9:/*如果要移动到的位置为可推的箱子，产生推箱效果*/ 
 if(x+x1*2>=0&&x+x1*2<MX&&y+y1*2>=0&&y+y1*2<MY&&map[x+x1*2][y+y1*2]==0) 
{putimage((x+x1*2)*BOXLONG,(y+y1*2)*BOXLONG,tu[9],0); 
putimage((fx)*BOXLONG,(fy)*BOXLONG,tu[0],0); 
putimage((fx)*BOXLONG,(fy)*BOXLONG,tu[mann+11],0); 
putimage(x*30,y*30,tu[0],0); 
map[x+x1*2][y+y1*2]=9; 
map[fx][fy]=mann+11; 
map[x][y]=0; 

break;} 
default:return 0; 
}/* end of switch*/ 
/*移动完毕，修改屏幕数组信息*/  
map[x][y]=0; 
map[fx][fy]=11+mann; 
/*修改移动人的信息*/ 
man[mann].x=fx; 
man[mann].y=fy; 
}/*end of if 范围*/ 

}/* end of funtion*/ 

GameOver() 
{ int i; 
/*释放内存空间*/ 
for(i=0;i<13;i++) if (i!=6) free(tu[i]); 
/*关闭图形显示模式*/ 
closegraph(); 
/*结束程序*/ 
exit(1); 
} 


main() 
{ 

int key=0,oldtime=0;/*K用来保存按键值，oldtime用来计时*/ 
struct time t1;/*定义一个时间型结构体*/ 


initgra();/*屏幕初始化*/ 
draw();/*绘图并保存图像*/ 
initgame();/*游戏初始化*/ 


while(1) 
{if (bioskey(1)==0)/*没有按键*/ 

 { /*每90百分秒，检测一次炸弹是否到爆炸时间，并重绘一次炸弹，产生动态效果*/ 

gettime(&t1); 
if(t1.ti_hund+100-oldtime>90) 

{ 
CheckZaDan(); 
DrawZaDan(); 

} 

 }else{
/*根据按键值，执行相应功能数*/

key=bioskey(0); 
switch(key) 
{case UP1: move(0,-1,0);break; 
case DOWN1: move(0,1,0);break; 
case LEFT1: move(-1,0,0);break; 
case RIGHT1:move(1,0,0);break; 
case UP2:move(0,-1,1);break; 
case DOWN2:move(0,1,1);break; 
case LEFT2:move(-1,0,1);break; 
case RIGHT2:move(1,0,1);break; 
case ENTER:PutZaDan(1);break; 
case SPACE:PutZaDan(0);break; 
case Z:DefineZa(0);break; 
case DEL:DefineZa(1);break; 
case ESC: GameOver();break; 

} 

 } 

 } 

} 
 
 
