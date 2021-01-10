#include <bits/stdc++.h>
using namespace std;

string teamName[105],memberName[105][11];
int n,mx,scr[105][4],teamscr[105],p[105];
int memberscr[105][11];
vector <string> ans;

bool cmp(int a,int b)
{
	if (teamscr[a]!=teamscr[b]) return teamscr[a]>teamscr[b];
	return teamName[a]<teamName[b];
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) p[i]=i;
	for (int t=1;t<=n;t++)
	{
		cin>>teamName[t];
		for (int i=1;i<=10;i++)
		{
			cin>>memberName[t][i];
			for (int j=1,x;j<=8;j++)
			{
				scanf("%d",&x);
				memberscr[t][i]+=x;
				scr[t][1]+=x;
			}
			for (int j=1,x;j<=4;j++)
			{
				scanf("%d",&x);
				memberscr[t][i]+=x;
				scr[t][2]+=x;
			}
			for (int j=1,x;j<=3;j++)
			{
				scanf("%d",&x);
				memberscr[t][i]+=x;
				scr[t][3]+=x;
			}
		}
		teamscr[t]=scr[t][1];
		if (scr[t][1]>=800)
		{
			teamscr[t]+=scr[t][2];
			if (scr[t][2]>=400) teamscr[t]+=scr[t][3];
		}
	}
	sort(p+1,p+n+1,cmp);
	int lst,lstscr=0;
	for (int t=1;t<=n;t++)
	{
		int x=p[t];
		cout<<teamName[x]<<" "<<scr[x][1]<<" "<<scr[x][2]<<" "<<scr[x][3]<<" "<<teamscr[x];
		if (teamscr[x]!=lstscr)
		{
			cout<<" "<<t<<'\n';
			lst=t;
		}
		else cout<<" "<<lst<<'\n';
		lstscr=teamscr[x];
	}
	for (int t=1;t<=n;t++)
		for (int i=1;i<=10;i++)
			mx=max(mx,memberscr[t][i]);
	for (int t=1;t<=n;t++)
		for (int i=1;i<=10;i++)
			if (memberscr[t][i]==mx)
				ans.push_back(memberName[t][i]);
	sort(ans.begin(),ans.end());
	printf("%d",mx);
	for (auto i:ans) cout<<" "<<i;
	puts("");
	return 0;
}