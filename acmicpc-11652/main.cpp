#include <cstdio>
#include <algorithm>
#include <map>

long long num[1000005];

int main()
{
    int n;
    long long temp = 0;
    long long ans = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        long long tmp;

        scanf("%lld", &tmp);

        num[tmp]++;

    }

    for(long long i = 0; i < n; i++) {

        if(num[i] > temp){
            temp = num[i];
            ans = i;
        }
    }

    printf("%lld", ans);

    return 0;
}
