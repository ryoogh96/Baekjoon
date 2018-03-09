#include <cstdio>



int commonDivisor()
{
    int n,k;
    scanf("%d %d", &n, &k);


    int cnt = 0;
    int tmp = n+1;
    while(cnt!=k)
    {
        tmp--;

        if(tmp == 0)
            break;

        if(n % tmp == 0)
        {
            cnt++;
        }



    }

    if(tmp == 0) printf("0");
    else printf("%d", n / tmp);

}

int main()
{
    commonDivisor();
    return 0;
}
