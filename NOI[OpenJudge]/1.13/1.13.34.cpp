//Code By HeRaNO
#include <stdio.h>
char p[32], q[32], r[32];

int MinRadix()
{
	int i, minRadix;
	minRadix = 1;
	for (i = 0; p[i]; i++)
		if (minRadix < p[i] - '0') minRadix = p[i] - '0';
	for (i = 0; q[i]; i++)
		if (minRadix < q[i] - '0') minRadix = q[i] - '0';
	for (i = 0; r[i]; i++)
		if (minRadix < r[i] - '0') minRadix = r[i] - '0';
	return minRadix + 1;
}

bool Radix(int radix)
{
	int i, P, Q, R;
	for (P = i = 0; p[i]; ++i)
		P = P * radix + p[i] - '0';
	for (Q = i = 0; q[i]; ++i)
		Q = Q * radix + q[i] - '0';
	for (R = i = 0; r[i]; ++i)
		R = R * radix + r[i] - '0';
	if (P * Q == R) return 1;
	else return 0;
}

int main()
{
	int i;
	scanf("%s%s%s", p, q, r);
	for (i = MinRadix(); i < 17; i++)
		if (Radix(i)) break;
	printf("%d\n", i == 17 ? 0 : i);
	return 0;
}
