#include <cstdio>
#include <vector>

using namespace std;


int n;
int cache[1001], A[1001], choices[1001];


int lis(int start) {
    int& ret = cache[start+1];
    if(ret != -1) return ret;

    ret = 1;
    int bestNext = -1;
    for(int next = start+1; next < n; ++next)
        if(start == -1 || A[start] < A[next]) {
            int cand = lis(next) + 1;
            if(cand > ret) {
                ret = cand;
                bestNext = next;
            }
        }
        choices[start+1] = bestNext;
        return ret;
}

void reconstruct(int start, vector<int>& seq) {
    if(start != -1) seq.push_back(A[start]);
    int next = choices[start+1];
    if(next != -1) reconstruct(next, seq);
}


int main()
{
    int temp;

    for(int i = 0; i < 1001; i++) {
            cache[i] = -1;
    }

    scanf("%d", &n);

    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    temp = lis(0);
    printf("%d\n", temp);

    reconstruct(0,a);



    for(vector<int>::size_type i = n; i < a.size(); ++i) {
        printf("%d ", a[i]);
    }


    return 0;
}
