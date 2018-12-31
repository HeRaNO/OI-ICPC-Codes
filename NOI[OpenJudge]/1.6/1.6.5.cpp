//Code By HeRaNO
#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	double age[n], shiba = 0, sanshiwu = 0, liushi = 0, lsys = 0, shiba1, sanshiwu1, liushi1, lsys1;
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &age[i]);
		if (age[i] <= 18) shiba++;
		else if ((age[i] >= 19) && (age[i] <= 35)) sanshiwu++;
		else if ((age[i] >= 36) && (age[i] <= 60)) liushi++;
		else lsys++;
	}
	shiba1 = (shiba / n) * 100.0;
	sanshiwu1 = (sanshiwu / n) * 100.0;
	liushi1 = (liushi / n) * 100.0;
	lsys1 = (lsys / n) * 100.0;
	printf("%0.2f%%\n", shiba1);
	printf("%0.2f%%\n", sanshiwu1);
	printf("%0.2f%%\n", liushi1);
	printf("%0.2f%%\n", lsys1);
	return 0;
}
