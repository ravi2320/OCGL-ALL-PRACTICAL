#include<graphics.h>
int main()
{
	int gd=0,gm,x=20,flag=0,y=200,uplimit=250;
	initgraph(&gd,&gm,"C:\\Tc\\BGI");
	while(!kbhit())
	{
		setcolor(5);
		line(0,400,700,400);
		if(flag==0)
		{
			y+=2;
			x+=1;
			if(y>=385)
				flag=1;
		}
		if(flag==1)
		{
			y-=2;
			x+=1;
			if(y<=uplimit)
			{
				flag=0;
				uplimit+=20;
			}
		}
		setcolor(15);
		fillellipse(x,y,15,15);
		delay(15);
		setcolor(0);
		setfillstyle(1,7);
		fillellipse(x,y,15,15);
		cleardevice();
	}
	return 0;
}
