#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<iostream.h>
main()
{
int gd=DETECT,gm,x=295,y=222,a,j,i;
initgraph(&gd,&gm,"c:\tc\bgi");
setcolor(14);
outtextxy(x-10,y,"AJAY");
while(!kbhit())
{
i++;

delay(1);
setcolor(16);
circle(x+(200*cos(i)),y+(200*sin(i)),8);
setcolor(10);
circle(x+(200*cos(i+40)),y+(200*sin(i+40)),8);
//set2
setcolor(16);
circle(x+(160*sin(i)),y+(160*cos(i)),7); //anti clockwise:-sin,cos
interchanged
circle(x+(160*sin(i)),y+(160*cos(i)),5);
setcolor(i);
circle(x+(160*sin(i+40)),y+(160*cos(i+40)),7);
circle(x+(160*sin(i+40)),y+(160*cos(i+40)),5);

setcolor(16);
circle(x+(120*sin(i)),y+(120*cos(i)),6);//anti clockwise:-sin,cos
interchanged
setcolor(12);
circle(x+(120*sin(i+40)),y+(120*cos(i+40)),6);

setcolor(16);
circle(x+(90*cos(i)),y+(90*sin(i)),5);
setcolor(i);
circle(x+(90*cos(i+40)),y+(90*sin(i+40)),5);
}
getch();
return 0;
}
