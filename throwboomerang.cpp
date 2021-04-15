#include<graphics.h>
#include<dos.h>
#include<iostream>
#include<math.h>
using namespace std;

void throwboomerang(int x1,int y1,int x2,int y2,int degree)
{

        double c = cos(degree *3.14/180);
        double s = sin(degree *3.14/180);
        degree++;
        x1 = floor(x1 * c + y1 * s);                            //Using the rotation transformation for throwing the boomerang
        y1 = floor(-x1 * s + y1 * c);
        x2 = floor(x2 * c + y2 * s);
        y2 = floor(-x2 * s + y2 * c);
        cleardevice();
        line(x1, y1 ,x2, y2);
}

void initiateBoomerang()
{
    int tx=0,ty=0,i=0,degree=0;
    int wheelRearX=0,wheelRearY=250;
    while(i<500 && degree<360)
    {
        tx=i;
        if(i==250)
            cout<<"Boomerang Launched\n";
        if(i>=250)
        {
            setcolor(YELLOW);
            throwboomerang(wheelRearX+tx,wheelRearY,wheelRearX+20+tx,wheelRearY,degree);
            degree+=2;
        }
        setcolor(GREEN);
        circle(wheelRearX+tx,wheelRearY+ty,20);                     //using the translation tranformation for moving the launcher
        i++;
        setcolor(BLUE);
        line(0,270,700,270);
        delay(15);
        cleardevice();
        setcolor(BLUE);
        line(0,270,700,270);
    }
}
int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver, &gmode,"");
    cout<<"\t\t\t\t\tComputer Graphics Assignment 5\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";
    char choice;
    cout<<"Are you ready to launch the boomerang?\n";
    cin>>choice;
    if(choice=='n')
        cout<<"K.BYE THEN.";
    else if(choice=='y')
        {
            cout<<"Getting Boomerang Ready!!!!\n";
            initiateBoomerang();
            cout<<"BOOM!\nBoomerang Successfull!\n";
        }

    getch();
    closegraph();
    return 0;
}
