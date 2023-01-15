// https://www.acmicpc.net/problem/2566
// 최댓값
// 브론즈 3
#include <stdio.h>

int main()
{
	int m = -1, mx, my, i, j, tmp;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &tmp);
			if (m < tmp)
			{
				mx = j + 1;
				my = i + 1;
				m = tmp;
			}
		}
	}
	printf("%d\n%d %d\n", m, my, mx);
}