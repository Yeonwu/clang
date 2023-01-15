# include <stdio.h>

char lake[2000][2000];
int queue[100000][3], tail = 0, head = 0, r, c;

void push(int dx, int dy) {
	queue[tail][0] = queue[head][0] + dx;
	queue[tail][1] = queue[head][1] + dy;
	queue[tail][2] = queue[head][2];
	if (lake[queue[tail][0]][queue[tail][1]] == 'X') queue[tail][2] += 1;
	if (queue[tail][0] >= 0 && queue[tail][0] < r && queue[tail][1] >= 0 && queue[tail][1] < c) tail++;
}

int main() {
	int i, j, answer, day = 0, found = 0;
	
	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++) {
		scanf("%s", &lake[i]);
		for (j = 0; j < c; j++) {
			if (lake[i][j] == 'L' && tail == 1) {lake[i][j] = 'P';}
			if (lake[i][j] == 'L' && tail == 0) {queue[tail][0] = i; queue[tail][1] = j; queue[tail++][2] = 0;}
		}
	}
	
	while(!found) {
		if (lake[queue[head][0]][queue[head][1]] == 'P') break;
		push(1, 0);
		push(-1, 0);
		push(0, 1);
		push(0, -1);
		head++;
	}
	
	printf("%d\n", queue[head][2]);
	return 0;
}