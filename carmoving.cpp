#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

using namespace std;

void translatecarbody(int tx)
{
    line(50+tx,370,90+tx,370);
        arc(110+tx,370,0,180,20);
        line(130+tx,370,220+tx,370);
        arc(240+tx,370,0,180,20);
        line(260+tx,370,300+tx,370);
        line(300+tx,370,300+tx,350);
        line(300+tx,350,240+tx,330);
        line(240+tx,330,200+tx,300);
        line(200+tx,300,110+tx,300);
        line(110+tx,300,80+tx,330);
        line(80+tx,330,50+tx,340);
        line(50+tx,340,50+tx,370);
}

void translatewheels(int tx)
{
    circle(110+tx,370,17);
    circle(240+tx,370,17);
}

int main()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    cout<<"\t\t\t\t\tComputer Graphics Assignment 5\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";


    char choice;
    cout<<"Do you want to drive the car?\n";
    cin>>choice;
    if(choice=='y')
    {
        for (int i=0;i<500;i++)
        {
            setcolor(GREEN);
            translatecarbody(i);
            translatewheels(i);
            delay(10);
            cleardevice();
            setcolor(YELLOW);
            line(0,390,640,390);  //ROAD
        }
    }
    else
        cout<<"K.COOL>BYE";
    getch();
    return 0;
}
