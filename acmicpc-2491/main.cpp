#include <cstdio>
#include <algorithm>

using namespace std;

int num[100001];

// Solution by http://blog.naver.com/PostView.nhn?blogId=korin57&logNo=220718061216&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
int main()
{
    int n;
    int cnt = 0;
    int bMax = 0;
    int sMax = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }


    for(int j = 0; j < n-1; j++)
    {
        if(num[j] >= num[j+1]) cnt++;
        else cnt = 0;

        if(cnt > bMax) bMax = cnt;
    }

    cnt = 0;

    for(int k = 0; k < n-1; k++)
    {
        if(num[k] <= num[k+1]) cnt++;
        else cnt = 0;

        if(cnt > sMax) sMax = cnt;
    }



    printf("%d", 1+max(bMax,sMax));

    return 0;
}
