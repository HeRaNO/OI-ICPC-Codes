#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define Flush fflush(stdout)
using namespace std;
int n;
int Left,Right,Up,Down;
int Down1,Up1,Left1,Right1;
int X[5],Y[5];

bool check1(int x)
{
	printf("? %d %d %d %d\n",Left,Down,x,Up);Flush;
	int k;scanf("%d",&k);
	if(k)return true;
	else return false;
}
bool check2(int x)
{
	printf("? %d %d %d %d\n",Left,Down,Right,x);Flush;
	int k;scanf("%d",&k);
	if(k)return true;
	else return false;
}
bool check3(int x)
{
	printf("? %d %d %d %d\n",x,Down,Right,Up);Flush;
	int k;scanf("%d",&k);
	if(k)return true;
	else return false;
}
bool check4(int x)
{
	printf("? %d %d %d %d\n",Left,x,Right,Up);Flush;
	int k;scanf("%d",&k);
	if(k)return true;
	else return false;
}
bool check5(int x)
{
	printf("? %d %d %d %d\n",Left1,Down1,x,Up1);Flush;
	int k;scanf("%d",&k);
	if(k-(Right<=x))return true;
	else return false;
}
bool check6(int x)
{
	printf("? %d %d %d %d\n",Left1,Down1,Right1,x);Flush;
	int k;scanf("%d",&k);
	if(k-(Right<=Right1&&Up<=x))return true;
	else return false;
}
bool check7(int x)
{
	printf("? %d %d %d %d\n",x,Down1,Right1,Up1);Flush;
	int k;scanf("%d",&k);
	if(k-(Left>=x&&Up<=Up1&&Right<=Right1))return true;
	else return false;
}
bool check8(int x)
{
	printf("? %d %d %d %d\n",Left1,x,Right1,Up1);Flush;
	int k;scanf("%d",&k);
	if(k-(Left>=Left1&&Down>=x&&Right<=Right1&&Up<=Up1))return true;
	else return false;
}

int main()
{
	scanf("%d",&n);
	Left=1,Right=n,Up=n,Down=1;
	int L=1,R=n;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check1(mid))Right=mid,R=mid-1;
		else L=mid+1;
	}
	L=1,R=n;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check2(mid))Up=mid,R=mid-1;
		else L=mid+1;
	}
	L=1,R=Right;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check3(mid))Left=mid,L=mid+1;
		else R=mid-1;
	}
	L=1,R=Up;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check4(mid))Down=mid,L=mid+1;
		else R=mid-1;
	}

	Left1=1,Right1=n,Up1=n,Down1=1;
	L=1,R=n;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check5(mid))Right1=mid,R=mid-1;
		else L=mid+1;
	}
	L=1,R=n;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check6(mid))Up1=mid,R=mid-1;
		else L=mid+1;
	}
	L=1,R=Right1;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check7(mid))Left1=mid,L=mid+1;
		else R=mid-1;
	}
	L=1,R=Up1;
	while(L<=R)
	{
		int mid=(L+R)>>1;
		if(check8(mid))Down1=mid,L=mid+1;
		else R=mid-1;
	}
	printf("! %d %d %d %d %d %d %d %d\n",
		   Left,Down,Right,Up,Left1,Down1,Right1,Up1);
	Flush;
	return 0;
}
