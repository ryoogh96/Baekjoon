#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// Solution by Official KOI ans book
// 십진 n+6 나머지 10 십이진 n+8 나머지 12
// This is same as http://codersbrunch.blogspot.kr/2016/08/7572.html
int main()
{
    int n;
    scanf("%d", &n);

    printf("%c%d", (n+8) % 12 + 'A', (n+6) % 10);

    return 0;
}
