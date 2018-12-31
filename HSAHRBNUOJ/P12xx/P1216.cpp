#include <cstdio>
#include <cstring>
#define MAXN 105
#define ppp printf("\nzhelicuole");printf("\n%d",i);
using namespace std;

char src[MAXN], pass[MAXN];
char yuan[MAXN], to[MAXN];
char duiyingbiao[27] = {"\0"};
bool check_duiyingbiao[27] = {false};
bool check[27] = {false};
bool flag = false;
int i, j, len, yuanlen;

int main()
{
	//freopen("spy.in","r",stdin);freopen("spy.out","w",stdout);
	gets(src);
	gets(pass);
	gets(yuan);
	len = strlen(src);
	yuanlen = strlen(yuan);
	memset(check, false, sizeof(check));
	for (i = 0; i < len; i++)
		check[src[i] - 'A' + 1] = true;
	for (i = 1; i <= 26; i++)
		if (!check[i])
		{
			printf("Failed");
			//ppp
			return 0;
		}
	memset(check, false, sizeof(check));
	for (i = 0; i < len; i++)
		check[pass[i] - 'A' + 1] = true;
	for (i = 1; i <= 26; i++)
		if (!check[i])
		{
			printf("Failed");
			//ppp
			return 0;
		}
	//Ô­Ôò1&2
	flag = false;
	for (i = 0; i < len; i++)
	{
		if (check_duiyingbiao[src[i] - 'A' + 1])
		{
			if (duiyingbiao[src[i] - 'A' + 1] != pass[i])
			{
				flag = true;
				break;
			}
		}
		else
		{
			duiyingbiao[src[i] - 'A' + 1] = pass[i];
			check_duiyingbiao[src[i] - 'A' + 1] = true;
		}
	}
	if (flag)
	{
		printf("Failed");
		//ppp
		return 0;
	}
	flag = false;
	for (i = 0; i < yuanlen; i++)
		to[i] = duiyingbiao[yuan[i] - 'A' + 1];
	puts(to);
	return 0;
}
