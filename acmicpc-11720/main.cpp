#include <stdio.h>


// get the whole number by char and get the integer value by -'0' from char
int main() {

    int n;
    int ans = 0;

    scanf("%d", &n);

    char numstr[n];

    scanf("%s", numstr);

    for(int i = 0; i < n; i++) {
        ans += numstr[i] - '0';
    }

    printf("%d", ans);

}

// http://romanceboong.tistory.com/entry/백준-11720번-문제-숫자의-합 [낭만붕어빵의 바다]




/* 10이상의 숫자를 정확히 구별하지 못함
int main()
{
    int idx = 1;
    int n;
    int ans = 0;
    int num;

    scanf("%d", &n);

    scanf("%d", &num);

    for(int temp = n; temp > 1; temp--) idx *= 10;

    for(n; n > 0; n--) {
        ans += num / idx; //printf("%d 번째 for문 ans : %d num : %d idx : %d\n", n, ans, num, idx);
        num %= idx;
        idx /= 10;
    }

    printf("%d", ans);


    return 0;
}
*/
