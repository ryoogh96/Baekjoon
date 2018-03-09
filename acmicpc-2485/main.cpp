#include <cstdio>

using namespace std;

int tree[100005];

int main()
{
    int n, tmp, diff;
    int cnt = 0;
    int i = 0, j = 1;
    scanf("%d", &n);


    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }

    tmp = tree[0];
    diff = 2;

    while(tmp != tree[n-1])
    {
        tmp += diff;

        if(tmp != tree[j]) cnt++;
        else if(tmp == tree[j]) j++;
    }

    printf("%d", cnt);

    return 0;
}
