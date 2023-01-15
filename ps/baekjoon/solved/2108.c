// https://www.acmicpc.net/problem/2108
// 통계학
// 실버 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return 1;
	else if (*(int *)first < *(int *)second)
		return -1;
	else
		return 0;
}

int main()
{
	int len, in, i, maxCnt = 0, max = -4000, min = 4000;
	int sorted[500000] = {
		0,
	};
	int cnt[8005] = {
		0,
	};
	double avg = 0;
	scanf("%d", &len);

	for (i = 1; i <= len; i++)
	{
		scanf("%d", &in);
		avg = (avg * (i - 1) + in) / i;

		sorted[i - 1] = in;

		cnt[in + 4000] += 1;
		if (cnt[maxCnt + 4000] <= cnt[in + 4000])
		{
			maxCnt = in;
		}

		if (max < in)
			max = in;
		if (min > in)
			min = in;
	}

	qsort(sorted, len, sizeof(int), compare);

	in = 0;
	for (i = -4000; i <= 4000; i++)
	{
		if (cnt[i + 4000] == cnt[maxCnt + 4000])
		{
			in += 1;
			if (in == 2)
			{
				maxCnt = i;
				break;
			}
		}
	}

	avg = floor(avg + 0.5);
	printf("%d\n%d\n%d\n%d\n", (int)avg, sorted[(len + 1) / 2 - 1], maxCnt, max - min);
	return 0;
}
