#include<graphics.h>
#include<dos.h>
#include<iostream>
#include<math.h>

using namespace std;

void translateclouds(int tx)
{
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    ellipse(120-tx,105,0,180,30,25);
    ellipse(150-tx,130,285,90,40,30);
    ellipse(135-tx,160,210,360,25,30);
    ellipse(100-tx,150,180,300,30,30);
    ellipse(90-tx,130,85,235,30,25);

    ellipse(420-tx+500,105,0,180,30,25);
    ellipse(450-tx+500,130,285,90,40,30);
    ellipse(435-tx+500,160,210,360,25,30);
    ellipse(400-tx+500,150,180,300,30,30);
    ellipse(390-tx+500,130,85,235,30,25);

    ellipse(420-tx+700,105,0,180,30,25);
    ellipse(450-tx+700,130,285,90,40,30);
    ellipse(435-tx+700,160,210,360,25,30);
    ellipse(400-tx+700,150,180,300,30,30);
    ellipse(390-tx+700,130,85,235,30,25);

    ellipse(420+300-tx,105,0,180,30,25);
    ellipse(450+300-tx,130,285,90,40,30);
    ellipse(435+300-tx,160,210,360,25,30);
    ellipse(400+300-tx,150,180,300,30,30);
    ellipse(390+300-tx,130,85,235,30,25);

    ellipse(420+100-tx,105,0,180,30,25);
    ellipse(450+100-tx,130,285,90,40,30);
    ellipse(435+100-tx,160,210,360,25,30);
    ellipse(400+100-tx,150,180,300,30,30);
    ellipse(390+100-tx,130,85,235,30,25);

    ellipse(320-tx,105,0,180,30,25);
    ellipse(350-tx,130,285,90,40,30);
    ellipse(335-tx,160,210,360,25,30);
    ellipse(300-tx,150,180,300,30,30);
    ellipse(290-tx,130,85,235,30,25);
}

void translatewheels(int tx,int ty)
{
    circle(45+tx,415-ty,5);
    //circle(22+tx,415,5);
    circle(90+tx,415-ty,5);
}

void translateplanewings(int tx,int ty)
{
    line(50+tx,400-ty,70+tx,400-ty);//visible wings
    line(50+tx,400-ty,30+tx,415-ty);
    line(70+tx,400-ty,30+tx,415-ty);

    line(50+tx,395-ty,70+tx,395-ty);//wings on the other side
    line(50+tx,395-ty,30+tx,380-ty);
    line(70+tx,395-ty,30+tx,380-ty);

    line(0+tx,395-ty,0+tx,381-ty);//tail
    line(0+tx,381-ty,20+tx,395-ty);
}

void translateplanebody(int tx,int ty)
{
    rectangle(0+tx,395-ty,100+tx,410-ty);
}

int main()
{
    int gdriver = DETECT,gmode;
    initgraph(&gdriver, &gmode,"");

    cout<<"\t\t\t\t\tComputer Graphics Assignment 5\t\n";
    cout<<"\t\t\t\t\tJyot Buch 201900182\n\n";
    char choice;
    cout<<"Prepared to take off?\n";
    cin>>choice;
    int tx=0,ty=0,j=0;
    if(choice=='y')
    {
        for (int i=0;i<300;i++)
        {
            j+=0;
            setcolor(YELLOW);
            translateplanewings(i,j);
            translateplanebody(i,j);
            translatewheels(i,j);
            translateclouds(i);
            delay(10);
            cleardevice();
            setcolor(GREEN);
            line(0,420,640,420);  //Runway
        }

        for (int i=300;i<630;i++)
        {
            setcolor(YELLOW);
            if(i==300)
                cout<<"LIFT OFF\n";
            j+=1;
            if(i<400)
                translatewheels(i,j);
            if(i==400)
                cout<<"Gears Up\n";
            translateplanewings(i,j);
            translateplanebody(i,j);
            translateclouds(i);
            delay(10);
            cleardevice();
            setcolor(GREEN);
            line(0,420,640,420);  //Runway
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
