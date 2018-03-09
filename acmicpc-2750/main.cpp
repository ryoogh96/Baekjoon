#include <bits/stdc++.h>
#include <cstdio>

using namespace std;


void Swap(int *lhs, int *rhs) {
    int tmp = *lhs;
    *lhs = *rhs;
    *rhs = tmp;
}

void BubbleSort(int arr[], int n) {


    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                Swap(&arr[j], &arr[j+1]);
            }
        }
    }

    for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    n = sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr, n);

    return 0;
}
