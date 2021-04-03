#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void BoundaryFill4(int x,int y,int fill, int boundary)
{
    int current;
    current = getpixel(x,y);
    if ((current!=boundary)&&(current!=fill))
    {
        /* code */
        setcolor(fill);
        putpixel(x,y,fill);
        BoundaryFill4(x+1,y,fill,boundary);
        BoundaryFill4(x-1,y,fill,boundary);
        BoundaryFill4(x,y+1,fill,boundary);
        BoundaryFill4(x,y-1,fill,boundary);
    }
    

}

void main()
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

    BoundaryFill4(x,y,4,15);
    delay(5000);

    getch();
    closegraph();

}