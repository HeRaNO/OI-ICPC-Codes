//Code By HeRaNO
#include <cstdio>
#include <algorithm>
#define MAXN 110
using namespace std;

struct patient
{
	char id[15];
	int pt;
	int age;
};

patient young[MAXN], old[MAXN];
int n, cntold, cntyoung;

bool cmpold(patient a, patient b)
{
	if (a.age == b.age) return a.pt < b.pt;
	return a.age > b.age;
}

bool cmpyoung(patient a, patient b)
{
	return a.pt < b.pt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		patient in;
		scanf("%s %d", in.id, &in.age);
		in.pt = i;
		if (in.age >= 60) old[++cntold] = in;
		else young[++cntyoung] = in;
	}
	sort(old + 1, old + cntold + 1, cmpold);
	sort(young + 1, young + cntyoung + 1, cmpyoung);
	for (int i = 1; i <= cntold; i++) printf("%s\n", old[i].id);
	for (int i = 1; i <= cntyoung; i++) printf("%s\n", young[i].id);
	return 0;
}
