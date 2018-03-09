#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
/*
struct students
{
    int voted;
    int order;
    int number;
};

bool operator cmp(const students &lhs, const students &rhs)
{
    return lhs.voted != rhs.voted ? lhs.voted < rhs.voted : lhs.order < rhs.order;
}

students student[101];

students candidate[21];
*/

//Solution by Official KOI 2007 Elementary NO.1

struct candidate {int num,vote,time;} cand[100001];

bool cmp(const candidate &lhs, const candidate &rhs)
{
    return lhs.num < rhs.num;
}

void lastChairMan()
{

    int picFrame,totalVote, seat;
    int cnt = 0;
    scanf("%d %d", &picFrame, &totalVote);

    for(int i = 0; i < totalVote; i++)
    {
        int curVote;
        scanf("%d", &curVote);

        // sequential search to find same student number in picFrame
        for(seat = 0; seat < cnt; seat++) if(cand[seat].num == curVote)
        {
                cand[seat].vote++;
                break;
        }

        // search finish but there was same student on picFrame so skip insert new student on picFrame
        if(seat < cnt) continue;

        // current picFrame has seat or not
        // if it has seat picFrame's seat + 1;
        if(cnt < picFrame)
        {
            seat = cnt;
            cnt++;
        }
        else    // if no seat than find lowest vote and order student
        {
            seat = 0;
            for(int k = 1; k < cnt; k++)
            {
                // find lowest vote student, if there are two more same vote students than find lowest order student
                if(cand[k].vote < cand[seat].vote || cand[k].vote == cand[seat].vote && cand[k].time < cand[seat].time)
                    seat = k; // lowest student after compare with two students
            }
        }
        // insert next student on picFrame where lowest student leaved
        cand[seat].num = curVote;
        cand[seat].vote = 1;
        cand[seat].time = i;

    }

    sort(cand, cand + cnt, cmp);

    for(int i = 0; i < cnt; i++)
    {
        printf("%d ", cand[i].num);
    }

    /*
    int n,voteNum,vote;
    int cnt = 0;
    scanf("%d %d", &n, &voteNum);

    for(int i = 0; i < voteNum; i++)
    {
        scanf("%d", &vote);

        // No seats available
        if(n)
        {
            sort(candidate,candidate + cnt,cmp);
            student[candidate[0]].voted = 0;
            student[vote]
            candidate[0] =
        }

        student[vote].voted++;
        student[vote].order = i;
        student[vote].number = vote;
        candidate[cnt++] = student[vote];
        if(n > 0)n--;


        /* no seats available
        if(candidate[2].vote != 0)
        {
            student[candidate[0].number].vote = 0;
            student[i].number = vote;
            student[i].order = i;
            student[i].vote++;
            candidate[0] = student[i];
        }
        else if(candidate[1].vote != 0)
        {
            student[i].number = vote;
            student[i].order = i;
            student[i].vote++;
            candidate[2] = student[i];
        }
        else if(candidate[0].vote != 0)
        {
            student[i].number = vote;
            student[i].order = i;
            student[i].vote++;
            candidate[1] = student[i];
        }
        else if(candidate[0].vote == 0)
        {
            student[i].number = vote;
            student[i].order = i;
            student[i].vote++;
            candidate[0] = student[i];
        }

    }
    */
}

int main()
{
    lastChairMan();

    return 0;
}
