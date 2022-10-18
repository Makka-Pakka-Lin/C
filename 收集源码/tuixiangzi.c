# include "conio.h" 
# include "graphics.h" 

char map[12][19]={{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}, 
  {'.','.','.','.','#','#','#','#','#','#','#','#','#','#','#','.','.','.','.'}, 
  {'.','.','.','.','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#','.','.','.','.'}, 
  {'.','.','.','.','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','.','.','.','.'}, 
  {'.','.','.','.','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','.','.','.','.'}, 
  {'.','.','.','.','#','#','#','#','#',' ','#','#','#','#','#','.','.','.','.'}, 
  {'.','.','.','.','.','.','.','#',' ',' ',' ','#','.','.','.','.','.','.','.'}, 
  {'.','.','.','.','.','.','.','#',' ',' ',' ','#','.','.','.','.','.','.','.'}, 
  {'.','.','.','.','.','.','.','#',' ',' ',' ','#','.','.','.','.','.','.','.'}, 
  {'.','.','.','.','.','.','.','#',' ',' ',' ','#','.','.','.','.','.','.','.'}, 
  {'.','.','.','.','.','.','.','#','#','#','#','#','.','.','.','.','.','.','.'}, 
                  {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'} 
}; 

struct move_point 
{ 
int x,y; 
}man; 

int num; 
int step=0; 
int xi=0,re=0; 

void draw() 
{ 
gotoxy(man.x,man.y); 
printf("%c\b",2); 
} 

void clr() 
{ 
gotoxy(man.x,man.y); 
printf(" \b"); 
} 

void drawmap() 
{ 
 int i,j; 
 gotoxy(0,0); 
 for(i=0;i<12;i++) 
{for(j=0;j<19;j++) 
    printf("%c",map[i][j]); 
 printf("\n"); 
} 
} 

int BI(int x,int y) 
{ 
if(map[y-1][x-1]=='#'||map[y-1][x-1]==15) return 1; 
else return 0; 
} 

int XI_W(int x,int y) 
{ 
if(map[y-1][x-1]==15&&BI(x,y-1)==0) {map[y-1][x-1]=' '; 
     map[y-2][x-1]=15; 
     xi=1; 
     gotoxy(x,y-1); 
     printf("%c",15); 
     return 0; 
    } 
if(map[y-1][x-1]==' ') {xi=2;return 0;} 
return 1; 
} 

int XI_A(int x,int y) 
{ 
if(map[y-1][x-1]==15&&BI(x-1,y)==0) {map[y-1][x-1]=' '; 
     map[y-1][x-2]=15; 
     xi=1; 
     gotoxy(x-1,y); 
     printf("%c",15); 
     return 0; 
    } 
if(map[y-1][x-1]==' ') {xi=2;return 0;} 
return 1; 
} 

int XI_S(int x,int y) 
{ 
if(map[y-1][x-1]==15&&BI(x,y+1)==0) {map[y-1][x-1]=' '; 
     map[y][x-1]=15; 
     xi=1; 
     gotoxy(x,y+1); 
     printf("%c",15); 
     return 0; 
    } 
if(map[y-1][x-1]==' ') {xi=2;return 0;} 
return 1; 
} 

int XI_D(int x,int y) 
{ 
if(map[y-1][x-1]==15&&BI(x+1,y)==0) {map[y-1][x-1]=' '; 
     map[y-1][x]=15; 
     xi=1; 
     gotoxy(x+1,y); 
     printf("%c",15); 
     return 0; 
    } 
if(map[y-1][x-1]==' ') {xi=2;return 0;} 
return 1; 
} 

void draw_des() 
{ 
num=6; 
if(map[6][10]==' ') gotoxy(11,7),printf("+");else num--; 
if(map[7][10]==' ') gotoxy(11,8),printf("+");else num--; 
if(map[8][10]==' ') gotoxy(11,9),printf("+");else num--; 
if(map[9][10]==' ') gotoxy(11,10),printf("+");else num--; 
if(map[8][8]==' ')  gotoxy(9,9),printf("+");else num--; 
if(map[8][9]==' ')  gotoxy(10,9),printf("+");else num--; 
if(num==0) gotoxy(23,12),printf("You are very clever!"),getch(),exit(0); 
} 

void draw_step() 
{ 
gotoxy(38,6); 
 printf("%d",step); 
} 

void draw_biaoge() 
{ 
line(170,0,170,200); 
line(0,200,340,200); 
line(170,60,340,60); 
line(340,0,340,200); 
line(0,205,345,205); 
line(345,0,345,205); 
line(165,0,165,200); 
line(260,60,260,160); 
line(170,5,340,5); 
line(170,160,340,160); 
} 

void FAN() 
{ 
switch(re) 
{case 1:clr();man.y++;draw();if(xi==1) 
     {map[man.y-3][man.x-1]=' '; 
      map[man.y-2][man.x-1]=15; 
      gotoxy(man.x,man.y-2); 
      printf(" "); 
      gotoxy(man.x,man.y-1); 
      printf("%c\b",15); 
     } 
     break; 
 case 2:clr();man.x++;draw();if(xi==1) 
     {map[man.y-1][man.x-3]=' '; 
      map[man.y-1][man.x-2]=15; 
      gotoxy(man.x-2,man.y); 
      printf(" "); 
      gotoxy(man.x-1,man.y); 
      printf("%c\b",15); 
     } 
     break; 
 case 3:clr();man.y--;draw();if(xi==1) 
     {map[man.y+1][man.x-1]=' '; 
      map[man.y][man.x-1]=15; 
      gotoxy(man.x,man.y+2); 
      printf(" "); 
      gotoxy(man.x,man.y+1); 
      printf("%c\b",15); 
     } 
                                     break; 
 case 4:clr();man.x--;draw();if(xi==1) 
     {map[man.y-1][man.x+1]=' '; 
      map[man.y-1][man.x]=15; 
      gotoxy(man.x+2,man.y); 
      printf(" "); 
      gotoxy(man.x+1,man.y); 
      printf("%c\b",15); 
     } 
                                     break; 
} 
re=0; 
xi=0; 
} 

main() 
{ 
int driver=DETECT,mode; 
char ch; 
man.x=12; 
man.y=4; 
map[3][6]=15; 
map[3][7]=15; 
map[3][8]=15; 
map[3][9]=15; 
map[3][10]=15; 
map[3][12]=15; 

clr(); 
registerbgidriver(EGAVGA_driver); 
initgraph(&driver,&mode,""); 
setbkcolor(GREEN); 
drawmap(); 
draw_des(); 
draw_step(); 
draw(); 
draw_biaoge(); 

gotoxy(25,5); 
printf("w:UP"); 
gotoxy(25,6); 
printf("a:LEFT"); 
gotoxy(25,7); 
printf("s:DOWN"); 
gotoxy(25,8); 
printf("d:RIGHT"); 
gotoxy(25,9); 
printf("r:QUIT"); 
gotoxy(25,10); 
printf("f:REGRET"); 
gotoxy(35,5); 
printf("step:"); 
gotoxy(27,3); 
printf("BAN YUN GONG"); 

for(;;) 
{ 
if(kbhit()) 
{ 
ch=getch(); 
if(ch=='r') break; 
switch(ch) 
{ 
case 'w':if(XI_W(man.x,man.y-1)==1) break; 
  clr(); 
  step++; 
  man.y--; 
  re=1; 
  draw_des(); 
  draw_step(); 
  draw(); 
  break; 
case 'a':if(XI_A(man.x-1,man.y)==1) break; 
  clr(); 
  step++; 
  man.x--; 
  re=2; 
  draw_des(); 
  draw_step(); 
  draw(); 
  break; 
case 's':if(XI_S(man.x,man.y+1)==1) break; 
  clr(); 
  step++; 
  man.y++; 
  re=3; 
  draw_des(); 
  draw_step(); 
  draw(); 
  break; 
case 'd':if(XI_D(man.x+1,man.y)==1) break; 
  clr(); 
  step++; 
  man.x++; 
  re=4; 
  draw_des(); 
  draw_step(); 
  draw(); 
  break; 
case 'f':if(re==0) break; 
 else FAN();break; 
default:break; 
} 
} 
} 
}  
 
