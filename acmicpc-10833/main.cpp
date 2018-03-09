#include <iostream>

using namespace std;

int main()
{
    int NumOfSchool, LeftApple;
    int LeftTotalApples = 0;


    cin >> NumOfSchool;

    for(int i = 0; i < NumOfSchool; i++) {

    int NumOfStudents, NumOfApple, DividedApple;

    cin >> NumOfStudents >> NumOfApple;

    DividedApple = NumOfApple / NumOfStudents * NumOfStudents;

    LeftApple = NumOfApple - DividedApple;

    LeftTotalApples += LeftApple;

    }


    cout << LeftTotalApples << endl;


    return 0;
}
