/* Solution by KOI Official
   check out the getSolution part make sure
   you fully understand the process of it
*/

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> weight;

int getSolution(int n)
{
    int ret = 1;
    for(int i = 0; i < n; i++)
    {
        if(ret < weight.at(i)) return ret;
        ret += weight.at(i);
    }
    return ret;
}

int main()
{
    int n, tmp;
    scanf("%d", &n);
    assert(1 <= n && n <= 1000);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        weight.push_back(tmp);
        assert(1 <= weight.at(i) && weight.at(i) <= 1000000);

        sum += weight.at(i);
        assert(sum <= 1000000000);
    }

    sort(weight.begin(), weight.end());

    printf("%d", getSolution(n));

    return 0;
}


/* Failed my Own Solution

#include <cstdio>
#include <vector>

using namespace std;

int unmeasure(int n, vector<int> weight) {

	int temp = 0;
	int min = 1;
	int max = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = weight.at(i) + weight.at(j);
			weight.push_back(temp);
		}
	}

	int size = weight.size();

	for (int i = 0; i < size; i++) {
		if (weight.at(i) < min) min = weight.at(i);

		if (weight.at(i) > max) max = weight.at(i);
	}

	for (int i = min; i < max; i++)
		ans.push_back(i);


	for (int i = 0; i < size; i++)
		for (int j = 0; j < ans.size(); j++) {
			if (ans.at(j) == weight.at(i)) ans.erase(ans.begin() + j);
		}



	return ans.at(0);

}



int main()
{
	int n;
	int weights;
	scanf("%d", &n);
	vector<int> weight;

	for (int i = 0; i < n; i++) {
		scanf("%d", &weights);
		weight.push_back(weights);
	}

	printf("%d", unmeasure(n, weight));


	return 0;
}
*/
