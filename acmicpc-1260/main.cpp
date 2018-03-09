#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

/* DFS implementation by geeksforgeeks and add BFS from geeksforgeeks 2018/01/10
https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/ */

// Graph class represents a directed graph
// using adjacency list representation
/*
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);

    // prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    printf("%d ", v);

    adj[v].sort();

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;



    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{

    int adjNum, edgeNum, start, startEdge, reachEdge;
    scanf("%d %d %d", &adjNum, &edgeNum, &start);

    Graph g(adjNum+1);

    for(int i = 0; i < edgeNum; ++i) {
        scanf("%d %d", &startEdge, &reachEdge);
        g.addEdge(startEdge, reachEdge);
    }


    g.DFS(start);

    printf("\n");

    g.BFS(start);

    /*Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);


    g.DFS(1);


    return 0;
}
*/

/* BFS implementation by geeksforgeeks 2018/01/10
https://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/ */
// This class represents a directed graph using
// adjacency list representation
/*
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
*/

// C++ program to print DFS traversal for a given given graph
/*
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS();    // prints DFS traversal of the complete graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

int main()
{
    int adjNum, edgeNum, start, startEdge, reachEdge;
    scanf("%d %d %d", &adjNum, &edgeNum, &start);

    Graph g(adjNum);

    for(int i = 0; i < edgeNum; ++i) {
        scanf("%d %d", &startEdge, &reachEdge);
        g.addEdge(startEdge, reachEdge);
    }


    g.DFS();

    return 0;
}
*/











// JongManBook 2018/01/10

int adjNum, lineNum, start;

vector<int> adj[1005];
vector<bool> visited;



void dfs(int here) {
    printf("%d ", here);
    visited[here] = true;



    for(int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i];


        if(!visited[there])
            dfs(there);
    }
}

void dfsAll() {
    visited = vector<bool>(adjNum, false);

    dfs(start);

}

void bfs(int start) {
    vector<bool> discovered(adjNum, false);
    queue<int> q;
    vector<int> order;

    discovered[start] = true;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        order.push_back(here);

        for(int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i];

            if(!discovered[there]) {
                q.push(there);
                discovered[there] = true;
            }
        }
    }
    for(int i = 0; i < order.size(); ++i) {
        printf("%d ", order[i]);
    }
}

int main()
{
    scanf("%d %d %d", &adjNum, &lineNum, &start);


    for(int i = 0; i < lineNum; ++i) {
        int cur, next;
        scanf("%d %d", &cur, &next);

        adj[cur].push_back(next);
        adj[next].push_back(cur);
    }

    for(int i = 1; i <= adjNum; ++i)
        sort(adj[i].begin(), adj[i].end());

    dfsAll();

    printf("\n");

    bfs(start);

    return 0;
}

