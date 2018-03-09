#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

/* 4

1 2 3 4

1 + 2 = 3

// 위의 케이스에 성립하지 않는다.
모든 특성값의 양 끝값 (최소값과 최대값) 부터 특성값을 구하기

그런 다음 특성값들의 절대값이 제일 작은 값의 양 끝값을 출력하면 답이다.
*/
int solutions[100005];
int halfSols;

void getAns()
{
    int n, half;
    int num = 0x3f3f3f3f;
    bool nFlag = false, pFlag = false;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &solutions[i]);
        if(solutions[i] < 0) nFlag = true;
        else if(solutions[i] > 0) pFlag = true;
    }

    // only negative input
    if(nFlag && !pFlag)
        printf("%d, %d", solutions[n-2], solutions[n-1]);
    // only positive input
    else if(!nFlag && pFlag)
        printf("%d, %d", solutions[0], solutions[1]);


    if(nFlag && pFlag)
    {
        half = n / 2;

        int cnt = n - 1;

        for(int i = 0; i < half; i++)
        {
            if(abs(solutions[i] + solutions[cnt-i]) < num &&
               abs(solutions[i] + solutions[cnt-i]) != 0)
            {
                num = abs(solutions[i] + solutions[cnt-i]);
                halfSols = i;
            }
        }

        printf("%d %d", solutions[halfSols], solutions[cnt-halfSols]);
    }
}

int main()
{

    getAns();

    return 0;
}



/* Too much time consuming 2018/01/25
int solution[100005];

void getAns()
{
    FILE* pFile;

    pFile = fopen("test.txt", "r");

    int n, temp, ans1, ans2, max, forcnt;
    int min = 0x3f3f3f3f;
    int cnt = 0;
    fscanf(pFile,"%d", &n);

    for(int i = 0; i < n; i++)
    {
        fscanf(pFile,"%d", &solution[i]);
    }

    fclose(pFile);

    FILE* wFile;

    wFile = fopen("result.txt", "w");


    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
        {
            temp = solution[i] + solution[j];

            fprintf(wFile, "%d ", temp);

        }


}

int main()
{
    getAns();

}
*/
