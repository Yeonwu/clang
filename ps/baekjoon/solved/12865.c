# define W 0
# define V 1
# include <stdio.h>

int len, mw, t[100][2];
int memo[200][200000];

int r(int n, int cw) {
	if (n >= len) return 0;
	if (memo[n][cw]) return memo[n][cw];
	int tmpa = 0, tmpb = 0;
	if (cw + t[n][W] <= mw) {
		tmpa = r(n + 1, cw + t[n][W]) + t[n][V];
	}
	tmpb = r(n + 1, cw);
	memo[n][cw] = tmpa > tmpb ? tmpa : tmpb;
	return memo[n][cw];
}

int main() {
	int i;
	scanf("%d %d", &len, &mw);
	for (i = 0; i < len; i++) {
		scanf("%d %d", &t[i][W], &t[i][V]);
	}
	printf("%d\n", r(0, 0));
	return 0;
}