#include <cstdio>

using namespace std;

struct score
{
    int total;
    int score1;
    int score2;
    int score3;
};

int highest;
score fst,sec,thd;

void addScores(int one, int two, int three)
{
    if(one == 3)
    {
        fst.score3++;
        fst.total += one;
    }
    else if(one == 2)
    {
        fst.score2++;
        fst.total += one;
    }
    else if(one == 1)
    {
        fst.score1++;
        fst.total += one;
    }

    if(two == 3)
    {
        sec.score3++;
        sec.total += two;
    }
    else if(two == 2)
    {
        sec.score2++;
        sec.total += two;
    }
    else if(two == 1)
    {
        sec.score1++;
        sec.total += two;
    }

    if(three == 3)
    {
        thd.score3++;
        thd.total += three;
    }
    else if(three == 2)
    {
        thd.score2++;
        thd.total += three;
    }
    else if(three == 1)
    {
        thd.score1++;
        thd.total += three;
    }



}

void setChairMan()
{
    int n, temp1, temp2, temp3;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &temp1, &temp2, &temp3);
        addScores(temp1, temp2, temp3);
    }


    highest = fst.total;
    if(sec.total > highest)
        highest = sec.total;
    else if(thd.total > highest)
        highest = thd.total;


    if(fst.total > sec.total && fst.total > thd.total && fst.score3 != sec.score3 && fst.score2 != thd.score2)
        printf("1 %d", fst.total);
    else if(sec.total > fst.total && sec.total > thd.total && sec.score3 != fst.score3 && sec.score3 != thd.score3)
        printf("2 %d", sec.total);
    else if(thd.total > fst.total && thd.total > sec.total && thd.score3 != fst.score3 && thd.score3 != sec.score3)
        printf("3 %d", thd.total);
    else if(fst.score3 > sec.score3 && fst.score3 > thd.score3)
        printf("1 %d", fst.total);
    else if(sec.score3 > fst.score3 && sec.score3 > thd.score3)
        printf("2 %d", sec.total);
    else if(thd.score3 > fst.score3 && thd.score3 > sec.score3)
        printf("3 %d", thd.total);
    else if(fst.score2 > sec.score2 && fst.score2 > thd.score2)
        printf("1 %d", fst.total);
    else if(sec.score2 > fst.score2 && sec.score2 > thd.score2)
        printf("2 %d", sec.total);
    else if(thd.score2 > fst.score2 && thd.score2 > sec.score2 && thd.total >= fst.total && thd.total >= sec.total)
        printf("3 %d", thd.total);
    else printf("0 %d", highest);



    //printf("%d %d %d", fst.score1, sec.score1, thd.score1);

}

int main()
{
    setChairMan();
    return 0;
}
