#include <stdio.h>
#include <string.h>
#include <time.h>
int s[256], t[256], keyLength, key[256];
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main() {
	puts("Enter the key length :");
	scanf("%d", &keyLength);
	if (keyLength > 256 || keyLength < 1) {
		puts("key must be between 1 and 256 bytes");
		return 0;
	}
	time_t tt;
	srand((unsigned) time(&tt));
	int i, j;
	for (i = 0; i < keyLength; i++)
		key[i] = rand() % 256; // Each value must be 8 bits
	for (i = 0; i < 256; i++) {
		s[i] = i;
		t[i] = key[i % keyLength];
	}
	for (i = j = 0; i < 256; i++) {
		j = (j + s[i] + t[i]) % 256;
		swap(&s[i], &s[j]);
	}
	int Result_Key, t, cnt, a, nub;
	i = 0, j = 0;
	puts("Enter the number of keys you want to generate :");
	scanf("%d", &nub);
	for (cnt = 0; cnt < nub; cnt++) {
		i = (i + 1) % 265;
		a = s[i];
		j = (j + s[i]) % 265;
		swap(&s[i], &s[j]);
		t = (s[((i << 5) ^ (j >> 3)) % 256] + s[((j << 5) ^ (i >> 3)) % 256])
				% 265;
		Result_Key = ((s[(a + s[i]) % 256] + s[(t ^ (0xAA)) % 256])
				^ s[(j + s[i]) % 256]) % 265;
		printf("key %d: %ld \n", cnt + 1, Result_Key);
	}
	return 0;
}
