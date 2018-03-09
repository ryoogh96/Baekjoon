#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int student[1001][6];
/*
struct cnt
{
    int num;
    //bool noRepeat[1001];
    int order;
};
cnt cot[1001];

bool cmp(const cnt &lhs, const cnt &rhs)
{
    return lhs.num == rhs.num ? lhs.order < rhs.order : lhs.num > rhs.num;
}
*/
int instanceChairMan()
{

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d %d", &student[i][0],&student[i][1],&student[i][2],&student[i][3],&student[i][4]);
        //cot[i].order = i+1;
    }
    int mmax = 0, ans = 0;
    for(int i = 0; i < n; i++)
    {
        set<int> visited;
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < n; k++)
            {
                {
                    if(i == k) continue;

                    // 0,0 1,0 2,0 3,0 4,0 5,0 ...
                    if(student[i][j] == student[k][j])
                        {
                            //cot[i].num++;
                            visited.insert(k); // stl set can't insert same value so
                                               // 한번이라도 같은 반이었던 사람이 가장 많은 학생을 고려하기위해 따로 구현을 하지 않아도 된다.
                        }
                }
            }
        }
        if(mmax < visited.size())
        {
            mmax = visited.size();
            ans = i;
        }

    }

    //printf("\n\n\n");

    //sort(cot, cot+n, cmp);

    //for(int i = 0; i < n; i++)
        //printf("%d ", cot[i].num);

    //
    //printf("\n");

    //return cot[0].order;
    return ans + 1;
}

int main()
{
    printf("%d", instanceChairMan());

    return 0;
}
