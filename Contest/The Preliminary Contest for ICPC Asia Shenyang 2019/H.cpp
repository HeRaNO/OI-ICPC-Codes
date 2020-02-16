#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#define N 100050
int n;
int num[15];
struct people
{
	string Name;
	int poker[10];
	int type;
}a[N];
char s[15];
inline bool cmp(const people &x,const people &y)
{
	if(x.type<y.type)return true;
	if(x.type>y.type)return false;
	int type=x.type;
	switch(type)
	{
	case 1:
		{
			return x.Name<y.Name;
			break;
		}
	case 2:
		{
			if(x.poker[5]==y.poker[5])return x.Name<y.Name;
			else return x.poker[5]>y.poker[5];
			break;
		}
	case 3:
		{
			int fourx,foury,xx,yy;
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[x.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==4)
				{
					fourx=k;
					break;
				}
			}
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[y.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==4)
				{
					foury=k;
					break;
				}
			}
			if(fourx<foury)return false;
			if(fourx>foury)return true;
			for(int i=1;i<=5;++i)
			{
				if(x.poker[i]!=fourx)
				{
					xx=x.poker[i];
					break;
				}
			}
			for(int i=1;i<=5;++i)
			{
				if(y.poker[i]!=foury)
				{
					yy=y.poker[i];
					break;
				}
			}
			if(xx>yy)return true;
			if(xx<yy)return false;
			return x.Name<y.Name;
			break;
		}
	case 4:
		{
			mem(num,0);
			int threex=0,threey=0,twox=0,twoy=0;
			for(int j=1;j<=5;++j)
			{
				num[x.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(threex&&twox)break;
				if(num[k]==3)threex=k;
				else if(num[k]==2)twox=k;
			}
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[y.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(threey&&twoy)break;
				if(num[k]==3)threey=k;
				else if(num[k]==2)twoy=k;
			}
			if(threex>threey)return true;
			if(threex<threey)return false;
			if(twox>twoy)return true;
			if(twox<twoy)return false;
			return x.Name<y.Name;
			break;
		}
	case 5:
		{
			mem(num,0);
			int threex=0,threey=0;
			for(int j=1;j<=5;++j)
			{
				num[x.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(threex)break;
				if(num[k]==3){threex=k;break;}
			}
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[y.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(threey)break;
				if(num[k]==3){threey=k;break;}
			}
			if(threex>threey)return true;
			if(threex<threey)return false;
			int sumx=0,sumy=0;
			for(int j=1;j<=5;++j)
			{
				if(x.poker[j]!=threex)sumx+=x.poker[j];
			}
			for(int j=1;j<=5;++j)
			{
				if(y.poker[j]!=threey)sumy+=y.poker[j];
			}
			if(sumx==sumy)return x.Name<y.Name;
			else return sumx>sumy;
			break;
		}
	case 6:
		{
			int twox1=0,twox2=0,twoy1=0,twoy2=0;
			int xx,yy;
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[x.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==2)
				{
					if(twox1){twox2=k;break;}
					else twox1=k;
				}
			}
			if(twox1<twox2)swap(twox1,twox2);
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[y.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==2)
				{
					if(twoy1){twoy2=k;break;}
					else twoy1=k;
				}
			}
			if(twoy1<twoy2)swap(twoy1,twoy2);
			if(twox1>twoy1)return true;
			if(twox1<twoy1)return false;
			if(twox2>twoy2)return true;
			if(twox2<twoy2)return false;
			for(int j=1;j<=5;++j)
			{
				if(x.poker[j]!=twox1&&x.poker[j]!=twox2){xx=x.poker[j];break;}
			}
			for(int j=1;j<=5;++j)
			{
				if(y.poker[j]!=twoy1&&y.poker[j]!=twoy2){yy=y.poker[j];break;}
			}
			if(xx==yy)return x.Name<y.Name;
			else return xx>yy;
			break;
		}
	case 7:
		{
			int twox,twoy,sumx=0,sumy=0;
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[x.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==2){twox=k;}
				else if(num[k])sumx+=k;
			}
			mem(num,0);
			for(int j=1;j<=5;++j)
			{
				num[y.poker[j]]++;
			}
			for(int k=1;k<=13;++k)
			{
				if(num[k]==2){twoy=k;}
				else if(num[k])sumy+=k;
			}
			if(twox>twoy)return true;
			if(twox<twoy)return false;
			if(sumx==sumy)return x.Name<y.Name;
			else return sumx>sumy;
			break;
		}
	case 8:
		{
			int sum1=0,sum2=0;
			for(int i=1;i<=5;++i)sum1+=x.poker[i],sum2+=y.poker[i];
			if(sum1==sum2)return x.Name<y.Name;
			else return sum1>sum2;
			break;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].Name;
		scanf("%s",s);
		int sz=strlen(s);
		int tot=0;
		for(int j=0;j<sz;++j)
		{
			if(s[j]=='0')continue;
			if(s[j]=='A')
			{
				a[i].poker[++tot]=1;
				continue;
			}
			if(s[j]=='1')
			{
				a[i].poker[++tot]=10;
				continue;
			}
			if(s[j]=='J')
			{
				a[i].poker[++tot]=11;
				continue;
			}
			if(s[j]=='Q')
			{
				a[i].poker[++tot]=12;
				continue;
			}
			if(s[j]=='K')
			{
				a[i].poker[++tot]=13;
				continue;
			}
			a[i].poker[++tot]=s[j]-'0';
			continue;
		}
	}
	bool flag=0;
	for(int i=1;i<=n;++i)sort(a[i].poker+1,a[i].poker+5+1);
	for(int i=1;i<=n;++i)
	{
		mem(num,0);
		if(a[i].poker[2]==10&&a[i].poker[3]==11&&a[i].poker[4]==12&&a[i].poker[5]==13&&a[i].poker[1]==1)
		{
			a[i].type=1;
			continue;
		}
		else
		{
			flag=true;
			for(int j=2;j<=5;++j)
			{
				if(a[i].poker[j]!=a[i].poker[j-1]+1){flag=0;break;}
			}
			if(flag){a[i].type=2;continue;}
		}
		for(int j=1;j<=5;++j)num[a[i].poker[j]]++;
		for(int k=1;k<=13;++k)
		{
			if(num[k]==4){a[i].type=3;break;}
		}
		if(a[i].type!=0)continue;
		if((a[i].poker[1]==a[i].poker[2]&&a[i].poker[2]==a[i].poker[3]&&a[i].poker[4]==a[i].poker[5])||(a[i].poker[3]==a[i].poker[4]&&a[i].poker[4]==a[i].poker[5]&&a[i].poker[1]==a[i].poker[2]))
		{
			a[i].type=4;
			continue;
		}
		for(int k=1;k<=13;++k)
		{
			if(num[k]==3){a[i].type=5;break;}
		}
		if(a[i].type!=0)continue;
		int tmp=0;
		for(int k=1;k<=13;++k)
		{
			if(num[k]==2)tmp++;
		}
		if(tmp==2)a[i].type=6;
		else if(tmp==1)a[i].type=7;
		else a[i].type=8;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		cout<<a[i].Name<<endl;
	}
	return 0;
}