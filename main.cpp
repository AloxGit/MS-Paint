#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int n=3;
POINT cursorPosition;

void brush(int x, int y)
{
    for(int i=1; i<=n; i++)
    {
        circle(x-2,y-25,i);
    }
}

void myline(double x1, double y1, double x2, double y2)
{
    int x, y, temp;
    double dx, dy;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if((dx/dy)>1)
    {
        if(x2<x1)
        {
            temp=x2;
            x2=x1;
            x1=temp;
            temp=y2;
            y2=y1;
            y1=temp;
        }
        for(x=x1; x<=x2; x++)
        {
            y=y1+((x-x1)/(x2-x1))*(y2-y1);
            brush(x, y);
        }
    }

    else
    {
        if(y2<y1)
        {
            temp=y2;
            y2=y1;
            y1=temp;
            temp=x2;
            x2=x1;
            x1=temp;
        }
        for(y=y1; y<=y2; y++)
        {
            x=x1+((y-y1)/(y2-y1))*(x2-x1);
            brush(x, y);
        }
    }
}

void nbrush(int col)
{
    int px, py;
    GetCursorPos(&cursorPosition);
    px=cursorPosition.x;
    py=cursorPosition.y;
    setcolor(col);
    while(1)
        {
            GetCursorPos(&cursorPosition);
            myline(px, py, cursorPosition.x, cursorPosition.y);
            px=cursorPosition.x;
            py=cursorPosition.y;

            if(GetAsyncKeyState(VK_LBUTTON))
            {
                break;
            }
        }
}

void oldbrush(int col)
{
    while(1)
    {
        GetCursorPos(&cursorPosition);
        setcolor(col);
        brush(cursorPosition.x,cursorPosition.y);

        if(GetAsyncKeyState(VK_LBUTTON))
        {
            break;
        }
    }
}


int main(void)
{
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode, i, j;
    int xmax, ymax;


    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

    /* read result of initialization */
    errorcode = graphresult();
    /* an error occurred */
    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }
    setbkcolor(15);

    setcolor(getmaxcolor());
    xmax = getmaxx();
    ymax = getmaxy();

    char ch;
    circle(320,240,320);
    floodfill(240,320,15);


    while(1)
    {
        if(kbhit())
        {
            ch=getch();
            if(ch==49)
            {
                nbrush(0);
            }

            if(ch==50)
            {
                nbrush(14);
            }

            if(ch==51)
            {
                nbrush(9);
            }

            if(ch==52)
            {
                nbrush(10);
            }

            if(ch==53)
            {
                nbrush(11);
            }

            if(ch==54)
            {
                nbrush(12);
            }

            if(ch==55)
            {
                nbrush(13);
            }

            if(ch==8)
            {
                nbrush(15);
            }

            if(ch==61)
            {
                n++;
            }

            if(ch==45)
            {
                n--;
                if(n<=1)
                    n==1;
            }
        }
    }


    getch();
    closegraph();
    return 0;
}
