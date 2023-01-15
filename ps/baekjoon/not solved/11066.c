# include<stdio.h>

int solve_task(int len, int* files) {
	int i = 0, sum = 0;
	
	

	return sum;
}

int main() {
	int task_num, len;
	int files[500] = {0};
	int answers[500] = {0};
	int i, j;

	scanf("%d", &task_num);
	for (i = 0; i < task_num; i++) {
		scanf("%d", &len);
		for (j = 0; j < len; j++) {
			scanf("%d", &files[j]);
		}
		answers[i] = solve_task(len, files);
	}

	for (i = 0; i < task_num; i++) {
		printf("%d ", answers[i]);
	}
	printf("\n");

	return 0;
}