#include <cstdio>
#include <bits/stdc++.h>

using namespace std;


// solution by http://www.crocus.co.kr/619
int V;
const int MAX_V = 1001;
const int INF = 0x3f3f3f3f;
vector<pair<int,int>> adj[MAX_V];


vector<int> dijkstra(int src, int V, int E) {
    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,src));

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;

            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main()
{
    int m;
    int from, to, val;
    scanf("%d", &V);
    scanf("%d", &m);

    V++;

    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &from, &to, &val);
        adj[from].push_back(make_pair(to, val));
    }

    int start, finish;
    scanf("%d %d", &start, &finish);

    vector<int> ans = dijkstra(start, V, m);

    printf("%d", ans[finish]);

    return 0;
}
