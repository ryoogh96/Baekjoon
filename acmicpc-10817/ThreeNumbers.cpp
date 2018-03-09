#include <iostream>

using namespace std;


int main() {
	
	int A,B,C;
	
	cin >> A >> B >> C;
	
	if(A > B && A > C) {
		
		if(B > C)
			cout << B << endl;
		else if(C > B)
			cout << C << endl;
		
	}
	
	else if(B > A && B > C) {
		
		if(A > C)
			cout << A << endl;
	 	else if(C > A)
			cout << C << endl;
	}
	
	else if(C > A && C > B) {
		
		if(A > B)
			cout << A << endl;
		else if(B > A)
			cout << B << endl;
	}
	
	if(A == B)
		cout << A << endl;
	else if(A == C)
		cout << A << endl;
	else if(B == C)
		cout << B << endl;
	
	
	return 0;
}