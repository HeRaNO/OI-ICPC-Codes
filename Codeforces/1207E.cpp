#include <bits/stdc++.h>
using namespace std;

int x;

int main()
{
	int ans=0;
	printf("?");
	for (int i=1;i<=100;i++) printf(" %d",i);puts("");
	fflush(stdout);
	scanf("%d",&x);
	for (int i=7;i<14;i++) ans|=(x&(1<<i));
	printf("?");
	for (int i=1;i<=100;i++) printf(" %d",i<<7);puts("");
	fflush(stdout);
	scanf("%d",&x);
	for (int i=0;i<7;i++) ans|=(x&(1<<i));
	printf("! %d\n",ans);fflush(stdout);
	return 0;
}