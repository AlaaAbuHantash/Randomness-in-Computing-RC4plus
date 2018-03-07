#include <stdio.h>

int arr[100000000] = { }, res[100000000] = { }, count;

int main() {
	int n, cnt = 0, x, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (arr[x] == 0)
			res[cnt++] = x;
		arr[x]++;
	}
	for (i = 0; i < cnt; i++)
		printf("Frequency of %d  = %d\n", res[i], arr[res[i]]);
	return 0;
}
