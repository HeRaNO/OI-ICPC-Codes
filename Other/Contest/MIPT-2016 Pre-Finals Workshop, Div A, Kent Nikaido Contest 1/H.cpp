#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

int l,n,x,y;
bool res;

bool f(int x,int y)
{
	return ((l&x)==x)&&((l&y)==y)&&((x&y)==y);
}

int main()
{
	scanf("%d %d",&l,&n);--l;res=l&1;
	while (n--) scanf("%d %d",&x,&y),res^=f(x-1,y-1);
	puts(res?"Iori":"Yayoi");
	return 0;
}