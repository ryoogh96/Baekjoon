#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 1001;
int V;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> adj[MAX_V];

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


/*vector<pair<int, int>>& selected*/

int kruskal() {
    int ret = 0;
    //selected.clear();
    vector<pair<int, pair<int, int>>> edges;
    for(int u = 0; u < V; ++u)
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }

    sort(edges.begin(), edges.end());


    OptimizedDisjointSet sets(V);
    for(int i = 0; i < edges.size(); ++i) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;

        if(sets.find(u) == sets.find(v))
            continue;
        sets.merge(u, v);
        //selected.push_back(make_pair(u, v));
        ret += cost;
    }
    return ret;
}


/*
int prim() {
    vector<bool> added(V, false);
    vector<int> minWeight(V, INF), parent(V, -1);
    int ret = 0;
    minWeight[0] = parent[0] = 0;

    for(int iter = 0; iter < V; ++iter) {
        int u = -1;
        for(int v = 0; v < V; ++v)
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;
        ret+= minWeight[u];
        added[u] = true;

        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first, weight = adj[u][i].second;
            if(!added[v] && minWeight[v] > weight) {
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }
    return ret;
}
*/

int main()
{
    int m;
    int from, to, val;
    scanf("%d %d", &V, &m);
    V++;

    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &val);
        adj[from].push_back(make_pair(to, val));
    }

    printf("%d", kruskal());

    return 0;
}
