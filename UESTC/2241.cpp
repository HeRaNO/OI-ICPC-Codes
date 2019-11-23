#include <bits/stdc++.h>
using namespace std;
#define N 2000010

//Templet from HDU's templet
#define F(x) x/3+(x%3==1?0:tb)
#define G(x) x>=tb?(x-tb)*3+2:x*3+1

int c[N*3], x[N*3], y[N*3];
int sa[N*3], rank[N*3];
int Rank[N],p[N*2],hei[N],p1,p2,ans;
char a[N],b[N];

bool c0 (int *r, int a, int b)
{
	return r[a]==r[b] && r[a+1]==r[b+1] && r[a+2]==r[b+2];
}

bool c12 (int k, int *r, int a, int b)
{
	if (k == 1)
		return r[a]<r[b] || (r[a]==r[b]&&c[a+1]<c[b+1]);
	return r[a]<r[b] || (r[a]==r[b]&&c12(1, r, a+1, b+1));
}

void Sort (int *r, int *a, int *b, int n, int m)
{
	for (int i=0; i<m; i++) c[i] = 0;
	for (int i=0; i<n; i++) c[r[a[i]]] ++;
	for (int i=1; i<m; i++) c[i] += c[i-1];
	for (int i=n-1; i>=0; i--)
		b[--c[r[a[i]]]] = a[i];
}

void DC3 (int *r, int *sa, int n, int m)
{
	int *san = sa+n, *rn = r+n, ta=0, tb=(n+1)/3, tbc=0, i, j, p;
	for (i=0; i<n; i++) if (i % 3)  x[tbc ++] = i;

	r[n] = r[n+1] = 0;
	Sort (r+2, x, y, tbc, m);
	Sort (r+1, y, x, tbc, m);
	Sort (r, x, y, tbc, m);

	rn[F(y[0])] = 0;
	for (i=1, p=1; i<tbc; i++)
		rn[F(y[i])] = c0(r, y[i-1], y[i])?p-1:p++;
	//rn[i] 起始位置为i的排名

	if (p < tbc)
		DC3 (rn, san, tbc, p);
	else
		for (i=0; i<tbc; i++)
			san[rn[i]] = i;

	for (i=0; i<tbc; i++)
		if (san[i] < tb)
			y[ta++] = san[i]*3;

	if (n%3 == 1)
		y[ta++] = n - 1;

	Sort (r, y, x, ta, m);//对mod3==0的后缀串排序
	for (i=0; i<tbc; i++)
		c[y[i] = G(san[i])] = i;

	for (i=0, j=0, p=0; i<ta&&j<tbc; p++)
		sa[p] = c12 (y[j]%3, r, y[j], x[i])?y[j++]:x[i++];
	for (; j<tbc; j++)
		sa[p++] = y[j];
	for (; i<ta; i++)
		sa[p++] = x[i];

	return;
}

void calHeight(int *r,int *sa,int n,int *height)
{
	int i,j,k=0;
	for(int i=1;i<=n;i++) Rank[sa[i]]=i;
	for(int i=0;i<n;i++)
	{
		if(k) k--;
		j=sa[Rank[i]-1];
		while(i+k<n&&j+k<n&&r[i+k]==r[j+k]) k++;
		height[Rank[i]]=k;
	}
}

int main()
{
	scanf("%s",a);scanf("%s",b);
	p1=strlen(a);p2=strlen(b);
	for (int i=0;i<p1;i++) p[i]=a[i]-'a'+1;
	p[p1]=0;
	for (int i=0;i<p2;i++) p[i+p1+1]=b[i]-'a'+1;
	DC3(p,sa,p1+p2+1,27);
	calHeight(p,sa,p1+p2+1,hei);
	for (int i=2;i<=p1+p2+1;i++)
	{
		if ((sa[i-1]<p1&&sa[i]>p1)||(sa[i-1]>p1&&sa[i]<p1)) ans=max(ans,hei[i]);
	}
	printf("%d\n",ans);
	return 0;
}