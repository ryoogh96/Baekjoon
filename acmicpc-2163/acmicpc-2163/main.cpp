

/*								수학적 귀납법 n*m의 초콜릿은 n*m-1의 횟수로 나누어진다. 
#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	cout << n*m - 1;
}
*/

#include <iostream>

using namespace std;

int f_data[300];

int divide(int n, int m)
{
	if (n == 1 && m == 1)
		return 1;



	return f_data[n] = divide(n, m);
}


int main()
{
	int n, m;

	cin >> n >> m;

	cout << n << " " << m;

	cout << divide(n, m) << endl;
	

	return 0;
}