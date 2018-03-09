#include <cstdio>

using namespace std;

int people[1005];
int maxPrize;

int gamePrize()
{
    int a,b,c;
    int prize;
    scanf("%d %d %d", &a, &b, &c);

    if(a == b && a == c && b == a)
        return 10000 + a * 1000;
    else if(a == b || a == c) return 1000 + a * 100;
    else if(b == c) return 1000 + b * 100;
    else if(a > b && a > c) return a * 100;
    else if(b > a && b > c) return b * 100;
    else if(c > a && c > b) return c * 100;

}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        people[i] = gamePrize();
        if(people[i] > maxPrize) maxPrize = people[i];
    }

    printf("%d", maxPrize);


    return 0;
}
