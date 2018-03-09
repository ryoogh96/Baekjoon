#include <bits/stdc++.h>

using namespace std;

struct Village
{
    int Sent;
    int Dest;
};

int main()
{
    vector<Village> v;
    int N, C, M;
    scanf("%d %d", &N, &C);
    Village village[N];
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &village[i].Sent, &village[i].Dest, &village[i].Weight);
        v.push_back(village[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < M; i++) {

    }


    return 0;
}
