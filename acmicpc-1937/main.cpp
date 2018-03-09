#include <cstdio>
#include <bits/stdc++.h>

using namespace std;


int n;
int tmp;
int days = 0;
int prevWoodSize;


int dp[501][501];


int maxlivingdays(vector<vector<int>> wood, int startY, int startX) {

    // 현재 위치에 캐싱된 값이 있으면 그 값을 리턴
    if(dp[startY][startX])
        return dp[startY][startX];


    // 대나무 숲의 범위를 벗어나면 그 즉시 일수 리턴
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

    // 현재 위치의 대나무 양
    int woodSize;
    woodSize = wood[startY].at(startX);

    // 여기 return tmp; 때문에 재귀가 작동하지 않음 수정하기
    if(woodSize < prevWoodSize) {
            tmp = days;
            days = 0;
            return tmp;
    }

    days++;

    // 현재 일수를 캐싱한다.
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
