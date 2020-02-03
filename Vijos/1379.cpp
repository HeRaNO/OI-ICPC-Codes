#include <stdio.h>
int p1, p2, p3;
char in[1000];
int i;

int judge()
{
	if (in[i] == '\0')
		return 1;
	if ((in[i] == '-' && (i == 0 || in[i - 1] >= in[i + 1] || in[i - 1] == '-')) || in[i] != '-' || (in[i] == '-' && in[i - 1] < 60 && in[i + 1] > 60))
		return 2;
	if (in[i] == '-' && in[i - 1] < in[i + 1])
		return 3;
}

void function()
{
	int j, m;
	if (p3 == 1)
	{
		for (j = in[i - 1] + 1; j < in[i + 1]; j++) for (m = 0; m < p2; m++)
			{
				if (p1 == 1) printf("%c", j);
				if (p1 == 2)
				{
					if (j > 60) printf("%c", j - 32);
					else printf("%c", j);
				}
				if (p1 == 3) printf("*");
			}
	}
	if (p3 == 2)
	{
		for (j = in[i + 1] - 1; j > in[i - 1]; j--)
			for (m = 0; m < p2; m++)
			{
				if (p1 == 1) printf("%c", j);
				if (p1 == 2)
				{
					if (j > 60) printf("%c", j - 32);
					else printf("%c", j);
				}
				if (p1 == 3) printf("*");
			}
	}
}
int main()
{
	scanf("%d%d%d", &p1, &p2, &p3);
	scanf("%s", &in);
	for (i = 0; i < 1000; i++)
	{
		if (judge() == 1) break;
		if (judge() == 2) printf("%c", in[i]);
		if (judge() == 3) function();
	}
	return 0;
}