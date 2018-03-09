#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int pTime[1001];

int main()
{
    int n;
    int ans = 0;

    scanf("%d", &n);



    for(int i = 0; i < n; i++){
        scanf("%d",&pTime[i]);
    }

    sort(pTime, pTime + n);

    /*
    for(int i = 0; i < n; i++){

        printf("%d ", pTime[i]);

    }
    */


    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            ans += pTime[j];
        }
    }

    printf("%d", ans);

    return 0;
}
