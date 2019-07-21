#include <bits/stdc++.h>
using namespace std;

const int d[4][2]={
	{1,0},{0,1},
	{-1,0},{0,-1}
};

const char pos[15][15]={
	"RIGHT",
	"DOWN",
	"LEFT",
	"UP"
};

int x=1,y=1,i=0;
char sta[15];

inline bool check(int i)
{
	if (x+d[i][0]<1||y+d[i][1]<1) return false;
	printf("LOOK %s\n",pos[i]);fflush(stdout);
	scanf("%s",sta);
	if (sta[0]=='S') return true;
	return false;
}

inline bool Go(int i)
{
	printf("GO %s\n",pos[i]);fflush(stdout);
	x+=d[i][0];y+=d[i][1];
	scanf("%s",sta);
	if (sta[0]=='N') return false;
	return true;
}

int main()
{
	while (true)
	{
		int dir=(i+1)%4;
		while (!check(dir)) dir=(dir+3)%4;
		i=dir;
		if (Go(i)) break;
	}
	return 0;
}