#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
/*
struct Tower
{
    int height;
    int number;
    int ans;
};
*/

// Solution by http://hsp1116.tistory.com/30
int main()
{
    stack<pair<int,int> > tower;
    int n,height;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &height);

        while(!tower.empty())
        {
            if(tower.top().second > height)
            {
                printf("%d ", tower.top().first);
                tower.push(make_pair(i+1,height));
                break;
            }
            else tower.pop();
        }

        if(tower.empty()) printf("0 ");
        tower.push(make_pair(i+1,height));
    }


    /*
    int n,tmp;
    stack<Tower> sTower;
    stack<Tower> tmpTower;
    stack<Tower> ansTower;
    Tower tower;
    Tower tmp1;
    Tower tmp2;
    //pair<int,int> cmp1, cmp2;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        tower.height = tmp; tower.number = i+1;
        sTower.push(tower);
    }

    tmp1 = sTower.pop();
    while(!sTower.empty())
    {
        tmp2 = sTower.pop();
        if(tmp2.height > tmp1.height)
        {
            tmp1.ans = tmp2.number;
            ansTower.push(tmp1);
            tmp1 = tmp2;
        }
        //else tmpTower.push(tmp2);


    }

    while(!ansTower.empty())
    {
        tmp1 = ansTower.pop();
        printf("%d ", tmp1.ans);
    }

    /*
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Tower[i].height);
        Tower[i].number = i+1;
        //tower.push(make_pair(n-i,tmp));
    }

    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i-1; j >=0; j--)
        {
            if(Tower[i].height < Tower[j].height)
                {
                    ans[i] = Tower[j].number;
                    break;
                }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    /*
    cmp1 = tower.pop();

    while(!tower.empty())
    {
        cmp2 = tower.pop();

        if(cmp2 > cmp1)
    }
    */
    return 0;
}
