// https://www.acmicpc.net/problem/10757
// 큰수 A+B
// 브론즈 5

#include <stdio.h>

char a[10000];
char b[10000];
int result[10001];

int cti(char c)
{
	return c - 48;
}

int main()
{
	int ia = 9999, ib = 9999, ir, sum;
	scanf("%s %s", a, b);

	while (ia >= 0 && a[ia] == 0)
	{
		ia--;
	}

	while (ib >= 0 && b[ib] == 0)
	{
		ib--;
	}

	for (ir = 0; ia >= 0 && ib >= 0; ir++)
	{
		sum = cti(a[ia]) + cti(b[ib]);
		result[ir] += sum;
		if (result[ir] >= 10)
		{
			result[ir] -= 10;
			result[ir + 1] += 1;
		}
		ia--;
		ib--;
	}

	while (ia >= 0)
	{
		result[ir] += cti(a[ia--]);
		if (result[ir] >= 10)
		{
			result[ir] -= 10;
			result[ir + 1] += 1;
		}
		ir++;
	}

	while (ib >= 0)
	{
		result[ir] += cti(b[ib--]);
		if (result[ir] >= 10)
		{
			result[ir] -= 10;
			result[ir + 1] += 1;
		}
		ir++;
	}

	int isFirst = 1;
	for (; ir >= 0; ir--)
	{
		if (isFirst)
		{
			isFirst = 0;
			if (result[ir] == 0)
			{
				continue;
			}
		}
		printf("%d", result[ir]);
	}
	printf("\n");

	return 0;
}