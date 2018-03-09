#include <bits/stdc++.h>
// 도저히 못풀겠어서 구글링해서 풀었습니니다. https://fatc.club/2017/03/01/992

using namespace std;
/*
class Medal {
public:
    int Gold[1005], Silver[1005], Bronze[1005];
};

Medal *medal;
*/

typedef struct Medal
{
    int Nation;
    int Gold;
    int Silver;
    int Bronze;
} Medal;

   int N, K;

// 그대로 가져온 코드입니다. 지금 봐서는 이해가 잘 안가네요 2017/11/24 오후 08:09
bool comp(Medal lfs, Medal rfs){
    if(lfs.Gold!=rfs.Gold)
        return lfs.Gold>rfs.Gold;
    else if(lfs.Silver!=rfs.Silver)
        return lfs.Silver>rfs.Silver;
    else if(lfs.Bronze!=rfs.Bronze)
        return lfs.Bronze>rfs.Bronze;
    else{
        return lfs.Nation==K;
    }
}

   vector<Medal> v;

int main()
{
    Medal medal;

    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &medal.Nation, &medal.Gold, &medal.Silver, &medal.Bronze);
        v.push_back(medal); // struct채로 vector에 넣을 수 있구나
    }

    sort(v.begin(),v.end(),comp);
    for (int i = 0; i < N; i++) {
        if (v[i].Nation==K) { // 이게 정렬된 등수와 찾는 국가 번호 가 같다는걸 나타내는거같은데 왜 같아지는지 이해가 안갑니다.
            printf("%d", i+1);
            return 0;
        }
    }



    /* 밑에부터 다 실패한 코드들입니다. 백터최대값나오면서 오류떠서 그냥 생각하기를 포기했습니다 OTL
    map<int, float> result;
    vector<float> Result;

    int N,K;
    cin >> N >> K;
    Result.reserve(N);

    for (int i = 0; i < N; i++) {
        int Num, Gold , Silver, Bronze;
        cin >> Num >> Gold >> Silver >> Bronze;
        float Total = Gold + (Silver * 0.001) + (Bronze * 0.00001);
        result.insert(pair<int, float> (Num, Total));
        Result.push_back(Total);
    }




    sort(Result.begin(), Result.end());

    int temp = N;
    int Count = 0;
    N -= 1;

    for (int i = 0; i < N; i++) {
    cout << result[i] << endl;
    }
    cout << 1 * 0.00001 << endl;

    /*
    for (int i = 0; i < temp; temp++) {
        for (int j = 0; j < temp; temp++) {
            if(result[i] == Result.at(N)) {
            Count++;
                if(result[i] == Result.at(N) && i + 1 == K)
                cout << Count << endl;
            }
            N--;
        }

    }

    */
    /*
    int N,K, Total;
    int result[1005];
    vector<int> Result[1005];
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        int Num;
        cin >> Num >> medal->Gold[i] >> medal->Silver[i] >> medal->Bronze[i];
        Total = medal->Gold[i] + (medal->Silver[i] * 0.001) +(medal->Bronze[i] * 0.00001);
        result[Num] = Total;
        Result[Num] = Total;
    }



    sort(Result.begin(), Result.end());

    vector<int> GoldMedal;
    vector<int> SilverMedal;
    vector<int> BronzeMedal;
    GoldMedal.reserve(N),  SilverMedal.reserve(N),  BronzeMedal.reserve(N);


    for (int i = 0; i < N; i++) {
    GoldMedal.push_back(medal->Gold[i]);
    SilverMedal.push_back(medal->Silver[i]);
    BronzeMedal.push_back(medal->Bronze[i]);

    }


    sort(GoldMedal.begin(), GoldMedal.end());
    sort(SilverMedal.begin(), SilverMedal.end());
    sort(BronzeMedal.begin(), BronzeMedal.end());
    */

    return 0;
}
