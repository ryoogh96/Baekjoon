#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

//int num[1000001];

const int MAX_INT = 2147483647;

struct RMQ {
    // 배열의 길이
    int n;
    // 각 구간의 최소치
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n-1, 1);
    }
    // node 노드가 array[left,right]배열을 표현할 때
    // node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환하다.
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return MAX_INT;

        if(left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];

        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid),
                   query(left, right, node*2+1, mid+1, nodeRight));
        }
            int query(int left, int right) {
                return query(left, right, 1, 0, n-1);
            }


    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index)
            return rangeMin[node];

        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node*2, nodeLeft, mid),
                                    update(index, newValue, node*2+1, mid+1, nodeRight));
        }

        int update(int index, int newValue) {
            return update(index, newValue, 1, 0, n-1);
        }

};

int main() {
    int n,m,k,a,b,c, temp;
    long long ans = 0;
    vector<int> segtree;
    scanf("%d %d %d", &n, &m, &k);


    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        segtree.push_back(temp);
    }

    RMQ rmq(segtree);

    for(int i = 0; i < m+k; i++) {
        scanf("%d", &a);
        if(a == 1) {
            scanf("%d %d", &b, &c);
            rmq.update(b, c);
        }
        else if(a == 2) {
            scanf("%d %d", &b, &c);
            printf("%d\n", rmq.query(b,c));

        }
    }


}

/* Only array timeout
int main()
{
    int n,m,k,a,b,c;
    long long ans = 0;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; i++)
        scanf("%d", &num[i]);

    for(int i = 0; i < m+k; i++) {
        scanf("%d", &a);
        if(a == 1) {
            scanf("%d %d", &b, &c);
            num[b] = c;
        }

        if(a == 2) {
            scanf("%d %d", &b, &c);
            for(; b <= c; b++) {
                ans += num[b];
            }
            printf("%lld\n", ans);
            ans = 0;
        }
    }



}
*/
