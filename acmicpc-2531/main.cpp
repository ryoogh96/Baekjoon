#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n,d,k,c,tmp;
int sushi[30005];


int maxSushi()
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {

            for(int l = j+1; l < j+k; l++)
            {

            }
        }
    }


}


int main()
{
    scanf("%d %d %d %d", &n, &d, &k, &c);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &sushi[i]);
    }


    return 0;
}




/*  vector<pair<int,bool> > sushi for O(n^(i+k))
//int sushi[30005];
//bool sushiKind[3005] = {false,};

vector<pair<int,bool> > sushi;

int maxSushiVal()
{
    int n,d,k,c,tmp;
    int cnt = 1, maxWays = 0;;
    scanf("%d %d %d %d", &n, &d, &k, &c);

    //printf("k : %d\n\n\n", k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        sushi.push_back(make_pair(tmp,false));
    }

    //printf("k : %d\n\n\n", k);

    // O(n^(i+k))
    for(int i = 0; i < n; i++)
    {
        sushi[i].second = true;

        //printf("k : %d\n\n\n", k);

        // if first one is coupon skip it
        if(sushi[i].first == c) i++;
        //printf("i : %d\n\n", i);
        // comp first with second and count max
        for(int j = i+1; j < i+k; j++)
        {
            //printf("j : %d\n\n\n", j);
            cnt++;
            //printf("cnt : %d\n\n", cnt);
            //if this sushi already in list reset else set it true
            if(sushi[j].second)
            {
                cnt = 1; break;
            }
            else sushi[j].second = true;

            // if there is coupon in belt reset count and skip it
            if(sushi[j].first == c)
            {
                cnt = 1; break;
            }
        }

        if(cnt > maxWays) maxWays = cnt;
        //printf("cnt : %d maxWays : %d\n\n\n", cnt, maxWays);
        // reset eaten sushi kind
        for(int i = 0; i < n; i++)
        {
            sushi[i].second = false;
        }
    }

    return maxWays+1;
}

int main()
{

    printf("%d", maxSushiVal());

    return 0;
}
*/
