#include <cstdio>
#include <bits/stdc++.h>

int n;


using namespace std;

// Jong Man Book 25.1
struct OptimizedDisjointSet {
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n,1) {
        for(int i = 0 ; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);

        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);

        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }

    bool sameSet(int u, int v) {
        u = find(u); v = find(v);

        if(u == v) return true;
        if(rank[u] > rank[v]) swap(u, v);

        parent[u] = v;
        if(rank[u] == rank[v]) ++rank[v];
    }
};


// http://ksj14.tistory.com/entry/BeakJoon1717-%EC%A7%91%ED%95%A9%EC%9D%98-%ED%91%9C%ED%98%84
int main()
{
    int m;
    int instruct, a, b;
    bool isSameSet = false;
    scanf("%d %d", &n, &m);
    n++;
    OptimizedDisjointSet disJointSet(n);

    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &instruct, &a, &b);
        if(instruct == 0) disJointSet.merge(a,b);
        else if(instruct == 1) {
            if(disJointSet.find(a) == disJointSet.find(b))
                printf("YES\n");
                else printf("NO\n");
        }
    }


    return 0;
}
