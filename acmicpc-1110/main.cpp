#include <iostream>

using namespace std;

int cycle = 0;

void Calc(int *num)
{
    int n1 = *num / 10;
    int n2 = *num % 10;
    int n3 = n1 + n2;

    *num = n2 * 10 + n3 % 10;
    ++cycle;


}

int main()
{
    int origin;
    int numba;
    cin >> numba;
    origin = numba;


    Calc(&numba);

    while(origin != numba)
    {
        Calc(&numba);
    }

    cout << cycle << endl;

    return 0;
}
