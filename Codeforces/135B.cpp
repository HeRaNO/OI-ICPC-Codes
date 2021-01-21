#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y, c;
	Point() {}
	Point(int _x, int _y):
		x(_x), y(_y) {}
	Point operator + (const Point &p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator - (const Point &p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator * (int rate) const {
		return Point(x * rate, y * rate);
	}
	bool operator < (const Point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	int length() const {
		return x * x + y * y;
	}
	int operator ^ (const Point &p) const {
		return x * p.x + y * p.y;
	}
	int operator * (const Point &p) const {
		return x * p.y - y * p.x;
	}
};

int n=8;
Point p[10],ch[10],v1[10],v2[10];

int ConvexHull(Point *p, int n)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	} // Lower hull
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	} // Upper hull
	if (n > 1) m--;
	return m;
}

inline bool isRect(Point v[])
{
	int m=ConvexHull(v,4);
	if (m!=4) return false;
	if (((ch[1]-ch[0])^(ch[2]-ch[1]))!=0) return false;
	if (((ch[2]-ch[1])^(ch[3]-ch[2]))!=0) return false;
	if (((ch[3]-ch[2])^(ch[0]-ch[3]))!=0) return false;
	if (((ch[0]-ch[3])^(ch[1]-ch[0]))!=0) return false;
	return true;
}

inline bool isSquare(Point v[])
{
	if (!isRect(v)) return false;
	int p=(ch[1]-ch[0]).length();
	for (int i=0;i<4;i++)
		if ((ch[i]-ch[(i+1)&3]).length()!=p)
			return false;
	return true;
}

int main(int argc, char const *argv[])
{
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		p[i].c=i+1;
	}
	for (int i=0;i<(1<<n);i++)
		if (__builtin_popcount(i)==n>>1)
		{
			int pp=0,qq=0;
			for (int j=0;j<8;j++)
				if (i&(1<<j)) v1[pp++]=p[j];
				else v2[qq++]=p[j];
			if (isRect(v1)&&isSquare(v2))
			{
				puts("YES");
				printf("%d %d %d %d\n",v2[0].c,v2[1].c,v2[2].c,v2[3].c);
				printf("%d %d %d %d\n",v1[0].c,v1[1].c,v1[2].c,v1[3].c);
				return 0;
			}
		}
	puts("NO");
	return 0;
}