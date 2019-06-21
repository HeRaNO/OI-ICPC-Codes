#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

/* Claris's Templet */
int tot=1,last=1,pre[MAXN<<1],son[MAXN<<1][26],ml[MAXN<<1];
void extend(int w){
	int p=++tot,x=last,r,q;
	for(ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x])son[x][w]=p;
	if(!x)pre[p]=1;
	else if(ml[x]+1==ml[q=son[x][w]])pre[p]=q;
	else{
		pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof son[r]);
		ml[r]=ml[x]+1;pre[p]=pre[q]=r;
		for(;x&&son[x][w]==q;x=pre[x])son[x][w]=r;
	}
}
/*But what is he writing???*/

int n,a[MAXN],r[MAXN<<1],f[MAXN],id[MAXN<<1];
char s[MAXN];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++) extend(s[i]-'a');
	for (int p=1,i=1;i<=n;i++) p=son[p][s[i]-'a'],++r[p];
	for (int i=1;i<=tot;i++) ++a[ml[i]];
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1;i<=tot;i++) id[a[ml[i]]--]=i;
	for (int i=tot;i;i--) r[pre[id[i]]]+=r[id[i]];
	for (int i=1;i<=tot;i++) f[ml[i]]=max(f[ml[i]],r[i]);
	for (int i=n;i;i--) f[i]=max(f[i],f[i+1]);
	for (int i=1;i<=n;i++) printf("%d%c",f[i],i==n?'\n':' ');
	return 0;
}