#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>

#define ROUND(a) {(int)(a+0.5)}

using namespace std;

void init(int vertex[10][3],int n);
void rotation(int vertex[10][3],int n);
void translate(int vertex[10][3],int n);
void shear(int vertex[10][3],int n);
void reflection(int vertex[10][3],int n);
void scaling(int vertex[10][3],int n);
void draw_Line(int x1,int y1,int x2,int y2,int clr);
void plot1(int x0,int y0,int x1,int y1,int clr);
void plot2(int x0,int y0,int x1,int y1,int clr);


void draw_Line(int x1,int y1,int x2,int y2,int clr)
{
    if(abs(y2-y1) < abs(x2-x1))
            {
                //abs(slope)<1
                if(x1>x2) //always drawn from left to right i.e. xinc is +1
                    plot1(x2,y2,x1,y1,clr);
                else
                    plot1(x1,y1,x2,y2,clr);
            }
            else
            {
                //abs(slope)>1
                if(y1>y2) //always bottom to top i.e. yinc is +1
                    plot2(x2,y2,x1,y1,clr);
                else
                    plot2(x1,y1,x2,y2,clr);

            }

}

void plot1(int x0,int y0,int x1,int y1,int clr)
{
    int X,Y,dx,dy,p,yinc;
    dx=x1-x0;
    dy=y1-y0;
    yinc=1;
    if(dy<0)
    {
        yinc=-1;
        dy=-dy;
    }
    p=(2*dy)-dx;
    Y=y0;
    for(X=x0;X<=x1;X++)
    {
        putpixel(X,Y,clr);
        if(p>0)
        {
            Y+=yinc;
            p=p+(2*(dy-dx));
        }
        else
            p=p+2*dy;
    }

}

void plot2(int x0,int y0,int x1,int y1,int clr)
{
    int X,Y,dx,dy,p,xinc;
    dx=x1-x0;
    dy=y1-y0;
    xinc=1;
    if(dx<0)
    {
        xinc=-1;
        dx=-dx;
    }
    p=(2*dx)-dy;
    X=x0;
    for(Y=y0;Y<=y1;Y++)
    {
        putpixel(X,Y,clr);
        if(p>0)
        {
            X+=xinc;
            p=p+(2*(dx-dy));
        }
        else
            p=p+2*dx;
    }
}
void init()
{
    int gd=DETECT,gm,i;
    initgraph(&gd,&gm,"");


    draw_Line(0,240,640,240,YELLOW);       //drawing X axis
    draw_Line(320,0,320,480,YELLOW);       //drawing Y axis

}

void initpolygon(int vertex[10][3],int n)
{
    /*int gd=DETECT,gm,i;
    initgraph(&gd,&gm,"");


    drawLine(0,240,640,240,YELLOW);       //drawing X axis
    drawLine(320,0,320,480,YELLOW);       //drawing Y axis*/


    for(int i=0; i<n-1; i++)
    {
        draw_Line(320+vertex[i][0],240-vertex[i][1],320+vertex[i+1][0],240-vertex[i+1][1],3);
    }
    draw_Line(320+vertex[n-1][0],240-vertex[n-1][1],320+vertex[0][0],240-vertex[0][1],3);

}

void translate(int vertex[10][3],int n)
{
    int tx,ty,i;
    cout<<"\nEnter the translation vector [tx ty]:";
    cin>>tx>>ty;

    for(i=0; i<n-1; i++)
    {
        draw_Line(320+(vertex[i][0]+tx), 240-(vertex[i][1]+ty), 320+(vertex[i+1][0]+tx), 240-(vertex[i+1][1]+ty),GREEN);//Translating every vertex w.r.t thr translation factor and the axis we are using in this graph
    }
    draw_Line(320+(vertex[n-1][0]+tx), 240-(vertex[n-1][1]+ty), 320+(vertex[0][0]+tx), 240-(vertex[0][1]+ty),GREEN);// this is done to draw the line between the last and the first node
}

void rotation(int vertex[10][3],int n)
{
    float rotate[3][3];
    float theta;
    cout<<"\nEnter the angle of rotation (theta): ";
    cin>>theta;
    theta = (theta*3.14)/180;
    rotate[0][0]= cos(theta);
    rotate[0][1]= -sin(theta);
    rotate[0][2]= 0;
    rotate[1][0]= sin(theta);
    rotate[1][1]= cos(theta);
    rotate[1][2]= 0;
    rotate[2][0]= 0;
    rotate[2][1]= 0;
    rotate[2][2]= 1;

    int i,j,k;
    int res[10][3];

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            res[i][j]=0;
            for(k=0; k<3; k++)
            {
                res[i][j] = res[i][j] + vertex[i][k]*rotate[k][j];
            }
        }
    }

    for(i=0; i<n-1; i++)
    {
        draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
    }
    draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);

}

