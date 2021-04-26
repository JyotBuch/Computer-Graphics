#include<iostream>
#include<graphics.h>
# define LEFT 1
# define RIGHT 4
# define TOP 8
# define BOTTOM 2

using namespace std;

int xmin, xmax, ymin, ymax;

int getRegionCode(float x, float y)//this function is used to give region code(eg:0000)
{
    int code=0;
    if (x<xmin)
        code|= LEFT;
    if (x>xmax)
        code|=RIGHT;
    if (y<ymin)
        code|=TOP;
    if (y>ymax)
        code|=BOTTOM;

    return code;
}

void midpointsubdivision(float x1, float y1, float x2, float y2)//this function is used to clip the line using midpoint subdivision method
{
    start://starting point
    int code1 = getRegionCode(x1,y1);
    int code2 = getRegionCode(x2,y2);
    if (code1==0 && code2==0)
    {
        line(x1,y1,x2,y2);
        return;
    }
    else if ((code1 & code2)!=0)
        return;

    float xm, ym;
    xm=(x1+x2)/2;
    ym=(y1+y2)/2;
    int codem = getRegionCode(xm,ym);

    if (codem!=0)
    {
        if ((code1 & codem)!=0)
        {
            x1=xm;
            y1=ym;
            goto start;
        }
        else if ((code2 & codem)!=0)
        {
            x2=xm;
            y2=ym;
            goto start;//going back to starting point
        }
    }

    int p1pm=0, pmp2=0;
    if (codem==0)
    {
        if (code1==0 && codem==0)
        {
            line(x1,y1,xm,ym);
            pmp2=1;
            goto label;
        }
        else if (code2==0 && codem==0)
        {
            line(xm,ym,x2,y2);
            p1pm=1;
            goto label;
        }
    }
    p1pm=1;
    pmp2=1;
    label:
    if (p1pm==1)
    {
        int codem1, xm1,ym1;
        do {
            xm1 = (x1+xm)/2;
            ym1 = (y1+ym)/2;
            codem1 = getRegionCode(xm1,ym1);
            if(codem1!=0)
            {
                x1=xm1;
                y1=ym1;
            }
            else
            {
                line(xm1,ym1,xm,ym);
                xm=xm1;
                ym=ym1;
            }
        }
        while (x1!=xmin && x1!=xmax && y1!=ymin && y1!=ymax);
        x1=xm;
        y1=ym;
    }

    if (pmp2==1)
    {
        int codem2, xm2, ym2;
        do {
            xm2 = (x2+xm)/2;
            ym2 = (y2+ym)/2;
            codem2 = getRegionCode(xm2,ym2);
            if(codem2!=0)
            {
                x2=xm2;
                y2=ym2;
            }
            else
            {
                line(xm2,ym2,xm,ym);
                xm=xm2;
                ym=ym2;
            }
        }
        while (x2!=xmin && x2!=xmax && y2!=ymin && y2!=ymax);
        x2=xm;
        y2=ym;
    }
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cout<<"\t\t\t\t\tComputer Graphics Assignment 5\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";

    int x1,y1,x2,y2;
    cout<<"Enter the bottom co-ordinates of window:";
    cin>>xmin;
    cout<<"Enter the left coordinates of the window:";
    cin>>ymin;
    cout<<"Enter the right coordinates of the window:";
    cin>>xmax;
    cout<<"Enter the top coordinates of the window:";
    cin>>ymax;
    rectangle(xmin, ymin, xmax, ymax);
    cout<<"Enter the coordinates(Terminal Points) of the line: ";
    cin>>x1>>y1;
    cin>>x2>>y2;
    line(x1,y1,x2,y2);
    delay(3000);
    cleardevice();
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(YELLOW);
    midpointsubdivision(x1,y1,x2,y2);

    getch();
    closegraph();
    return 0;
}
