#include<stdio.h>
#include<stdlib.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'


char picture[HEIGHT][WIDTH];
void clearPicture()
{
    int i,j;
    for(i=0;i<HEIGHT;i++)
        {
            for(j=0;j<WIDTH;j++)
                {
                    picture[i][j]=EMPTY;

}
        }
}
void displayPicture()
{
    int i,j;
for(i=0;i<HEIGHT;i++)
{
for(j=0;j<WIDTH;j++)
{
printf("%c", picture[i][j]);
}
printf("\n");
}
}
void setPixel(int x, int y)
{
    if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
{
picture[y][x]=PIXEL;
}
}
void drawLine(int x1,int y1,int x2,int y2)
{
int dx=abs(x2-x1);
int dy=abs(y2-y1);
int steps=(dx>dy)?dx:dy;
if(steps==0)
{
setPixel(x1,y1);
return;
}
float xInc=(float)(x2-x1)/steps;
float yInc=(float)(y2-y1)/steps;
float x=x1;
float y=y1;
int i;
for(i=0;i<=steps;i++)
{
setPixel((int)(x+0.5), (int)(y+0.5));
x += xInc;
y += yInc;
}
}
void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1, y1, x2, y1);
drawLine(x2, y1, x2, y2);
drawLine(x2, y2, x1, y2);
drawLine(x1, y2, x1, y1);
}
void drawCircle(int cX, int cy, int radius)
{
    int x,y;
for(x=-radius;x<=radius;x++)
{
for(y=-radius;y<=radius;y++)
{
int d=x*x+y*y;
int r=radius*radius;
if(d>=r - radius && d<=r+radius)
{
setPixel(cX + x,cy + y);
}
}
}
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
drawLine(x2, y2, x3, y3);
drawLine(x3, y3, x1, y1);
}
int main()
{
    int choice;
clearPicture();
printf("2D Graphics Editor\n");
printf("Canvas size: %d x %d\n", WIDTH, HEIGHT);
printf("Use coordinates x y.\n");
printf("x range: 0 to %d\n", WIDTH - 1);
printf("y range: 0 to %d\n", HEIGHT - 1);