void shear(int vertex[10][3],int n)
{
    int shx,shy;

    cout<<"\nEnter the shearing vector [SHx SHy]:";
    cin>>shx>>shy;

    float shear_array[3][3];

    shear_array[0][0]=1;
    shear_array[0][1]=shx;
    shear_array[0][2]=0;
    shear_array[1][0]=shy;
    shear_array[1][1]=1;
    shear_array[1][2]=0;
    shear_array[2][0]=0;
    shear_array[2][1]=0;
    shear_array[2][2]=1;

    int i,j,k;
    int res[10][3];

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            res[i][j]=0;
            for(k=0; k<3; k++)
            {
                res[i][j] = res[i][j] + vertex[i][k]*shear_array[k][j];
            }
        }
    }

    for(i=0; i<n-1; i++)
    {
        draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
    }
    draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);

}

void reflection(int vertex[10][3], int n)
{
    int choice;
    boolean ans=true;
    while(ans){cout<<"\nPress 1 for reflecting on x axis\nPress 2 for reflecting on y axis\nPress 3 for reflecting on origin \n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        int x_reflect[3][3];
        x_reflect[0][0]=1;
        x_reflect[0][1]=0;
        x_reflect[0][2]=0;
        x_reflect[1][0]=0;
        x_reflect[1][1]=-1;
        x_reflect[1][2]=0;
        x_reflect[2][0]=0;
        x_reflect[2][1]=0;
        x_reflect[2][2]=1;

        int i,j,k;
        int res[10][3];

        for(i=0; i<n; i++)
        {
            for(j=0; j<3; j++)
            {
                res[i][j]=0;
                for(k=0; k<3; k++)
                {
                    res[i][j] = res[i][j] + vertex[i][k]*x_reflect[k][j];
                }
            }
        }

        for(i=0; i<n-1; i++)
        {
            draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
        }
        draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);
        break;
    case 2:
        int y_reflect[3][3];
        y_reflect[0][0]=-1;
        y_reflect[0][1]=0;
        y_reflect[0][2]=0;
        y_reflect[1][0]=0;
        y_reflect[1][1]=1;
        y_reflect[1][2]=0;
        y_reflect[2][0]=0;
        y_reflect[2][1]=0;
        y_reflect[2][2]=1;

        //int i,j,k;
        //int res[10][3];

        for(i=0; i<n; i++)
        {
            for(j=0; j<3; j++)
            {
                res[i][j]=0;
                for(k=0; k<3; k++)
                {
                    res[i][j] = res[i][j] + vertex[i][k]*y_reflect[k][j];
                }
            }
        }

        for(i=0; i<n-1; i++)
        {
            draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
        }
        draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);
        break;
    case 3:
        int o_reflect[3][3];
        o_reflect[0][0]=-1;
        o_reflect[0][1]=0;
        o_reflect[0][2]=0;
        o_reflect[1][0]=0;
        o_reflect[1][1]=-1;
        o_reflect[1][2]=0;
        o_reflect[2][0]=0;
        o_reflect[2][1]=0;
        o_reflect[2][2]=1;

        //int i,j,k;
        //int res[10][3];

        for(i=0; i<n; i++)
        {
            for(j=0; j<3; j++)
            {
                res[i][j]=0;
                for(k=0; k<3; k++)
                {
                    res[i][j] = res[i][j] + vertex[i][k]*o_reflect[k][j];
                }
            }
        }

        for(i=0; i<n-1; i++)
        {
            draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
        }
        draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);
        break;
    default:
        cout<<"Invalid choice";
        ans=false;
        break;
    }
    }
}

void scaling(int vertex[10][3], int n)
{
    int scx,scy;

    cout<<"\nEnter the scaling vector [SCx SCy]:";
    cin>>scx>>scy;

    float scaling_array[3][3];

    scaling_array[0][0]=scx;
    scaling_array[0][1]=0;
    scaling_array[0][2]=0;
    scaling_array[1][0]=0;
    scaling_array[1][1]=scy;
    scaling_array[1][2]=0;
    scaling_array[2][0]=0;
    scaling_array[2][1]=0;
    scaling_array[2][2]=1;

    int i,j,k;
    int res[10][3];

    for(i=0; i<n; i++)
    {
        for(j=0; j<3; j++)
        {
            res[i][j]=0;
            for(k=0; k<3; k++)
            {
                res[i][j] = res[i][j] + vertex[i][k]*scaling_array[k][j];
            }
        }
    }

    for(i=0; i<n-1; i++)
    {
        draw_Line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1],15);
    }
    draw_Line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1],15);
}


int main()
{
    int i,x,y;
    int vertex[10][3],n;

    init();

    cout<<"\nEnter the number of vertices : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter the points (x y): ";
        cin>>x>>y;
        vertex[i][0]=x;
        vertex[i][1]=y;
        vertex[i][2]=1;
    }

    initpolygon(vertex,n);

     int ch;
    cout<<"Enter your choice for 2D transformation:\n";
    cout<<"1.Translation\n2.Shearing\n3.Rotation\n4.Reflection\n5.Scaling\n";
    cout<<"Choice:";
    cin>>ch;

    switch(ch)
    {
    case 1:
        translate(vertex,n);
        break;
    case 2:
        shear(vertex,n);
        break;
    case 3:
        rotation(vertex,n);
        break;
    case 4:
        reflection(vertex,n);
        break;
    case 5:
        scaling(vertex,n);
        break;
    default:
        cout<<"Invalid Choice";
        break;
    }

    getch();
    closegraph();
}
