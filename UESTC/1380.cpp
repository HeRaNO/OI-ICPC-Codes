#include <map>
#include <queue>
#include <cstdio>
#define fi first
#define se second
using namespace std;

const int d[4][2]={
	{1,0},{-1,0},
	{0,1},{0,-1}
};

int T,a[4][4];char x[3];

queue <pair<int,int> > q;
map <int,int> mp;
map <int,int> :: iterator it;

pair<int,int> decode(int p)
{
	int cnt=9;int x=3,y=3;pair<int,int> r;
	while (cnt)
	{
		a[x][y]=p%10;
		if (!a[x][y]){r.fi=x;r.se=y;}
		p/=10;
		--y;if (!y){--x;y=3;}
		--cnt;
	}
	return r;
}

bool in(int x,int y){return (1<=x&&x<=3&&1<=y&&y<=3);}

inline void BFS(int st)
{
	mp.insert(make_pair(st,0));q.push(make_pair(st,0));
	while (!q.empty())
	{
		pair<int,int> x=q.front();q.pop();
		pair<int,int> pos=decode(x.first);int p=x.second;
		for (int i=0;i<4;i++)
			if (in(pos.fi+d[i][0],pos.se+d[i][1]))
			{
				swap(a[pos.fi][pos.se],a[pos.fi+d[i][0]][pos.se+d[i][1]]);
				int t=0;
				for (int i=1;i<=3;i++)
					for (int j=1;j<=3;j++)
						t=t*10+a[i][j];
				if (!mp.count(t))
				{
					mp.insert(make_pair(t,p+1));
					q.push(make_pair(t,p+1));
				}
				swap(a[pos.fi][pos.se],a[pos.fi+d[i][0]][pos.se+d[i][1]]);
			}
	}
	return ;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&T);BFS(123456780);
	while (T--)
	{
		int st=0;
		for (int i=1;i<=3;i++)
			for (int j=1,c;j<=3;j++)
			{
				scanf("%s",x);
				c=x[0]=='x'?0:x[0]-'0';
				st=st*10+c;
			}
		it=mp.find(st);
		if (it==mp.end()) puts("-1");
		else printf("%d\n",it->second);
	}
	return 0;
}