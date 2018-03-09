#include <cstdio>
#include <bits/stdc++.h>


int a[10], b[10];
int aScore, bScore;
bool aLastWin = false, bLastWin = false;

void result() {
    for(int i = 0; i < 10; i++) {
        if(a[i] > b[i]) {
            aScore += 3;
            aLastWin = true;
            bLastWin = false;
        }
        else if(b[i] > a[i]) {
            bScore += 3;
            aLastWin = false;
            bLastWin = true;
        }
        else if(a[i] == b[i]) {
            aScore++;
            bScore++;
        }
    }

    printf("%d %d\n", aScore, bScore);

    if(aScore > bScore) printf("A");
    else if(bScore > aScore) printf("B");
    else if(aScore == bScore)
            if(aLastWin) printf("A");
            else if(bLastWin) printf("B");
            else if(!(aLastWin && bLastWin)) printf("D");
}


int main()
{
    for(int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 10; i++) {
        scanf("%d", &b[i]);
    }


    result();


    /*
    for(int i : A) {
        printf("%d ", i);
    }

    printf("\n");

    for(int i : B) {
        printf("%d ", i);
    }
    */
    return 0;
}
