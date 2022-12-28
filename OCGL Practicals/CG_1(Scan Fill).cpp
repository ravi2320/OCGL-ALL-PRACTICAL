#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

class point
{
	public:
		int x[20], y[20], k;
		
};

class scan : public point
{
	public:
		float slope[20], x_int[20];
		void polygon(int n);
};

void scan::polygon(int n)
{
	int i;
	float dx, dy;
	
	x[n] = x[0];
	y[n] = y[0];
	
	for(i=0; i<n; i++)
	{
		line(x[i], y[i], x[i+1], y[i+1]);
	}
	
	for(i=0; i<n; i++)
	{
		dy = y[i+1]-y[i];
		dx = x[i+1]-x[i];
		
		if(dy==0)
			slope[i] = 1;
		else if(dx==0)
			slope[i] = 0;
		else
			slope[i] = dx/dy;
	}
	//finding intersection points
	for(int p=0; p<480; p++) //consider 480 horizontal line on screen
	{
		k = 0;
		for(i=0; i<n; i++)
		{
			if(( (y[i]<=p) && (y[i+1]>p)) || ((y[i]>p) && (y[i+1]<=p) ))
			{
				x_int[k] = x[i] + slope[i]*(p-y[i]); //fill out intersection pints using formula
				k++;
			}
		}
		
		for(int j=0; j<k-1; j++)
		{
			for(int i=0; i<k-1; i++)
			{
				if(x_int[i]>x_int[i+1])
				{
					int temp = x_int[i];
					x_int[i] = x_int[i+1];
					x_int[i+1] = temp;
				}
			}
		}
		
		for(i=0; i<k; i=i+2)//fill points of line that are interior to polygon
		{
			setcolor(8);
			line(x_int[i], p, x_int[i+1], p);
			delay(10);
		}
	}
}
int main()
{
	int n, i;
	scan p;
	cout<<"\nEnter No of edges : ";
	cin>>n;
	cout<<"\nEnter Coordinates : ";
	for(i=0; i<n; i++)
	{
		cout<<"\nEnter coordinate of x"<<i+1<<" and y"<<i+1<<" : ";
		cin>>p.x[i]>>p.y[i];
	}
	int gd, gm;
	initgraph(&gd, &gm, "");
	
	p.polygon(n);
	getch();
	closegraph();
	return 0;
}