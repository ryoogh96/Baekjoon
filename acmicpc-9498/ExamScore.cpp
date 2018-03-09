#include <iostream>

using namespace std;

int main()
{
	
	int Score;
	
	cin >> Score;
	
	if(90 <= Score <= 100)
			cout << "A" << endl;
		else if(80 <= Score <= 89)
				cout << "B" << endl;
			else if(70 <= Score <= 79)
					cout << "C" << endl;
				else if(60 <= Score <=69)
						cout << "D" << endl;
					else cout << "F" << endl;
					
	return 0;
}