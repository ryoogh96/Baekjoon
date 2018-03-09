#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n,m,height,start,meltCnt,cnt;
vector<int> adj[301];
vector<bool> visited[301];
vector<int> tmpadj[301];
bool allMelt = true;

void melt(int ty, int tx)
{
    //printf("%d ", adj[ty][tx]);
    visited[ty][tx] = true;

    if(tmpadj[ty][tx] > 0)
    {
        if(adj[ty-1][tx] == 0) tmpadj[ty][tx]--;
        if(adj[ty][tx-1] == 0) tmpadj[ty][tx]--;
        if(adj[ty+1][tx] == 0) tmpadj[ty][tx]--;
        if(adj[ty][tx+1] == 0) tmpadj[ty][tx]--;

        if(tmpadj[ty][tx] < 0) tmpadj[ty][tx] = 0;
    }



    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            if(!visited[y][x])
                melt(y,x);
        }
    }
}

void visitedFalse()
{
    for(int i = 0; i < 301; i++)
        visited[i] = vector<bool>(301,false);


}

void searchMass(int ty, int tx)
{
    //printf("%d ", adj[ty][tx]);
    visited[ty][tx] = true;

    if(adj[ty][tx] > 0)
    {
        if(adj[ty-1][tx] == 0 && adj[ty][tx-1] == 0
            && adj[ty+1][tx] == 0 && adj[ty][tx+1] == 0)
            meltCnt++;

        allMelt = false;
    }

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            if(!visited[y][x])
                searchMass(y,x);
        }
    }
}

void dfs()
{
    visitedFalse();
    melt(0,0);

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            adj[y][x] = tmpadj[y][x];
        }
    }

    //printf("\n\n\n");

    /*
    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            printf("%d ",adj[y].at(x));
        }
            printf("\n");
    }
    */

    meltCnt = 0;

    visitedFalse();
    searchMass(0,0);

    cnt++;
}

int main()
{

    scanf("%d %d", &n, &m);

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < m; x++)
        {
            scanf("%d", &height);
            adj[y].push_back(height);
            tmpadj[y].push_back(height);
        }
    }

    while(meltCnt < 2)
    {
        dfs();
        if(allMelt) break;
    }

    if(meltCnt == 0) printf("0");

    printf("%d", cnt);


    return 0;
}
