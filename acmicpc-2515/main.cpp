#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n, s;
int dp[100001];

struct image {
    int h;
    int c;
};

image cur;
image next;

int maxSum() {

    next = s + cur < next.h

    return dp[cur] = max(dp[next] + cur.w, dp[cur], cur.w);
}

int main()
{

    int tmpH, tmpS;
    scanf("%d %d", &n, &s);

    vector<pair<int,int>> height;
    vector<pair<int,int>>::iterator iter;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &tmpH, &tmpS);
        height.push_back(make_pair(tmpH, tmpS));
    }

    sort(height.begin(), height.end());

    for (iter = height.begin(); iter != height.end(); iter++) {
        printf("%d %d\n", iter->first, iter->second);
    }



    return 0;
}
