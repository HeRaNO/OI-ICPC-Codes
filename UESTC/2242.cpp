#include <bits/stdc++.h>
using namespace std;

const long long M=1e9+7;

struct Matrix
{
	long long m[3][3];
	Matrix(){}
	bool operator < (const Matrix &a)const{
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				if (a.m[i][j]!=m[i][j]) return m[i][j]<a.m[i][j];
		return false;
	}
	bool operator == (const Matrix &a)const{
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				if (a.m[i][j]!=m[i][j]) return false;
		return true;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
			{
				res.m[i][j]=0LL;
				for (int k=0;k<3;k++) res.m[i][j]=(res.m[i][j]+(m[i][k]*a.m[k][j]%M))%M;
			}
		return res;
	}
}A,B;

map <Matrix,int> v;
map <Matrix,int> :: iterator it;

int BSGS(Matrix a,Matrix b)
{
	int m=31623;
	Matrix ans=b,t,p=a;
	for (int i=0;i<=m;i++,ans=ans*a) v.insert(make_pair(ans,i));
	for (int i=1;i<m;i++) p=p*a;
	t=p;
	for (int i=1;i<=m;i++)
	{
		it=v.find(t);
		if (it!=v.end()) return i*m-(it->second);
		t=t*p;
	}
	return -1LL;
}

int main()
{
	for (int i=0;i<3;i++) A.m[i][0]=1LL;
	A.m[0][1]=A.m[1][2]=1LL;
	scanf("%lld %lld %lld",&B.m[0][2],&B.m[0][1],&B.m[0][0]);
	B.m[1][0]=(B.m[0][1]+B.m[0][2])%M;
	B.m[1][1]=(B.m[0][0]-B.m[0][1]+M)%M;
	B.m[1][2]=(B.m[0][1]-B.m[0][2]+M)%M;
	B.m[2][0]=B.m[0][1];
	B.m[2][1]=B.m[0][2];
	B.m[2][2]=(B.m[0][0]-B.m[0][1]+M-B.m[0][2]+M)%M;
	printf("%d\n",BSGS(A,B));
	return 0;
}