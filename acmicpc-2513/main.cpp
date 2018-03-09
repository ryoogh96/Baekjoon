#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,k,s;
int cov;
vector< pair<int,int> > v;
int main(){
    scanf("%d%d%d",&n,&k,&s);
    for(int i=0;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v.push_back( make_pair(x,y));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i){
        if(v[i].first<s)++cov;
    }
    int ans = 0;
    int food = 0;
    int pos = 0;
    for(int i=0;i<cov;++i){
        if(k-food>=v[i].second){
            food += v[i].second;
            v[i].second = 0;
        }else{
            v[i].second = v[i].second - (k-food);
            ans += abs(s-v[pos].first)*2;
            pos = i;
            food = 0;
            --i;
        }
        if(i==cov-1)ans += abs(s-v[pos].first)*2;
    }

    pos = n-1;
    food=0;
    for(int i=n-1;i>=cov;--i){
        if(k-food>=v[i].second){
            food += v[i].second;
            v[i].second=0;
        }else{
            v[i].second = v[i].second - (k-food);
            ans += abs(s-v[pos].first)*2;
            pos = i;
            food = 0;
            ++i;
        }
        if(i==cov)ans += abs(s-v[pos].first)*2;
    }

    printf("%d",ans);
}

/* My Own Solution Failed
map<int, int> student;


int findMax(int a, int b)
{
    if(a < b) return b;
    else if(a > b) return a;
}

int minimumMove(int n, int k, int s) {

	int house, tmpstu;
	int prevHouse = 0, prevTmpStu = 0;
	int movedDistance = 0;
	int limit = 0;
	int curDistance = k;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &house, &tmpstu);
		prevHouse = findMax(prevHouse, house);
		prevTmpStu = findMax(prevTmpStu, tmpstu);
		student.insert(pair<int, int>(house, tmpstu));
	}


	// 스쿨버스가 자기보다 작은 좌표를 움직인다.
	for (int i = s - 1; i >= 0; i--) {


		// 학생들을 스쿨 버스에 태운다.
		while(student[i] > 0 && limit < k) {
			movedDistance += curDistance - i;
			curDistance = i;
			limit += k;
			student[i] -= k;
		}

		// 인원이 꽉차면 돌아간다.
		if (limit >= k) {
			movedDistance += s - i;
			curDistance = s;
			limit = 0;
		}

		// 끝 좌표 도달하면 돌아간다.
		if (i == 0 && curDistance != s)
			movedDistance += k;
	}

	limit = 0;
	curDistance = k;

	// 스쿨버스가 자기보다 큰 좌표를 움직인다.
	for (int i = s + 1; i <= prevHouse; i++) {

		// 학생들을 스쿨 버스에 태운다.
		while(student[i] > 0 && limit < k) {
			movedDistance += i - curDistance;
			curDistance = i;
			limit += k;
			student[i] -= k;
		}

		// 인원이 꽉차면 돌아간다.
		if (limit >= k) {
			movedDistance += i - s;
			curDistance = s;
			limit = 0;
		}

		// 끝 좌표 도달하면 돌아간다
		if (i == house && curDistance != s)
			movedDistance += i - s;
	}
	return movedDistance;
}

int main()
{
	int apartment, schoolBus, school;
	scanf("%d %d %d", &apartment, &schoolBus, &school);

	printf("%d", minimumMove(apartment, schoolBus, school));


	return 0;
}
*/
