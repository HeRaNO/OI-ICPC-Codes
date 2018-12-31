#include <cstdio>
using namespace std;

int cnta, cntn;
char ch;

int main()
{
	while (true)
	{
		ch = getchar();
		if (ch == '?' || ch == '\n') break;
		if (ch >= 'a' && ch <= 'z') cnta++;
		if (ch >= 'A' && ch <= 'Z') cnta++;
		if (ch >= '0' && ch <= '9') cntn++;
	}
	printf("%d %d\n", cnta, cntn);
	return 0;
}
