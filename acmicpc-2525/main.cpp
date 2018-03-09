#include <cstdio>

using namespace std;

void finishTime()
{
    int a,b,c, timeExprMin, currentHour, currentMin;
    scanf("%d %d", &a, &b);
    scanf("%d", &c);

    // Express finished time as minute
    timeExprMin = a * 60 + b + c;
    currentHour = timeExprMin / 60;
    currentMin  = timeExprMin % 60;

    if(currentHour > 23) currentHour -= 24;

    printf("%d %d", currentHour, currentMin);
}

int main()
{
    finishTime();

    return 0;
}
