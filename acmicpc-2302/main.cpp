#include <cstdio>

using namespace std;

// Solutions by google
int fibo[41];


// Initialize fibonacci array with fibonacci values
void fibonacci()
{
    fibo[0] = 1;
    fibo[1] = 1;

    // 1 + 1 = 2, 2 + 1 = 3, 3 + 2 = 5, ...
    for(int i = 2; i < 41; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    fibonacci();

    int vip;
    int ans = 1, cur = 0;

    for(int i = 0; i < m; i++)
    {
        scanf("%d", &vip);
        ans *= fibo[vip-1-cur];
        cur = vip;
    }

    ans *= fibo[n-cur];

    printf("%d", ans);

    return 0;
}
