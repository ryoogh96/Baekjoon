#include <cstdio>

int time = 0;

int fastestTime(int src, int dest)
{
    if(src == dest)
        return time;

    time++;

    fastestTime(src+1,dest);
    fastestTime(src-1,dest);
    fastestTime(2*src,dest);
}


int main()
{
    int src,dest;
    scanf("%d %d", &src, &dest);

    printf("%d", fastestTime(src, dest));

    return 0;
}
