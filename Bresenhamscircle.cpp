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

    int x=0, y=r;
    int p=3-2*r;

    /*dA=((x+1-x0)*(x+1-x0))+(y-y0)*((y-y0));
    dB=((x+1-x0)*(x+1-x0))+((y-1-y0)*(y-1-y0));

    delA=delA-(r*r);
    delB=delB-(r*r);*/

    //p=delA+delB;

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
            p+=4*x+6;
            x+=1;
        }
        else if(p>=0)
        {
            p+=4*x-4*y+10;
            x+=1;
            y-=1;
        }
    }
	getch();
	closegraph();
}