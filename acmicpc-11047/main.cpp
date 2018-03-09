#include <cstdio>


int coin[11];

int findMinNum(int num, int coinNum, int kWon) {
	if (kWon == 0) return num;
	else if (kWon < coin[coinNum]) { coinNum--;  return findMinNum(num, coinNum, kWon); }


	num += kWon / coin[coinNum];
	kWon %= coin[coinNum];
	coinNum--;
	return findMinNum(num, coinNum, kWon);
}

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	if (n == 1) { printf("%d", k / coin[0]); return 0;}

	for (int i = 0; i < n; i++) {
		if (k < coin[i + 1]) {
			printf("%d", findMinNum(0, i, k));
			break;
		}
        else if(i == n - 1)
            printf("%d", findMinNum(0, i, k));
	}



	return 0;
}
