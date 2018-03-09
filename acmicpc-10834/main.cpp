#include <iostream>

using namespace std;

int main()
{
    int NumOfBelt;
    int LastBeltType = 0;
    int PrevB = 1;

    cin >> NumOfBelt;

    for(int i = 0; i < NumOfBelt; i++) {

    int a, b, BeltType;

    cin >> a >> b >> BeltType;

    if(BeltType == 1)
        LastBeltType++;

    PrevB /= a;

    PrevB *= b;
    }

    if(LastBeltType %2 == 0)
        LastBeltType = 0;
    else if(LastBeltType %2 == 1)
        LastBeltType = 1;


    cout << LastBeltType << " " << PrevB << endl;


    return 0;
}
