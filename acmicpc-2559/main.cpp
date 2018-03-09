#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/* Solution by KOI 2011 Official */

int n,k;


int getMaxSum()
{
    int tmp = 0;
    int sum = 0;
    int max_sum = -999999999;
    vector<int> data;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        data.push_back(tmp);

        if(data.at(i) > 100 || data.at(i) < -100)
            return -1;
        sum += data.at(i);

        if(i >= k-1)
        {
            if(sum > max_sum) max_sum = sum;
            sum -= data.at(i-k+1);
        }
    }

    return max_sum;


}

int main()
{
    scanf("%d %d", &n, &k);

    if(!k) return 0;


    printf("%d", getMaxSum());


}



/* Time Complexity O(kN) which only gets subset scores so BOJ judge this wrong as 시간 초과
int main() {

	int n, k;
	int ans = -110;
	int sum = 0;
	int i = 0, j = 0;
	int count;
	int tmp;
	vector<int> temp;
	scanf("%d %d", &n, &k);



	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		temp.push_back(tmp);
	}

	count = k - 1;

	while (count != n) {
		for (; j < k; j++) {
			sum += temp.at(j);
		}

        if(sum > ans) ans = sum;
        sum = 0;
		i++;
		j = i;
		k++;
		count++;
	}


	printf("%d", ans);

}
*/
