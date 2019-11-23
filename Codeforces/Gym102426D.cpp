#include <bits/stdc++.h>
using namespace std;
#define ll long long
double a[]={0,1.008,4.003,
6.941,9.012,10.81,12.01,14.01,16.00,19.00,20.18,22.99,
24.31,26.98,28.09,30.97,32.07,35.45,39.95,39.10,40.08,
44.96,47.88,50.94,52.00,54.94,55.85,58.93,58.69,63.55,
65.39,69.72,72.59,74.92,78.96,79.90,83.80,85.47,87.62,
88.91,91.22,92.91,95.94,97.91,101.1,102.9,106.4,107.9,
112.4,114.8,118.7,121.8,127.6,126.9,131.3,132.9,137.3,
138.9,140.1,140.9,144.2,144.9,150.4,152.0,157.3,158.9,
162.5,164.9,167.3,168.9,173.0,175.0,178.5,180.9,183.9,
186.2,190.2,192.2,195.1,197.0,200.6,204.4,207.2,209.0,209.0,
210.0,222.0,223.0,226.0,227.0,232.0,231.0,238.0,237.1,
244.1,243.1,247.1,247.1,252.1,252.1,257.1,258.1,259.1,
262.1,265.1,268.1,271.1,270.1,277.2,276.2,281.2,280.2,
285.2,284.2,289.2,288.2,293.2,294.2,294.2};
double ans;
char s[1050];
char fenzi[][5]={"0","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
				"Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
				"Cs","Ba",
				"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
				"Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
				"Fr","Ra",
				"Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr",
				"Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
char tmp[15];
char Num[10];

bool isnum(char c)
{
	return c>='0'&&c<='9';
}
bool islow(char c)
{
	return c>='a'&&c<='z';
}
bool isup(char c)
{
	return c>='A'&&c<='Z';
}

void getans(int num)
{
	for(int i=1;i<=118;++i)
	{
		if(tmp[0]==fenzi[i][0]&&tmp[1]==fenzi[i][1])
		{
			ans+=num*a[i];
			break;
		}
	}
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		ans=0;
		memset(s,0,sizeof s);
		scanf("%s",s);
		int siz=strlen(s);
		int i=0;
		int t=0;
		while(i<siz)
		{
			t=0;
			memset(tmp,0,sizeof tmp);
			if(isup(s[i]))
			{
				if(i==siz-1||isnum(s[i+1])||isup(s[i+1]))
				{
					tmp[t++]=s[i];
					i++;
					int num=0;
					while(isnum(s[i]))
					{
						num*=10;
						num+=s[i]-'0';
						i++;
					}
					if(num==0)num=1;
					getans(num);
				}
				else
				{
					tmp[t++]=s[i];
					tmp[t++]=s[i+1];
					i+=2;
					int num=0;
					while(isnum(s[i]))
					{
						num*=10;
						num+=s[i]-'0';
						i++;
					}
					if(num==0)num=1;
					getans(num);
				}
			}
			else if(isnum(s[i])||islow(s[i]))
			{
				i++;
				continue;
			}
		}
		printf("%lf\n",ans);
	}
	return 0;
}