#include<iostream>
#include<graphics.h>
using namespace std;

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
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int x,y,r;
    cout<<"\n\n\nBoundary Fill ALGORITHM\n\n\n";
    cout<<"Enter x position of circle : ";
    cin>>x;
    cout<<"Enter y position of circle : ";
    cin>>y;
    printf("Enter radius of circle:");
	cin>>r;

	circle(x,y,r);
	floodFill(x,y,0,15);


	//rectangle(150,250,450,350);
	//floodFill(151,251,0,15);
    delay(5000);

    getch();
    closegraph();

    return 0;
}
