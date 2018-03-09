// https://www.acmicpc.net/problem/2293
// if 문은 정수 0 이면 false 그외엔 true

#include <iostream>
#include <stdlib.h>
using namespace std;

int n, k;
int *value;
int total = 0;
int chk1, chk2;

void probability(int b, int c) {				
	int chk1 = b;
	int chk2 = c;
	
	if (b == c) {										// 왜 b = 1 c = 2일때 이 if문을 만족하는가?  -> b = c 이 아니라 b == c 을 써야 값이 똑같은지 비교한다.
		if (!(k % (b + c))) {							// k % a 가 0이면 true 그외면 false;
			while (b != k)
				b += c;
			total++;
		}
	}

	while(b + c <= k) {
		if ((k % (b + c))) {
			while (b + c != 10) {						// 1인 b를 점차 증가 시켜 c가 2일때 10이되는 경우의수, c가 4일때, 6일때, ... 10일때까지
				if(b + c <= k)
				b += chk1;
			}
			total++;
			b = chk1;
			c += chk2;
		}

	}
	
	
}
/*
int probability(int d, int e, int f)
{
	int chk2 = d;
	if (!(k % (d + e + f))) {
		while (d + e + f != 10) {
			d += d;
		}
	}
	total++;
	d = chk2;
	e += e;

	return 0;

}
*/

int main()
{	

	cin >> n >> k;
	
	value = new int[n];							//	동전의 갯수 동적 할당	

	for (int i = 0;i < n;i++) {
		cin >> value[i];
	}

		/*
		if (m != n + 1)							//	n이 3이니까 value[2]까지 인수로 전달해 주기 위해
			probability(value[m - 2], value[m - 1]);
		else
			probability(value[m - 2], value[m - 1], value[m]);
		/*
		while (chk1 != 10) {

			chk1 = value[m] + value[m];
		}
		*/
		//probability(value[m]);
	
	for (int m = n; m - 1 >= 0; m--) {
		for (int i = 0; i <= m - 1; i++) {
			for (int j = 0; j <= m - 1; j++) {
				probability(value[i], value[j]);
			}
		}
		// probability(value[m - ?], value[m - ?], value[m - ?]); 

	}
	


	cout << "경우의 수는  : " << total << endl;
	
	
	delete(value);

	system("pause");
	return 0;
}