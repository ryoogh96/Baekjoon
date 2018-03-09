#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
	int T, x1, x2, y1, y2, r1, r2;
	
	cin >> T;
	
	for(int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		double distance = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
		
		if(x1 == x2 && y1 == y2)
		{
			if(r1 == r2)
				cout << "-1" << endl;
			else 
				cout << "0" << endl;
		}
		
		else 
		{
			if(r1 + r2 > distance && distance > abs(r1 -r2))
				cout << "2" << endl;
			else if((r1 + r2) == distance || abs(r1 - r2) == distance)
				cout << "1" << endl;
			else 
				cout << "0" << endl;
		}
	}
	
	
	
	return 0;
	
}
