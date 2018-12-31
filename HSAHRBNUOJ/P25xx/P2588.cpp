#include <cstdio>
#include <cstring>
#define MAXL 20000010
#define MAXN 2000010
using namespace std;

char sta[MAXL];
char s[MAXN];
int ansdep, time, nowdep, n, T;
int top;
bool out;

bool judge(char a, char b)
{
	if (a == '/') return true;
	if (a == '(') return b == ')';
	if (a == '[') return b == ']';
	if (a == '{') return b == '}';
	if (a == '<') return b == '>';
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		top = 0;
		time = 0;
		nowdep = 0;
		out = false;
		ansdep = 0;
		scanf("%s", s);
		n = strlen(s);
		if (n == 1)
		{
			printf("FALSE\n");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<')
			{
				sta[++top] = s[i];
				if (top > ansdep)
				{
					ansdep = top;
					time = 1;
				}
				else if (top == ansdep) time++;
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}' || s[i] == '>')
			{
				if (top > 0 && judge(sta[top], s[i])) top--;
				else
				{
					printf("FALSE\n");
					out = true;
					break;
				}
			}
			else if (s[i] == '/' || s[i] == '#' || s[i] == '@' || s[i] == '?')
			{
				if (s[i] == '/') sta[++top] = s[i];
				else if (s[i] == '#') for (int j = 0; j <= 1; j++) sta[++top] = '/';
				else if (s[i] == '@') for (int j = 0; j <= 3; j++) sta[++top] = '/';
				else for (int j = 0; j <= 7; j++) sta[++top] = '/';
				if (top > ansdep)
				{
					ansdep = top;
					time = 1;
				}
				else if (top == ansdep) time++;
			}
			else
			{
				if (s[i] == '\\') top--;
				else if (s[i] == '*') top -= 2;
				else if (s[i] == '&') top -= 4;
				else top -= 8;
			}
			if (top < 0)
			{
				printf("FALSE\n");
				out = true;
				break;
			}
		}
		if (!ansdep && !out) out = true, printf("FALSE\n");
		if (top > 0 && !out) out = true, printf("FALSE\n");
		if (!out) printf("TRUE %d %d\n", ansdep, time);
	}
	return 0;
}
