
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<dos.h>

void floodFill(int x,int y,int oldcolor,int newcolor)
{
	if(getpixel(x,y) == oldcolor)
	{
		putpixel(x,y,newcolor);
		floodFill(x+1,y,oldcolor,newcolor);
		floodFill(x,y+1,oldcolor,newcolor);
		floodFill(x-1,y,oldcolor,newcolor);
		floodFill(x,y-1,oldcolor,newcolor);
	}
}

int main()
{
	int gm,gd=DETECT,radius;
	int x,y;

	printf("Enter x position for circle:");
	scanf("%d",&x);
	printf("Enter y position for circle:");
	scanf("%d",&y);
	printf("Enter radius of circle:");
	scanf("%d",&radius);

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	circle(x,y,radius);
	floodFill(x,y,0,15);
	delay(5000);
	closegraph();

	return 0;
}
