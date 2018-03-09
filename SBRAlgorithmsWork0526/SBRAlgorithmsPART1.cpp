// https://www.acmicpc.net/problem/2293
// if ���� ���� 0 �̸� false �׿ܿ� true

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
	
	if (b == c) {										// �� b = 1 c = 2�϶� �� if���� �����ϴ°�?  -> b = c �� �ƴ϶� b == c �� ��� ���� �Ȱ����� ���Ѵ�.
		if (!(k % (b + c))) {							// k % a �� 0�̸� true �׿ܸ� false;
			while (b != k)
				b += c;
			total++;
		}
	}

	while(b + c <= k) {
		if ((k % (b + c))) {
			while (b + c != 10) {						// 1�� b�� ���� ���� ���� c�� 2�϶� 10�̵Ǵ� ����Ǽ�, c�� 4�϶�, 6�϶�, ... 10�϶�����
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
	
	value = new int[n];							//	������ ���� ���� �Ҵ�	

	for (int i = 0;i < n;i++) {
		cin >> value[i];
	}

		/*
		if (m != n + 1)							//	n�� 3�̴ϱ� value[2]���� �μ��� ������ �ֱ� ����
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
	


	cout << "����� ����  : " << total << endl;
	
	
	delete(value);

	system("pause");
	return 0;
}