#include <stdio.h>

// Solution by Official KOI
int N, d[100], P;

int main()
{
    int cur,cnt;
    scanf("%d %d", &N, &P);
    cur = N % P;
    cnt = 1;

    while(1)
    {
        d[cur] = cnt++;
        cur = cur * N % P;
        if(d[cur])
        {
            printf("%d", cnt - d[cur]);
            break;
        }
    }
    return 0;
}


/*
int getDiffValues()
{
    int cnt = 0, diffCnt = 0;
    int n,p,remainder, cyclePos, startPos;
    bool isCycle = false;
    vector<int> remain;
    scanf("%d %d", &n, &p);
    remainder = n;

    /*
    for(int i = 0; i < 5; i++)
    {
        remainder = remainder * n % p;
        printf("%d\n", remainder);

    }


    while(!isCycle)
    {
        remainder = remainder * n % p;
        remain.push_back(remainder);

        /* if start number and second num is same print 0
        if(remain.at(0) == remainder && cnt == 1)
        {
                return 0;
        }


        for(int i = 0; i < cnt; i++)
        {
            if(remainder == remain.at(i))
                {
                    //printf("%d\n", remainder);
                    //printf("YES CYCLE\n");
                    isCycle = true;
                    cyclePos = cnt;
                    startPos = i+1;
                }
        }
        if(!isCycle)
        {
            cnt++; //printf("%d\n",cnt);
        }
        /*
        if(cnt > 1)
            // if start number and second num is not same diffcnt++
            if(remainder != remain.at(cnt-1)) diffCnt++;

    }

    if(cyclePos - startPos == 0) return 1;

    for(int i = startPos; i < cyclePos; i++)
    {
        if(remain.at(i) == remainder) cnt -= 1;
    }


    //printf("NO CYCLE\n");
    //printf("0");
    return cnt;
}

int main()
{
    printf("%d", getDiffValues());

    return 0;
}
*/
