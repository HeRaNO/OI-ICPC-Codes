#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char s[4];
	scanf("%s",s);
	if (s[0]==s[1]&&s[1]==s[2]) puts("Won");
	else puts("Lost");
	return 0;
}