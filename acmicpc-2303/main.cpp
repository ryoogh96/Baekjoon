#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int p[1001][5];

struct GreatestNumber
{
    int value;
    int number;
};

GreatestNumber gNum[1001];

int winNum()
{
    int n,cmp1,cmp2;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }



    /* Failed don't search all the patterns
    // Find the greatest number from each person
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        gNum[i].number = i+1;

        printf("gNum[%d] : \n\n\n", i+1);

        gNum[i].value = max((p[i][j] + p[i][j+1] + p[i][j+2]) % 10, (p[i][j] + p[i][j+1] + p[i][j+3]) % 10 );

        printf("%d %d\n\n", (p[i][j] + p[i][j+1] + p[i][j+2]) % 10, (p[i][j] + p[i][j+1] + p[i][j+3]) % 10 );


        gNum[i].value = max(gNum[i].value, (p[i][j] + p[i][j+1] + p[i][j+4]) % 10 );

        printf("%d %d\n\n", gNum[i].value, (p[i][j] + p[i][j+1] + p[i][j+4]) % 10);

        gNum[i].value = max(gNum[i].value, (p[i][j+1] + p[i][j+2] + p[i][j+3]) % 10 );

        printf("%d %d\n\n", gNum[i].value, (p[i][j+1] + p[i][j+2] + p[i][j+3]) % 10 );

        gNum[i].value = max(gNum[i].value, (p[i][j+1] + p[i][j+2] + p[i][j+4]) % 10 );

        printf("%d %d\n\n", gNum[i].value, (p[i][j+1] + p[i][j+2] + p[i][j+4]) % 10);

        gNum[i].value = max(gNum[i].value, (p[i][j+2] + p[i][j+3] + p[i][j+4]) % 10 );

        printf("%d %d\n\n", gNum[i].value, (p[i][j+2] + p[i][j+3] + p[i][j+4]) % 10);

        printf("gNum[%d].number = %d\n\n\n", gNum[i].number, gNum[i].value);
    }
    */

    // https://github.com/iljimae0418/BOJ/blob/master/boj2303.cpp#L47
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = j+1; k < 5; k++)
            {
                for(int l = k+1; l < 5; l++)
                {
                    gNum[i].value = max(gNum[i].value, (p[i][j] + p[i][k] + p[i][l]) % 10);
                }
            }
        }
        gNum[i].number = i+1;
    }

    GreatestNumber ans;

    ans = gNum[0];

    for(int i = 0; i < n-1; i++)
    {
        if(ans.value < gNum[i+1].value) ans = gNum[i+1];
        else if(ans.value == gNum[i+1].value && ans.number < gNum[i+1].number) ans.number = gNum[i+1].number;
    }

    return ans.number;
}

int main()
{
    printf("%d", winNum());
    return 0;
}
