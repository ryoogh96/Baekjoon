#include <iostream>
#include <cstring>

using namespace std;

int main() {
	
	char Sentences[101] = {0,};
	
	
	
	
	
	for(int i = 0; i < 100; i++) {
		
		cout << Sentences[i];
				
		if((i + 1) % 10 == 0 && i != 0) {
				
		if(Sentences[i] == 0)
			break;
			else 
				cout << endl;
		}
		
	}
	
	
	return 0;
}