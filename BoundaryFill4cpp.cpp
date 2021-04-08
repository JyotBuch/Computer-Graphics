#include<iostream>
#include<graphics.h>
using namespace std;

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
    BoundaryFill4(x,y,4,15);
    delay(5000);

    getch();
    closegraph();

    return 0;
}
