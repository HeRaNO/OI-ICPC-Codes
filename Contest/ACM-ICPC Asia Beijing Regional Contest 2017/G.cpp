#include <bits/stdc++.h>
using namespace std;

const int d[8][2]={
	{-1,0},{1,0},{0,1},{0,-1},
	{-1,-1},{-1,1},{1,-1},{1,1}
};

struct point
{
	int x,y;
	point(){}
	point(int _,int __):x(_),y(__){}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
};

inline int dot(point p,point q){return p.x*q.x+p.y*q.y;}
inline int cross(point p,point q){return p.x*q.y-p.y*q.x;}

point p[3];
char g[25][25],x[100];
int n;
bool fl[25][25];
queue <point> q;

inline int f(int x,int y){return x*n+y;}

inline bool judge(int x,int y)
{
	if (g[y][x]=='#') return false;
	return 0<=x&&x<n&&0<=y&&y<n&&!fl[x][y];
}

inline bool in(point a)
{
	int t1=cross(a-p[0],p[1]-a);
	int t2=cross(a-p[1],p[2]-a);
	int t3=cross(a-p[2],p[0]-a);
	if (!t1||!t2||!t3) return false;
	if (t1<0&&t2<0&&t3<0) return true;
	if (t1>0&&t2>0&&t3>0) return true;
	return false;
}

inline bool inside(int a,int b,int c,int d)
{
	point st=point(a*100,b*100),ed=point(c*100,d*100);
	if (in(ed)) return true;
	for (int i=0;i<=100;i++)
	{
		point t=point(st.x+i*(c-a),st.y+i*(d-b));
		if (in(t)) return true;
	}
	return false;
}

inline int BFS()
{
	while (!q.empty()) q.pop();
	memset(fl,false,sizeof fl);
	fl[0][0]=true;q.push(point(0,0));
	while (!q.empty())
	{
		point now=q.front();q.pop();
		if (now.x==f(n-1,n-1)) return now.y;
		int nx=now.x/n,ny=now.x%n;
		for (int i=0;i<8;i++)
		{
			int tx=nx+d[i][0],ty=ny+d[i][1];
			if (!judge(tx,ty)) continue;
			if (inside(nx,ny,tx,ty)) continue;
			fl[tx][ty]=true;
			q.push(point(f(tx,ty),now.y+1));
		}
	}
	return -1;
}

int main()
{
	while (~scanf("%d",&n))
	{
		for (int r=0;r<3;r++)
		{
			scanf("%s",x);
			int a=0,b=0,l=strlen(x),pt=-1;
			for (int i=0;i<l;i++) if (x[i]=='.') pt=i;
			if (pt!=-1)
			{
				for (int i=pt+1;i<l;i++) b=b*10+x[i]-'0';
			}
			else pt=l;
			if (0<=b&&b<=10) b*=10;
			for (int i=x[0]=='-'?1:0;i<pt;i++) a=a*10+x[i]-'0';
			if (x[0]=='-') p[r].x=-(a*100+b);
			else p[r].x=a*100+b;
			scanf("%s",x);
			a=0;b=0;l=strlen(x);pt=-1;
			for (int i=0;i<l;i++) if (x[i]=='.') pt=i;
			if (pt!=-1)
			{
				for (int i=pt+1;i<l;i++) b=b*10+x[i]-'0';
			}
			else pt=l;
			if (0<=b&&b<=10) b*=10;
			for (int i=x[0]=='-'?1:0;i<pt;i++) a=a*10+x[i]-'0';
			if (x[0]=='-') p[r].y=-(a*100+b);
			else p[r].y=a*100+b;
		}
		for (int i=0;i<n;i++) scanf("%s",g[n-i-1]);
		printf("%d\n",BFS());
	}
	return 0;
}