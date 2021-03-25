#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main()
{
	//This program uses the Bresenham's Line drawing Algorithm
	int gd = DETECT,gm;
	//initialize the variables
	int x1, y1, x2, y2, dx, dy, p;
	//initilize graphics 
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//get values
	cout<<"Enter values of x1 and y1"<<endl;
	cin>>x1>>y1;
	cout<<"Enter values of x2 and y2"<<endl;
	cin>>x2>>y2;
	//Bresenham's Algorithm
	dx=x2-x1;
	dy=y2-y1;
	p=2*abs(dy)-abs(dx);
	putpixel(x1,y1,3);
	for(int i=0;i<=dx-1;i++)
	{
		if(p<0)
		{
			x1+=1;
			putpixel(x1,y1,3);
			p+=(2*abs(dy));
		}
		else
		{
			x1+=1;
			y1+=1;
			putpixel(x1,y1,3);
			p+=(2*abs(dy)-2*abs(dx));
		}
	}
	getch();
	closegraph();
}