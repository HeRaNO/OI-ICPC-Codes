#include <bits/stdc++.h>
#define MAXL 100005
using namespace std;

int T,cas,n,p,q,cnt;
char s[MAXL],html[MAXL];

inline bool isWhite(char s){return s==32||s==9||s==10;}

inline bool readLine()
{
	if (gets(s))
	{
		p=0;
		n=strlen(s);
		return true;
	}
	return false;
}

inline void writeHTML(int x)
{
	if (!q) return ;
	for (int i=1;i<=x;i++) putchar(' ');
	puts(html);
	return ;
}

inline bool parseSpace()
{
	while (p<n&&isWhite(s[p])) ++p;
	if (p>=n) return readLine();
	return true;
}

inline bool match(char x)
{
	if (!parseSpace()) return false;
	if (s[p]==x){html[q++]=s[p++];return true;}
	return false;
}

inline void addSpace()
{
	if (q&&html[q-1]!=' ') html[q++]=' ';
	return ;
}

inline int parseLine()
{
	if (p>=n) readLine();
	q=0;
	bool isTag=match('<');
	bool isEnd=match('/');
	bool space=false;
	if (isTag)
	{
		while (s[p]!='>')
		{
			if (!p&&space) html[q++]=' ';
			html[q++]=s[p++];
			if (p>=n&&!readLine()) break;
			space=true;
		}
	}
	else
	{
		while (s[p]!='<')
		{
			if (!p&&space) addSpace();
			if (isWhite(s[p])) addSpace();
			else html[q++]=s[p];++p;
			if (p>=n&&!readLine()) break;
			space=true;
		}
		while (q&&html[q-1]==' ') --q;
	}
	bool endWithSlash=html[q-1]=='/';
	match('>');
	html[q]='\0';
	if (isTag&&isEnd&&!endWithSlash) return -1;
	if (isTag&&!endWithSlash) return 1;
	return 0;
}

int main()
{
	scanf("%d%*c",&T);
	while (T--)
	{
		printf("Case #%d:\n",++cas);
		cnt=parseLine();
		writeHTML(0);
		while (cnt)
		{
			int now=parseLine();
			if (now<0) writeHTML(cnt-1);
			else writeHTML(cnt);
			cnt+=now;
		}
	}
	return 0;
}