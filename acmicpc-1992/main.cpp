#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;
int vision[65][65];



void decompress(int y, int x, int _size) {
    bool flag = true;

    if(vision[x][y] == 0) {
        for(int i = 0; i < _size; i++) {
            for(int j = 0; j < _size; j++) {
                if(vision[i][j] != 0)
                    flag = false;
            }
        }
        if(flag == true)
            printf("0");
    }
    else if(vision[x][y] == 1) {
        for(int i = 0; i < _size; i++) {
            for(int j = 0; j < _size; j++) {
                if(vision[i][j] != 1)
                    flag = false;
            }
        }
        if(flag == true)
            printf("1");
    }




    if(flag == false) {
        printf("(");
        int half = _size/2;
        decompress(y, x, half);
        decompress(y, x+half, half);
        decompress(y+half, x, half);
        decompress(y+half, x+half, half);
        printf(")");
    }
}


int main()
{

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d",&vision[i][j]);
        }
    }

    decompress(0,0,n);


    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d",vision[i][j]);
        }
        printf("\n");
    }
    */


    return 0;
}
