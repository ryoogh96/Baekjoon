#include <cstdio>

using namespace std;

int maxPeople()
{
    int out,in;
    int cur = 0, max = 0;

    for(int i = 0; i < 10; i++)
    {
        scanf("%d %d", &out, &in);
        cur += in - out;
        if(cur > max) max = cur;
    }

    return max;
}

int main()
{
    printf("%d", maxPeople());

    return 0;
}
