#include <bits/stdc++.h>
using namespace std;

int x,y,dx,dy,fx,fy,n;
char f[3];
int act[100][2];

int movex(char f)
{
	n=0;
	if (fx==0) return 0;
	if (fx==1)
	{
		if (f=='S')
		{
			act[++n][0]=0;
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='O')
		{
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='N') act[++n][0]=0;
		act[++n][0]=1;
		act[n][1]=dx-x;
	}
	else
	{
		if (f=='N')
		{
			act[++n][0]=0;
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='E')
		{
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='S') act[++n][0]=0;
		act[++n][0]=1;
		act[n][1]=x-dx;
	}
	return n;
}

int movey(char f)
{
	n=0;
	if (fy==0) return 0;
	if (fy==1)
	{
		if (f=='E')
		{
			act[++n][0]=0;
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='S')
		{
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='O') act[++n][0]=0;
		act[++n][0]=1;
		act[n][1]=dy-y;
	}
	else
	{
		if (f=='O')
		{
			act[++n][0]=0;
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='N')
		{
			act[++n][0]=0;
			act[++n][0]=0;
		}
		if (f=='E') act[++n][0]=0;
		act[++n][0]=1;
		act[n][1]=y-dy;
	}
	return n;
}

int main()
{
	scanf("%d %d %s",&x,&y,f);
	scanf("%d %d",&dx,&dy);
	if (dx<x) fx=-1;
	else if (dx==x) fx=0;
	else fx=1;
	if (dy<y) fy=-1;
	else if (dy==y) fy=0;
	else fy=1;
	int xy=movex(f[0]);
	if (!xy) xy+=movey(f[0]);
	else if (fx==-1) xy+=movey('O');
	else xy+=movey('E');
	int yx=movey(f[0]);
	if (!yx) yx+=movex(f[0]);
	else if (fy==-1) yx+=movex('S');
	else yx+=movex('N');
	if (xy<yx)
	{
		printf("%d\n",xy);
		xy=movex(f[0]);
		for (int i=1;i<=n;i++)
		{
			if (act[i][0]) printf("A %d\n",act[i][1]);
			else printf("D\n");
		}
		if (!xy) movey(f[0]);
		else if (fx==-1) movey('O');
		else movey('E');
		for (int i=1;i<=n;i++)
		{
			if (act[i][0]) printf("A %d\n",act[i][1]);
			else printf("D\n");
		}
	}
	else
	{
		printf("%d\n",yx);
		yx=movey(f[0]);
		for (int i=1;i<=n;i++)
		{
			if (act[i][0]) printf("A %d\n",act[i][1]);
			else printf("D\n");
		}
		if (!yx) yx+=movex(f[0]);
		else if (fy==-1) yx+=movex('S');
		else yx+=movex('N');
		for (int i=1;i<=n;i++)
		{
			if (act[i][0]) printf("A %d\n",act[i][1]);
			else printf("D\n");
		}
	}
	return 0;
}