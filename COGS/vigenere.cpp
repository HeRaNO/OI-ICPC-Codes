#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 1100
using namespace std;

int key[MAXN];
char k[MAXN],mw[MAXM],ans;
int i,lk,lmw;

int main()
{
	freopen("vigenere.in","r",stdin);freopen("vigenere.out","w",stdout);
	scanf("%s",k);scanf("%s",mw);
	lk=strlen(k);lmw=strlen(mw);
	for(i=0;i<lk;i++)
	{
		if(k[i]>='a') key[i]=k[i]-'a';
		else key[i]=k[i]-'A';
	}
	i=0;
	while(i<lmw)
	{
		ans=mw[i]-key[i%lk];
		if((ans<'A')||(ans<'a'&&mw[i]>='a'))
			ans+=26;
		printf("%c",ans);
		i++;
	}
	printf("\n");
	return 0;
}