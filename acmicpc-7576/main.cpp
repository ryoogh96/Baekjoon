#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int arrBox[1001][1001];

class Graph {
    int V;

    list<int> *adj;

    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);

    void addEdge(int v, int w);

    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    printf("%d ", v);

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

int main()
{
    int boxSizeX, boxSizeY;

    scanf("%d %d", &boxSizeX, &boxSizeY);

    Graph box(boxSizeX * boxSizeY);

    for(int i = 0; i < boxSizeX; ++i)
        for(int j = 0; j < boxSizeY; ++j) {
                scanf("%d", &arrBox[i][j]);
        }

    for(int i = 0; i < boxSizeX; ++i)
        for(int j = 0; j < boxSizeY; ++j) {
            if(arrBox[i][j] == 1) {
                box.addEdge(i,i-1);
                box.addEdge(i,i+1);
                box.addEdge(j,j-6);
                box.addEdge(j,j+6);
            }
            box.DFS()
        }





    return 0;
}
