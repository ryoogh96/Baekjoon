#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;
int tmpRank = 1;
int tmptmpRank;

struct fat
{
    int weight;
    int height;
    int rankNum;
    int order;
};

bool fatcompare(fat lhs, fat rhs) {return lhs.weight > rhs.weight && lhs.height > rhs.height;}
bool fatordercomp(fat lhs, fat rhs) {return lhs.order < rhs.order;}
//bool fatrankcomp(fat lhs, fat rhs) {return lhs.rankNum < rhs.rankNum;}



fat Fat[205];

void getRank()
{
    //bool isSame = false;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &Fat[i].weight, &Fat[i].height);
        Fat[i].order = i;
    }

    //sort(Fat, Fat+n, fatcompare);

    /*
    cout << endl;

    for(int i = 0; i < n; i++)
    {
        printf("%d %d\n", Fat[i].weight, Fat[i].height);
    }
    */
    /*
    for(int i = 0; i < n-1; i++)
    {
        if(Fat[i].weight > Fat[i+1].weight && Fat[i].height > Fat[i+1].height)
        {
            Fat[i].rankNum = tmpRank++;
            tmptmpRank++;
        }
        //else if(Fat[i].weight > Fat[i+1].weight || Fat[i].height > Fat[i+1].height)
        else
        {
            Fat[i].rankNum = tmpRank;
            tmptmpRank++;
        }

        // set the Last people's rankNum
        if(i == n-2) Fat[n-1].rankNum = tmptmpRank;

    }

    //sort(Fat, Fat+n, fatrankcomp);
    sort(Fat, Fat+n, fatordercomp);

    */
    //tmpRank = n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i!=j)
            {
                if(Fat[i].weight < Fat[j].weight && Fat[i].height < Fat[j].height)
                    tmpRank++;
                //else if(Fat[i].weight > Fat[j].weight && Fat[i].height > Fat[j].height)
                  //  tmpRank++;
                /*
                // 몸무게나 키 둘중 하나가 작거나 둘다 같으면 같은 등수를 매긴다.
                if(!isSame)
                {
                    Fat[i].rankNum = tmpRank++;
                    isSame = true;
                }
                else Fat[i].rankNum = tmpRank;
                */
            }

        }
        Fat[i].rankNum = tmpRank;
        tmpRank = 1;
        //tmpRank = n;
        //isSame = false;
    }


    for(int i = 0; i < n; i++)
    {
        printf("%d ", Fat[i].rankNum);
    }

}

int main()
{
    getRank();

    return 0;
}
