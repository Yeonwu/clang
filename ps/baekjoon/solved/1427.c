// https://www.acmicpc.net/problem/1427
// 소트인사이드
// 실버 5

#include <stdio.h>
#include <string.h>
int main()
{
	char n[20];
	int len, i, j, tmp;
	scanf("%s", n);
	len = strlen(n);
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (n[j] < n[i])
			{
				tmp = n[j];
				n[j] = n[i];
				n[i] = tmp;
			}
		}
	}
	printf("%s\n", n);
	return 0;
}