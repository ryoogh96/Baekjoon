#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 100;
int V;
vector<pair<int, int>> adj[MAX_V];

int n;

struct NaiveDisjointSet {
	vector<int> parent;

	NaiveDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int ffind(int u) {
		if (n == parent[u])
			return u;
		return ffind(parent[u]);
	}

	void mmerge(int u, int v) {
		u = ffind(u); v = ffind(v);

		if (u == v)
			return;
		parent[u] = v;
	}

	bool sameSet(int u, int v) {
		u = ffind(u); v = ffind(v);

		if (u == v)
			return true;
		return false;
	}


};

/*vector<pair<int, int>>& selected*/
int kruskal() {
	int ret = 0;
	//selected.clear();
	vector<pair<int, pair<int, int>>> edges;
	for (int u = 0; u < V; ++u)
		for (int i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first, cost = adj[u][i].second;
			edges.push_back(make_pair(cost, make_pair(u, v)));
		}

	sort(edges.begin(), edges.end());

	NaiveDisjointSet sets(V);
	for (int i = 0; i < edges.size(); ++i) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;

		if (sets.ffind(u) == sets.ffind(v))
			continue;
		sets.mmerge(u, v);
		//selected.push_back(make_pair(u, v));
		ret += cost;
	}
	return ret;
}

int main()
{
	int m;
	int from, to, val;
	scanf("%d %d", &n, &m);
	V = n;

	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &from, &to, &val);
		adj[from].push_back(make_pair(to, val));
	}

	printf("%d", kruskal());

	return 0;
}
