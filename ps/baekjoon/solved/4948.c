// https://www.acmicpc.net/problem/4948
// 베르트랑 공준
// 실버 2
#define MAX 20
#define AVG(a, b) (a + b) / 2
#include <stdio.h>

int find(int *memo, int len, int p)
{
	int low = 0;
	int high = len;
	int piv = AVG(low, high);

	while (1)
	{
		if (p == memo[piv] || piv == low || piv == high)
		{
			break;
		}
		else if (p < memo[piv])
		{
			high = piv;
			piv = AVG(low, high);
		}
		else if (p > memo[piv])
		{
			low = piv;
			piv = AVG(low, high);
		}
	}
	return piv;
}

int main()
{
	int memo[21798] = {
		0,
	};
	memo[0] = 1;
	memo[1] = 2;
	int p, p2, mc = 2, min, max;
	for (p = 3; p < 246993; p++)
	{
		for (p2 = 1; p2 < mc; p2++)
		{
			if (!(p % memo[p2]))
			{
				break;
			}
		}

		if (p2 == mc)
		{
			memo[mc++] = p;
		}
	}

	p = 1;
	mc--;
	while (1)
	{
		scanf("%d", &p);
		if (!p)
			break;
		min = find(memo, mc, p);
		max = find(memo, mc, p * 2);
		printf("%d\n", max - min);
	}
	return 0;
}