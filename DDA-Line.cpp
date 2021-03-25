#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
void main()
{
	//This program uses Digital Differential Analyzer to draw a line on the screen
	int gd = DETECT,gm;
	//initialize the variables
	int x1, y1, x2, y2, dx, dy, steps, xinc, yinc;
	//initilize graphics 
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	//get values
	cout<<"Enter values of x1 and y1"<<endl;
	cin>>x1>>y1;
	cout<<"Enter values of x2 and y2"<<endl;
	cin>>x2>>y2;
	//DDA algorithm
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	xinc=dx/steps;
	yinc=dy/steps;
	for(int i=0;i<steps;i++)
	{
		putpixel(x1,y1,3);
		x1+=xinc;
		y1+=yinc;	
	}
	getch();
	closegraph();	
}