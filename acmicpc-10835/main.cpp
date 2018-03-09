#include <iostream>

using namespace std;

int dp_data[20000][20000] = {0,};
int LeftCard[10000500] = {0,} , RightCard[10000500] = {0,};

int Rule(int N) {

    int a = 0, b = 0;
    for(int i = 0; i < N; i++) {
        if(LeftCard[i] > RightCard[i])  {

            return dp_data[a][b] = Rule(i,j) + Rule(a,b-1);

            return dp_data[a][b] = Rule(i,j) + Rule(a-1,b);

            return dp_data[a][b] = Rule(i,j) + Rule(a-1,b-1);
            }
    }



}



int main()
{
    int N;
    int FinalScore = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> LeftCard[i];

    }

    for(int i = 0; i < N; i++) {
        cin >> RightCard[i];

    }

    for(int i = 0; i < N; i++) {
       Rule(i);
    }



    /*
    int i = 0, j = 0; int LeftCard[N], RightCard[N];

    while(RightCard[j] <= LeftCard[N]) {

        if(RightCard[j] <= LeftCard[i]) {
            FinalScore += RightCard[j];
            j++;
        }
        else j++;
    }
    */



    return 0;
}

