#include <stdio.h>

int f_data[40] = {1,1,};


int fibonacci(int n) {
    if ( n <= 1) return f_data[n];
	else {
		if(f_data[n] > 0) return f_data[n];
	}
	return f_data[n] = fibonacci(n-1) + fibonacci(n-2);
}

int main(void) {
	int T;

	scanf("%d", &T);
	for (int i = 0; i<T; i++) {
		int test;
		scanf("%d", &test);
		if (test == 0) printf("1 0\n");
		else if(test == 1) printf("0 1\n");
		else{
			fibonacci(test);
			printf("%d %d\n",f_data[test-2],f_data[test-1]);

        }
	}

	return 0;
}

