#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <process.h>
#define EXCAPE 27
#define ENTER 13
main(){
int press,i,x,y,x1,y1,ch_z=0;
int dian=0;
char ch='0';   /*input + - * / */
char emp[80],sum[80],*e,*s;
double yuan=0.000000000000;
void init(void);
void clear_z(char *u);
double strtoflt(char *p);
int getkey();
int gd=DETECT, gm;
initgraph(&gd, &gm, "");
e=emp;
s=sum;
init();
x = (getmaxx() / 2) - 120;
y = (getmaxy() / 2) - 150;
x1 = (getmaxx() / 2) + 120;
y1 = (getmaxy() / 2) + 150;
while(1){
    press = getkey();
    switch(press){
      case EXCAPE:
exit(0);
      case 47:
bar (x + 10, y + 80 + 10, x + 60 - 10, y + 80 + 60 - 10);
delay(8000);
init();
if (ch!='0'){
   switch(ch){
     case '/':
       if (strtoflt(emp)==0.0){
   ch='0';
   ch_z=0;
   dian=0;
   emp[0]='\0';
   sum[0]='\0';
   e=emp;
   s=sum;
   outtextxy(x+30,y+40,"error!!!!!");
   break;
       }
       yuan = strtoflt(sum) / strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       break;
     case '*':
       yuan = strtoflt(sum) * strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       break;
     case '+':
       yuan = strtoflt(sum) + strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       break;
     case '-':
       if (strtoflt(sum)>=strtoflt(emp)){
   yuan = strtoflt(sum) - strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
       }
       else{
   yuan=strtoflt(emp)-strtoflt(sum);
   sprintf(sum,"-%0.10f",yuan);
       }
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
   }
}
        else{
   if (ch_z==0){
     outtextxy(x+30,y+40,emp);
     stpcpy(sum,emp);

   }
   else{
     outtextxy(x+30,y+40,sum);

   }
}
ch='/';
ch_z=0;
emp[0]='\0';
e=emp;
dian=0;
break;
      case 42:
bar (x + 60 + 10, y + 80 + 10, x + 60 * 2 - 10, y + 80 + 60 - 10);
delay(8000);
init();
        if (ch!='0'){
   switch(ch){
     case '/':
       yuan = strtoflt(sum) / strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '*':
       yuan = strtoflt(sum) * strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '+':
       yuan = strtoflt(sum) + strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '-':
       if (strtoflt(sum)>=strtoflt(emp)){
   yuan = strtoflt(sum) - strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
       }
       else{
   yuan=strtoflt(emp)-strtoflt(sum);
   sprintf(sum,"-%0.10f",yuan);
       }
              clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
   }
}
        else{
   if (ch_z==0){
     outtextxy(x+30,y+40,emp);
     stpcpy(sum,emp);
     e=emp;
   }
   else
     outtextxy(x+30,y+40,sum);
}
ch='*';
ch_z=0;
        dian=0;
break;
      case 45:
bar (x + 60 * 2 + 10, y + 80 + 10, x + 60 * 3 - 10, y + 80 + 60 - 10);
delay(8000);
init();
        if (ch!='0'){
   switch(ch){
     case '/':
       yuan = strtoflt(sum) / strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '*':
       yuan = strtoflt(sum) * strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '+':
       yuan = strtoflt(sum) + strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '-':
       if (strtoflt(sum)>=strtoflt(emp)){
   yuan = strtoflt(sum) - strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
       }
       else{
   yuan=strtoflt(emp)-strtoflt(sum);
   sprintf(sum,"-%0.10f",yuan);
       }
              clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
   }
}
        else{
   if (ch_z==0){
     outtextxy(x+30,y+40,emp);
     stpcpy(sum,emp);
     e=emp;
   }
   else
     outtextxy(x+30,y+40,sum);
}
ch='-';
ch_z=0;
        dian=0;
break;
      case 43:
bar (x + 60 * 3 + 10, y + 80 + 10, x + 60 * 4 - 10, y + 80 + 60 - 10);
delay(8000);
init();
        if (ch!='0'){
   switch(ch){
     case '/':
       yuan = strtoflt(sum) / strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '*':
       yuan = strtoflt(sum) * strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '+':
       yuan = strtoflt(sum) + strtoflt(emp);
       sprintf(sum,"%0.10f",yuan);
       clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
     case '-':
       if (strtoflt(sum)>=strtoflt(emp)){
   yuan = strtoflt(sum) - strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
       }
       else{
   yuan=strtoflt(emp)-strtoflt(sum);
   sprintf(sum,"-%0.10f",yuan);
       }
              clear_z(sum);
       outtextxy(x+30,y+40,sum);
       emp[0]='\0';
       e=emp;
       break;
   }
}
        else{
   if (ch_z==0){
     outtextxy(x+30,y+40,emp);
     stpcpy(sum,emp);
     e=emp;
   }
   else
     outtextxy(x+30,y+40,sum);
}
ch='+';
ch_z=0;
        dian=0;
break;
      case 49:
bar (x + 10, y + 80 + 53 + 10, x + 60 - 10, y + 80 + 53 * 2 - 4);
delay(8000);
init();
for (i=0;i<=79;i++){
   if (emp[i]=='\0')
     break;
}
if (ch_z==0){
   *e='1';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 50:
bar (x + 60 + 10, y + 80 + 53 + 10, x + 60 * 2 - 10, y + 80 + 53 * 2 - 4);
delay(8000);
init();
        for (i=0;i<=79;i++){
   if (emp[i]=='\0')
     break;
}
        if (ch_z==0){
   *e='2';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 51:
bar (x + 60 * 2 + 10, y + 80 + 53 + 10, x + 60 * 3 - 10, y + 80 + 53 * 2 - 4);
delay(8000);
init();
        for (i=0;i<=79;i++){
   if (emp[i]=='\0')
     break;
}
        if (ch_z==0){
   *e='3';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case ENTER:
bar (x + 60 * 3 + 10, y + 80 + 53 + 10, x + 60 * 4 - 10, y + 80 + 53 * 2 - 4);
delay(8000);
init();
   if (ch!='0'){
     switch(ch){
       case '/':
   yuan = strtoflt(sum) / strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
   clear_z(sum);
   outtextxy(x+30,y+40,sum);
   emp[0]='\0';
   e=emp;
   break;
       case '*':
   yuan = strtoflt(sum) * strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
   clear_z(sum);
   outtextxy(x+30,y+40,sum);
   emp[0]='\0';
   e=emp;
   break;
       case '+':
   yuan = strtoflt(sum) + strtoflt(emp);
   sprintf(sum,"%0.10f",yuan);
   clear_z(sum);
   outtextxy(x+30,y+40,sum);
   emp[0]='\0';
   e=emp;
   break;
       case '-':
   if (strtoflt(sum)>=strtoflt(emp)){
    yuan = strtoflt(sum) - strtoflt(emp);
    sprintf(sum,"%0.10f",yuan);
   }
   else{
    yuan=strtoflt(emp)-strtoflt(sum);
    sprintf(sum,"-%0.10f",yuan);
   }
   clear_z(sum);
   outtextxy(x+30,y+40,sum);
   emp[0]='\0';
   e=emp;
   break;
     }
   }
   else{
     if (ch_z==0){
       outtextxy(x+30,y+40,emp);
       stpcpy(sum,emp);
       e=emp;
     }
     else{
       outtextxy(x+30,y+40,sum);
     }
   }
ch='0';
ch_z=1;
        dian=0;
break;
      case 52:
bar (x + 10, y + 80 + 53 * 2 + 10, x + 60 - 10, y + 80 + 53 * 3 - 4);
delay(8000);
init();
if (ch_z==0){
   *e='4';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 53:
bar (x + 60 + 10, y + 80 + 53 * 2 + 10, x + 60 * 2 - 10, y + 80 + 53 * 3 - 4);
delay(8000);
init();
        if (ch_z==0){
   *e='5';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 54:
bar (x + 60 * 2 +10, y + 80 + 53 * 2 + 10, x + 60 * 3 - 10, y + 80 + 53 * 3 - 4);
delay(8000);
init();
        if (ch_z==0){
   *e='6';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 46:
bar (x + 60 * 3 + 10, y + 80 + 53 * 2 + 10, x + 60 * 4 - 10, y + 80 + 53 * 3 - 4);
delay(8000);
init();
if (dian==0){
   if (ch_z==0){
     *e='.';e++;*e='\0';
     outtextxy(x+30,y+40,emp);
   }
   else{
     outtextxy(x+30,y+40,sum);
   }
}
else{
   if (ch_z==0)
     outtextxy(x+30,y+40,emp);
   else
     outtextxy(x+30,y+40,sum);
}
dian=1;
break;
      case 55:
bar (x + 10, y + 80 + 53 * 3 + 10, x + 60 - 10, y + 80 + 53 * 4 - 4);
delay(8000);
init();
        if (ch_z==0){
   *e='7';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 56:
bar (x + 60 + 10, y + 80 + 53 * 3 + 10, x + 60 * 2 -10, y + 80 + 53 * 4 - 4);
delay(8000);
init();
        if (ch_z==0){
   *e='8';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 57:
bar (x + 60 * 2 + 10, y + 80 + 53 * 3 + 10, x + 60 * 3 - 10, y + 80 + 53 * 4 - 4);
delay(8000);
init();
if (ch_z==0){
   *e='9';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 48:
bar (x + 60 * 3 + 10, y + 80 + 53 * 3 + 10, x + 60 * 4 - 10, y + 80 + 53 * 4 - 4);
delay(8000);
init();
if (ch_z==0){
   *e='0';e++;*e='\0';
   outtextxy(x+30,y+40,emp);
}
else{
   outtextxy(x+30,y+40,sum);
}
break;
      case 32:
emp[0]='\0';
sum[0]='\0';
e=emp;
s=sum;
ch='0';
ch_z=0;
dian=0;
init();
break;
      case 8:
delay(8000);
for(i=0;i<=79;i++){
   if (emp[i]=='\0')
     break;
}
if (i==0)
   break;
if (i!=79&&i!=0){
   i--;
   emp[i]='\0';
   e=&emp[i];
}
init();
outtextxy(x+30,y+40,emp);
break;
    }
}
}
/*---------------------------------------------------------------------*/
void init(void){
int x, y, x1, y1, i, j;
char emp;
x = (getmaxx() / 2) - 120;
y = (getmaxy() / 2) - 150;
x1 = (getmaxx() / 2) + 120;
y1 = (getmaxy() / 2) + 150;
cleardevice();
setbkcolor(3);
setfillstyle(1, 15);
setcolor(15);
settextstyle(1,0,1);
rectangle (x, y, x1, y1);
rectangle (x - 7, y - 7, x1 + 7, y1 + 7);
rectangle (x + 10, y + 10, x1 - 10, y + 80 - 10);
line (x, y + 80, x1, y + 80);
y = y + 80;
for (j = 1; j <= 4; j++){
    x = (getmaxx() / 2) - 120;
    for (i = 1; i <= 4; i++){
      /* bar (x + 10, y + 10, x + 60 - 10, y + 60 - 10);*/
      rectangle(x + 10, y + 10, x + 60 - 10, y + 60 - 10);
      if (j == 1){
if (i == 1)
   outtextxy(x + 20, y + 20, "/");
if (i == 2)
   outtextxy(x + 25, y + 20, "*");
if (i == 3)
   outtextxy(x + 27, y + 20, "-");
if (i == 4)
   outtextxy(x + 25, y + 20, "+");
      }
      if (j == 2){
if (i == 1)
   outtextxy(x + 25, y + 20, "1");
if (i == 2)
   outtextxy(x + 25, y + 20, "2");
if (i == 3)
   outtextxy(x + 25, y + 20, "3");
if (i == 4)
   outtextxy(x + 25, y + 20, "=");
      }
      if (j == 3){
if (i == 1)
   outtextxy(x + 25, y + 20, "4");
if (i == 2)
   outtextxy(x + 25, y + 20, "5");
if (i == 3)
   outtextxy(x + 25, y + 20, "6");
if (i == 4)
   outtextxy(x + 25, y + 20, ".");
      }
      if (j == 4){
if (i == 1)
   outtextxy(x + 25, y + 20, "7");
if (i == 2)
   outtextxy(x + 25, y + 20, "8");
if (i == 3)
   outtextxy(x + 25, y + 20, "9");
if (i == 4)
   outtextxy(x + 25, y + 20, "0");
      }
      x = x + 60;
    }
    y = y + 53;
}
}
/*---------------------------------------------------------------------*/
int getkey(){
char lowbyte;
int press;
while(bioskey(1)==0);
press = bioskey(0);
press = press&0xff? press&0xff: press>>8;

return(press);

}
double strtoflt(char *p)
{
double rtl=0.000000000000;
double pnt=0.000000000000;
double t = 10;
int ispoint = 0;
while (*p!='\0'||*p!='.'){
    if(*p<'0'||*p>'9')
      break;
    rtl*=10;
    rtl+=*p-'0';
    p++;
}
if (*p=='.'){
    ispoint=1;
    p++;
}
while(ispoint&&*p!='\0'){
    pnt+=(double)(*p-'0')/t;
    t*=10;
    p++;
}
rtl+=pnt;
return (rtl);
}
/*-----------------------------------------------------------------------*/
void clear_z(char u[]){
int i;
for(i=strlen(u)-1;i>=0;i--){
    if (u[i]!='0')
      break;
}
if (u[i]=='.'){
    u[i]='\0';
}
else{
    i++;
    u[i]='\0';
}
}
