#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int rope[100001];


int compare (const int lhs, const int rhs) {
    if(lhs < rhs) return lhs;
    else if(lhs > rhs) return rhs;
}


int main()
{
    int n;
    int minimum = 0, ans = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &rope[i]);
    }

    sort(rope, rope + n);

    for(int i = 0; i < n - 1; i++) {
        ans = compare(rope[i], rope[i+1]);
    }
    ans += rope[n];



    printf("%d", ans);


    return 0;
}
