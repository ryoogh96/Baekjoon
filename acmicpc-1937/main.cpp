#include <cstdio>
#include <bits/stdc++.h>

using namespace std;


int n;
int tmp;
int days = 0;
int prevWoodSize;


int dp[501][501];


int maxlivingdays(vector<vector<int>> wood, int startY, int startX) {

    // ���� ��ġ�� ĳ�̵� ���� ������ �� ���� ����
    if(dp[startY][startX])
        return dp[startY][startX];


    // �볪�� ���� ������ ����� �� ��� �ϼ� ����
    if(startY < 0 || startX < 0) {
            tmp = days;
            days = 0;
            return tmp;
    }
    else if(n <= startY || n <= startX) {
            tmp = days;
            days = 0;
            return tmp;
    }

    // ���� ��ġ�� �볪�� ��
    int woodSize;
    woodSize = wood[startY].at(startX);

    // ���� return tmp; ������ ��Ͱ� �۵����� ���� �����ϱ�
    if(woodSize < prevWoodSize) {
            tmp = days;
            days = 0;
            return tmp;
    }

    days++;

    // ���� �ϼ��� ĳ���Ѵ�.
    dp[startY][startX] = days;


    prevWoodSize = woodSize;

    return maxlivingdays(wood, startY + 1, startX)
            + maxlivingdays(wood, startY - 1, startX)
            + maxlivingdays(wood, startY, startX - 1)
            + maxlivingdays(wood, startY, startX + 1);

}


int main()
{
    scanf("%d", &n);
    vector<vector<int>> wood(n, vector<int>(n, 0));


    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) {
            scanf("%d", &tmp);
            wood[i].at(j) = tmp;
        }




    printf("%d", maxlivingdays(wood,0,0));



    return 0;
}
