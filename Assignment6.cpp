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

//Cohen Sutherland Algorithm
/*#include<iostream>

#include<graphics.h>
typedef unsigned int outcode;//defining structure outcode
enum{TOP=0x1,BOTTOM=0x2,RIGHT=0x4,LEFT=0x8};// It is used to assign names to the integral constants which makes a program easy to read and maintain

using namespace std;

outcode CompOutCode(double ,double ,double ,double ,double ,double );//initialzing function of structure that recieves double values as paarmeters and returns integer as outcode
void cohensalgo(double x0,double y0,double x1,double y1,double xmin,double xmax,double ymin,double ymax)
{

    outcode outcode0,outcode1,outcodeout;
    boolean accept=FALSE, done=FALSE;
    outcode0=CompOutCode(x0,y0,xmin,xmax,ymin,ymax);
    outcode1=CompOutCode(x1,y1,xmin,xmax,ymin,ymax);
    cout<<"outcode0="<<outcode0<<endl;
    cout<<"outcode1="<<outcode1<<endl;
    do
    {
        if(outcode0==0 && outcode1==0)                      //checks if both points lie inside the line
        {
            accept=TRUE;
            done=TRUE;
        }
        else if(outcode0 & outcode1)                        //performs the and logical operator on the two outcodes
            {                                               //if it results to 0000 then the line is partially visible
                done=TRUE;                                  //inside the window
            }
            else
            {
                double x,y;
                int ocd=outcode0 ? outcode0:outcode1;
                if(ocd & TOP)                               //checks if the line intersects at the top of the window
                {
                    x=x0+(x1-x0)*(ymax-y0)/(y1-y0);         //getting intersection points
                    y=ymax;
                }
                else if(ocd & BOTTOM)                       //checks if the line intersects at the bottom of the window
                {
                    x=x0+(x1-x0)*(ymin-y0)/(y1-y0);         //getting intersection points
                    y=ymin;
                }
                else if(ocd & LEFT)                         //checks if the line intersects at the left of the window
                {
                    y=y0+(y1-y0)*(xmin-x0)/(x1-x0);         //getting intersection points
                    x=xmin;
                }
                else
                {
                    y=y0+(y1-y0)*(xmax-x0)/(x1-x0);         //checks if the line intersects at the right of the window and getting the intersection points
                    x=xmax;
                }
                if(ocd==outcode0)
                {
                    x0=x;
                    y0=y;
                    outcode0=CompOutCode(x0,y0,xmin,xmax,ymin,ymax);//gets the outcode of the new intersection points
                }
                else
                {
                    x1=x;
                    y1=y;
                    outcode1=CompOutCode(x1,y1,xmin,xmax,ymin,ymax);
                }
            }

    }while(done==FALSE);

    if(accept==TRUE)
    {
        line(x0,y0,x1,y1);
    }
}

outcode CompOutCode(double x,double y,double xmin,double xmax,double ymin,double ymax)
{
    outcode code=0;
    if(y>ymax)
        code|=TOP;
    if(y<ymin)
        code|=BOTTOM;
    if(x>xmax)
        code|=RIGHT;
    if(x<xmin)
        code|=LEFT;
    return code;
}

int main()
{
    string ch;
    double xmin,xmax,ymin,ymax,x1,y1,x2,y2;

    initwindow(500,600);

    cout<<"\t\t\t\t\tComputer Graphics Assignment 5\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";

    cout<<"Enter the bottom co-ordinates of window:";
    cin>>xmin;
    cout<<"Enter the left coordinates of the window:";
    cin>>ymin;
    cout<<"Enter the right coordinates of the window:";
    cin>>xmax;
    cout<<"Enter the top coordinates of the window:";
    cin>>ymax;
    setcolor(WHITE);
    rectangle(xmin,ymin,xmax,ymax);

    cout<<"Enter the coordinates(Terminal Points) of the line: ";
    cin>>x1>>y1;
    cin>>x2>>y2;
    line(x1,y1,x2,y2);

    delay(5000);
    cleardevice();
    setcolor(RED);
    cohensalgo(x1,y1,x2,y2,xmin,xmax,ymin,ymax);
    setcolor(WHITE);
    rectangle(xmin,ymin,xmax,ymax);
    delay(50000);

    closegraph();
}
*/
