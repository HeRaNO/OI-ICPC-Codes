#include <cstdio>
using namespace std;

bool a[26];
char equal[3];
bool first = true;
int n;

int main()
{
	scanf("%d", &n);
	a[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", equal);
		a[equal[0] - 'a'] = a[equal[2] - 'a'];
	}
	for (int i = 0; i < 26; i++)
		if (a[i])
		{
			if (first)
			{
				first = false;
				printf("%c", i + 'a');
			}
			else printf(" %c", i + 'a');
		}
	if (first) printf("none");
	puts("");
	return 0;
}
