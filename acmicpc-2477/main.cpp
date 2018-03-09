#include <cstdio>
#include <cmath>
using namespace std;

struct block
{
    int direct;
    int length;
};

int numMelon()
{
    int k,a,b,c,d,e,f, absval1,absval2;
    bool val1 = false, val2 = false;
    block Block[6];
    scanf("%d", &k);
    scanf("%d %d", &Block[0].direct, &Block[0].length);
    scanf("%d %d", &Block[1].direct, &Block[1].length);
    scanf("%d %d", &Block[2].direct, &Block[2].length);
    scanf("%d %d", &Block[3].direct, &Block[3].length);
    scanf("%d %d", &Block[4].direct, &Block[4].length);
    scanf("%d %d", &Block[5].direct, &Block[5].length);

    for(int i = 0; i < 6; i++)
    {
        for(int j = i+1; j < 6; j++)
        {
            if(((Block[i].direct == 1 && Block[j].direct == 3) || (Block[i].direct == 4 && Block[j].direct == 1) || (Block[i].direct == 2 && Block[j].direct == 4) ||
               (Block[i].direct == 3 && Block[j].direct == 2)) && val1 == false)
               {
                   absval1 = Block[i].length * Block[j].length;
                   val1 = true;
                   printf("%d %d %d %d\n", Block[i].length, Block[j].length, Block[i].direct, Block[j].direct);
               }


            if(((Block[i].direct == 4 && Block[j].direct == 2) || (Block[i].direct == 2 && Block[j].direct == 3) || (Block[i].direct == 3 && Block[j].direct == 1) ||
                (Block[i].direct == 1 && Block[j].direct == 4)) && val2 == false)
                {
                    absval2 = Block[i].length * Block[j].length;
                    val2 = true;
                    printf("%d %d %d %d\n", Block[i].length, Block[j].length, Block[i].direct, Block[j].direct);
                }
        }
    }

    printf("%d %d\n", absval1, absval2);

    return k * abs(abs(absval1) - abs(absval2));

    /*
    if(a == 4 && b == 2) return k * (block[0] * block[1] - block[4] * (block[1] - block[5]));
    else if(a == 4 && b == 1) return k * (block[3] * block[4] - block[0] * block[1]);
    else if(a == 2 && b == 3) return k * (block[0] * block[5] - block[2] * block[3]);
    else if(a == 3 && b == 2) return k * (block[1] * block[2] - block[4] * block[5]);
    */
}

int main()
{
    printf("%d", numMelon());

    return 0;
}
