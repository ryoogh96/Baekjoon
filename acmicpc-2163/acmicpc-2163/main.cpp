

/*								������ �ͳ��� n*m�� ���ݸ��� n*m-1�� Ƚ���� ����������. 
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