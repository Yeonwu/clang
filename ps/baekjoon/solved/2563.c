// https://www.acmicpc.net/problem/2563
// 색종이
// 실버 5

#include <stdio.h>

int main()
{
	int a[101][101] = {
		0,
	};
	int num, x, y, i, j, k;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = x; j < x + 10; j++)
		{
			for (k = y; k < y + 10; k++)
			{
				a[j][k] = 1;
			}
		}
	}
	num = 0;
	for (x = 0; x < 100; x++)
	{
		for (y = 0; y < 100; y++)
		{
			if (a[x][y])
			{
				num++;
			}
		}
	}
	printf("%d\n", num);
}