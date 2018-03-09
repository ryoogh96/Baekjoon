#include <iostream>

using namespace std;

int main()
{
    static int _Button_A = 300, _Button_B = 60, _Button_C = 10;

    int Acount = 0, Bcount = 0, Ccount = 0;
    int T;

    cin >> T;

    while(T != 0) {

             if(T >= 300)           { Acount = T / _Button_A;   T %= _Button_A;}
        else if(T >= 60 && T < 300) { Bcount = T / _Button_B;   T %= _Button_B;}
        else if(T >= 10 && T < 60)  { Ccount = T / _Button_C;   T %= _Button_C;}
        else if(T < 10) break;

    }


    if(T == 0) cout << Acount << " " << Bcount << " " << Ccount << endl;
    else cout << "-1" << endl;

    return 0;
}
