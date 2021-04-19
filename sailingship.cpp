#include<graphics.h>
#include<dos.h>
#include<iostream>
#include<math.h>

using namespace std;

void translateshipbody(int tx)
{
    setcolor(YELLOW);
    line(10+tx,350,40+tx,400);
    line(10+tx,350,250+tx,350);
    line(250+tx,350,220+tx,400);
    line(40+tx,400,220+tx,400);

}

void translateshipgoods(int tx)
{
    setcolor(RED);
    rectangle(15+tx,300,100+tx,350);
    setcolor(GREEN);
    rectangle(100+tx,300,150+tx,350);
    setcolor(WHITE);
    rectangle(150+tx,300,220+tx,350);
}

int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver, &gmode,"");
    char choice='y';
    int tx=0,ty=0,j=0;
    if(choice=='y')
    {
        for (int i=0;i<630;i++)
        {
            setcolor(YELLOW);

            translateshipbody(i);
            translateshipgoods(i);
            delay(10);
            cleardevice();
            setcolor(BLUE);
            line(0,400,640,400);  //sea
            if(i==625)
            {
                cout<<"Bon Voyage";

            }
        }
    }
    else
        cout<<"K.COOL>BYE";
    getch();
    closegraph();
    return 0;
}
