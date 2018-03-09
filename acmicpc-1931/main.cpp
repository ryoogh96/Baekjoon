#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;
int start[100002];
int finish[100002];
int selected = 0;

// From Algorithm Problem Solving Textbook p.386
int schedule() {
    vector<pair<int,int> > order;
    for(int i = 0; i < n; ++i)
        order.push_back(make_pair(finish[i], start[i]));

    sort(order.begin(), order.end());

    int earliest = 0, selected = 0;
    for(int i = 0; i < order.size(); ++i) {
        int meetingBegin = order[i].second, meetingEnd = order[i].first;

        if(earliest <= meetingBegin) {
            earliest = meetingEnd;
            ++selected;
        }
    }
    return selected;
}


int main()
{

    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &start[i], &finish[i]);
    }

    printf("%d", schedule());


    return 0;
}
