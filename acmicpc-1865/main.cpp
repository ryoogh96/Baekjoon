#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int INF = 0x3f3f3f3f;

int V;
vector<pair<int,int>> adj[501];
bool bellmanFord(int src) {
    vector<int> upper(V, INF);
    upper[src] = 0;

    for(int iter = 0; iter < V-1; ++iter) {
        for(int here = 0; here < V; ++here){
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                }
            }
        }
    }

    bool negative_cycle = false;

        for(int here = 0; here < V; ++here) {
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[there] > upper[here] + cost) {
                    negative_cycle = true;
                    return true;
                }
            }
        }
    return false;

}

int main()
{
    int T;
    scanf("%d", &T);
    int n,m,w;
    int s,e,t;
    scanf("%d %d %d", &n, &m, &w);

    V = n;


    while(T--) {

        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &t);
            s--;
            e--;
            adj[s].emplace_back(e,t);
            adj[e].emplace_back(s,t);
        }


        for(int i = 0; i < w; i++) {
            scanf("%d %d %d", &s, &e, &t);
            s--;
            e--;
            adj[s].emplace_back(e, -t);
        }
        if(bellmanFord(1)) printf("YES\n");
        else printf("NO\n");

    }





    return 0;
}
