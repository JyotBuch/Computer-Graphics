#include<iostream.h>
#include<graphics.h>
#include<conio.h>
 
void main()
{
	int gdriver=DETECT, gmode, error, x0, y0, r;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 
	cout<<"Enter radius of circle: ";
	cin>>r;
 
	cout<<"Enter co-ordinates of center(x and y): ";
	cin>>x0>>y0;
	//drawcircle(x, y, r);

	int x=0,y=r;
	int p=1-r;

	while(x<=y)
	{
		//everytime you find a point, it is plotted in all 8  quadrants
		putpixel(x0 + x, y0 + y, 7);
		putpixel(x0 + y, y0 + x, 7);
		putpixel(x0 - y, y0 + x, 7);
		putpixel(x0 - x, y0 + y, 7);
		putpixel(x0 - x, y0 - y, 7);
		putpixel(x0 - y, y0 - x, 7);
		putpixel(x0 + y, y0 - x, 7);
		putpixel(x0 + x, y0 - y, 7);

		if(p<0)
		{
			p+=(2*x)+3;
			x+=1;
		}
		else if(p>=0)
		{
			p+=(2*x)-(2*y)+5;
			x+=1;
			y-=1;
		}
	}
	getch();
	closegraph();
}