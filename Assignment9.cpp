#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdio.h>

using namespace std;

int maxx,maxy,midx,midy; //global variables

void rotation(int left,int top,int right,int bottom,int depth)
{

    int x1,y1,x2,y2;

    cleardevice();


    outtextxy(100,200,"Rotation");

    float ang;
    cout<<"Enter your angle of rotation : ";
    cin>>ang;

    setcolor(WHITE);

    line(midx,0,midx,maxy);
    line(0,midy,maxx,midy);


    setcolor(RED);



    bar3d(midx+left,midy-top,midx+right, midy-bottom, depth, 5);



    delay(2000);

    cleardevice();
    x1=left*cos(ang*3.14/180)-top*sin(ang*3.14/180);
    y1=left*sin(ang*3.14/180)+top*sin(ang*3.14/180);
    x2=right*cos(ang*3.14/180)-bottom*sin(ang*3.14/180);
    y2=right*sin(ang*3.14/180)+bottom*sin(ang*3.14/180);

    setcolor(WHITE);

    line(midx,0,midx,maxy);
    line(0,midy,maxx,midy);

    setcolor(YELLOW);



    outtextxy(100,200,"After Rotating");

    bar3d(midx+x1,midy-y1,midx+x2,midy-y2,depth,5);

    //bar3d(x1,y1,x2,y2,depth,5);
}

void scale(int left,int top,int right,int bottom,int depth)
{
    cleardevice();

    float x,y,z;

    cout<<"\nEnter the Scaling factor(x y z) : ";
    cin>>x>>y>>z;

    setcolor(WHITE);


    outtextxy(100,200,"Scaling");


    line(midx,0,midx,maxy);
    line(0,midy,maxx,midy);


    setcolor(YELLOW);

    line(0,maxy,maxx,0);

    bar3d(midx+left,midy-top,midx+right, midy-bottom, depth, 5);



    delay(2000);

    cleardevice();

    setcolor(WHITE);

    line(midx,0,midx,maxy);

    outtextxy(100,200,"After Scaling");

    setcolor(YELLOW);



    bar3d(midx+(x*left),midy-(y*top),midx+(x*right),midy-(y*bottom),depth*z,5);
}


int main()
{
    cout<<"\t\t\t\t\tComputer Graphics Assignment 9\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";
    int gd,gm;


    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "");
    setfillstyle(5,2);
    maxx=getmaxx();
    maxy=getmaxy();
    midx=maxx/2;
    midy=maxy/2;
    line(midx,0,midx,maxy);
    line(0,midy,maxx,midy);
    setcolor(YELLOW);

    int left,right,top,bottom,depth;

    while(true)
    {
        cout<<"Enter your leftmost point : ";
        cin>>left;

        cout<<"Enter your rightmost point : ";
        cin>>right;

        cout<<"Enter your topmost point : ";
        cin>>top;

        cout<<"Enter your lowest point : ";
        cin>>bottom;

        cout<<"Enter your depth : ";
        cin>>depth;

        bar3d(midx+left,midy-top,midx+right, midy-bottom, depth, 5);

        cout<<"\nPress 1 for Rotation\nPress 2 for Scaling\n";

        int x;

        cin>>x;

        switch(x)
        {
            case 1: cleardevice();
                    rotation(left,top,right,bottom,depth);
                    break;

            case 2: cleardevice();
                    scale(left,top,right,bottom,depth);
                    break;

            default: ExitProcess(1);
            break;
        }

    }

    getch();
    closegraph();
    return 0;
}
