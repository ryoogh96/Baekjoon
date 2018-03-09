#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Solution by https://github.com/kks227/BOJ/blob/master/2400/2495.cpp
int main()
{
    char fst[9], sec[9], thd[9];
    int cnt = 1;
    int ans = 1;
    scanf("%s", fst);
    scanf("%s", sec);
    scanf("%s", thd);

    for(int j = 0; j < 8; j++)
    {
        if(fst[j] == fst[j+1]) cnt++;
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
        }
    }

    printf("%d\n", ans);

    ans = 1;

    for(int j = 0; j < 8; j++)
    {
        if(sec[j] == sec[j+1]) cnt++;
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
        }
    }

    printf("%d\n", ans);

    ans = 1;

    for(int j = 0; j < 8; j++)
    {
        if(thd[j] == thd[j+1]) cnt++;
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
        }
    }

    printf("%d\n", ans);

    ans = 1;


    return 0;
}
