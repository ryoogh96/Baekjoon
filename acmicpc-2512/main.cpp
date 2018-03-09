#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;
double m;
double low = 0, _high;
//int mid;
double budget[10001];
int sum = 0;
int avg;
int ans;

bool decision(double mid) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += min(mid,budget[i]);
    }
    if(sum<=m) return true;
    return false;
}

double optimize() {

    double mid = (low + _high) / 2.0;

    if(decision(mid))
        low = mid;
    else
        _high = mid;

    return low;
}


/* 2018/01/09 2nd Try by binary search
int optimize() {

    int ans;

    mid = (_high + low) / 2;

    printf("%d\n", mid);

    if(mid <= m) {
        low++;
        ans = mid;
        optimize();
    }
    else if(mid > m) {
        _high--;
        optimize();
    }

    return ans;

}
*/


/* 2018/01/09 1st Try
int totalBudget;
int budget[10001];
int lessAvg[10001];
int biggerAvg[10001];


int maxint(vector<int> _vecBudget, int num) {
    int ans = 0;
    vector<int>::iterator numLocate;
    int tmp, maxBudget;
    int numLessAvg = 0, numbiggerAvg = 0;
    int sumofBudget = 0;

    for(int i = 0; i < num; i++) {
        ans += budget[i];
    }

    maxBudget = totalBudget;

    if(ans <= totalBudget) {
        numLocate = max_element(_vecBudget.begin(), _vecBudget.end());
        tmp = distance(_vecBudget.begin(), numLocate);
        return _vecBudget.at(tmp);
    }    mid = high / 2;

    sort(budget, budget + num);

    for(int i = 0; i < num; i++) sumofBudget += budget[i];

    for(int i = 0; i < num; i++) {
        if(budget[i] < sumofBudget / num) {
            lessAvg[i] = budget[i];
            numLessAvg++;
        }
        else if(budget[i] > sumofBudget / num) {
            biggerAvg[i] = budget[i];4
120 110 140 150
485
            numbiggerAvg++;
        }

    for(int i = 0; i < numLessAvg; i++) {
        sumofBudget -= lessAvg[i];
    }

    printf("sumofBudget : %d\n", sumofBudget);

    sumofBudget /= numbiggerAvg;

    return sumofBudget;

    /*
    for(int i = 0; i < num - 2; i++) {
        maxBudget -= budget[i];
    }

    printf("%d\n", maxBudget);

    if(maxBudget / (num - 2) < (budget[num-1] + budget[num-2]) / 2)
        return maxBudget / (num - 2);


    for(int i = 0; i < num - 1; i++) {
        numLocate = min_element(_vecBudget.begin(), _vecBudget.end());
        tmp = distance(_vecBudget.begin(), numLocate);
        maxBudget -= _vecBudget.at(tmp);
    }





    }
}
*/


int main()
{

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &budget[i]);
    }
    scanf("%d", &m);

    _high = m;



    for(int i = 0; i < n; i++) sum += budget[i];

    avg = sum / n;

    printf("%d", optimize());

    /* 2018/01/09 1st Try
    vector<int> vecBudget(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &budget[i]);
        vecBudget.push_back(budget[i]);
    }
    scanf("%d", &totalBudget);


    printf("%d", maxint(vecBudget, n));
    */


    return 0;
}
