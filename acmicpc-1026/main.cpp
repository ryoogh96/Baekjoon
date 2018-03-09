#include <iostream>

using namespace std;

int main()
{
    int N, i, temp;

    int total = 0;

    cin >> N;
    temp = N;


    int *A = new int[N];
    int *B = new int[N];


    for(i = 0; i < N; i++){
        cin >> temp;
        A[i] = temp;
    }

    for (i = 0; i < N; i++){
        cout << A[i] << " ";
    }


    for(i = 0; i < N; i++){
        cin >> temp;
        B[i] = temp;
    }

    for (i = 0; i < N; i++){
        cout << B[i] << " ";
    }

    for (i = 0; i < N; i++){
        total += A[i] * B[i];
    }

    cout << total << endl;

    return 0;
}
