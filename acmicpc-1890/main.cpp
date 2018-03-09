#include <cstdio>

int n, board[101][101];
long long cache[101][101];

long long jump3(int y, int x) {

    //printf("%d %d\n", y, x);
    if(y >= n || x >= n) //{printf("false\n"); return false;}
            return 0;
    if(y == n-1 && x == n-1) //{printf("true\n"); return true;}
            return 1;


    long long& ret = cache[y][x];

    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    if(board[y][x] == 0) return 0;


    return ret = (jump3(y + jumpSize, x) + jump3(y, x + jumpSize));
}


/* Solved by Dynamic Programming
int jump2(int y, int x) {

    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;

    int& ret = cache[y][x];

    if(ret != -1) return ret;
    int jumpSize = board[y][x];

    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}
*/

/* Solved by Exhaustive search

bool jump(int y, int x) {

    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;

    int jumpSize = board[y][x];

    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}
*/


int main()
{

    for(int i = 0; i < 101; i++) {

        for(int j = 0; j < 101; j++) {
            cache[i][j] = -1;

        }
    }

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);

        }
    }





    printf("%lld\n", jump3(0,0));

    return 0;
}
