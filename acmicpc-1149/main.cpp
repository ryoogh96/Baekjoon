#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

struct house {
    int red, green, blue;
    bool isRed = false;
    bool isGreen = false;
    bool isBlue = false;
};

struct house h[1001];

int minCost()
{
    int n;
    int cost = 0;
    scanf("%d", &n);

    //bool isRed = false;
    //bool isGreen = false;
    //bool isBlue = false;

    for(int i = 0; i < n; i++) {

        scanf("%d %d %d", &h[i].red, &h[i].green, &h[i].blue);

        if(i > 0)
        {
            if(h[i-1].isRed == false /* && h[i-1].isGreen == false && h[i-1].isBlue == false */ &&  h[i].red < h[i].green && h[i].red < h[i].blue)
            {
                cost += h[i].red;
                h[i].isRed = true;
            }
            else if(h[i-1].isGreen == false /* && h[i-1].isGreen == false && h[i-1].isBlue == false */ && h[i].green < h[i].blue)
            {
                cost += h[i].green;
                h[i].isGreen = true;
            }
            else if(h[i-1].isBlue == false /* && h[i-1].isGreen == false && h[i-1].isBlue == false */)
            {
                cost += h[i].blue;
                h[i].isBlue = true;
            }
        }
        else if(i == 0)
        {
            if(h[i].red < h[i].green && h[i].red < h[i].blue)
            {
                cost += h[i].red;
                h[i].isRed = true;
            }
            else if(h[i].green < h[i].red && h[i].green < h[i].blue)
            {
                cost += h[i].green;
                h[i].isGreen = true;
            }
            else if(h[i].blue < h[i].red && h[i].blue < h[i].green)
            {
                cost += h[i].blue;
                h[i].blue = true;
            }
        }
    }


    return cost;
}

int main()
{

    printf("%d", minCost());





    return 0;
}
