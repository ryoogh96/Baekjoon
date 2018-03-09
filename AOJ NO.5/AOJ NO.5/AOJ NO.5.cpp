#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, b;


	cin >> n >> m >> b;

	std::vector<int> x(n); std:vector<int> y(n); std::vector<int> dmg(n);
	std::vector<vector<int> > array2d(n, std::vector<int>(m, 0));
	std::vector<vector<int> > bomb(b, std::vector<int>(3, 0));

	for (int i = 0; i < n; i++)								
	{
		for (int j = 0; j < m; j++)
		{
			cin >> array2d[i][j];
		}
	}

	for (int i = 0; i < b; i++)								
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> bomb[i][j];
		}
		x[i] = bomb[i][0]; y[i] = bomb[i][1]; dmg[i] = bomb[i][2];
	}

	for (int i = 0; i < b; i++)								
	{
		int x1 = x[i]; int y1 = y[i]; int dmg1 = dmg[i];

		for (int j = x1 - 1; j <= x1 + 1; j++)
		{
			if (j - 1 < 0)
				j = 0;
			for (int k = y1 - 1; k <= y1 + 1; k++)
			{
				if (k - 1 < 0)
					k = 0;
				array2d[j][k] -= dmg1;
				if (array2d[j][k] < 0)
					array2d[j][k] = 0;
			}
		}

	}

	for (int i = 0; i < n; i++)								
	{
		for (int j = 0; j < m; j++)
		{
			cout << array2d[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}