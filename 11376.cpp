#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DFS 이분매칭

//check가 무조건 필요!!!안그러면 무한루프
//현재 DFS단계에서 한번 check해본 일이라면 또 check할 필요가 없다

int N, M;		//직원 수, 일 개수
vector<int> v[1001];	//할수있는 일
int person[1001] = { 0 };		//일 맡은 사람 번호
int num[1001] = { 0 };		//맡은 일의 개수
bool check[1001];

bool process(int now) {

	//할수있는일 탐색
	for (int i = 0; i < v[now].size(); i++) {
		int work = v[now][i];
		
        //check된거는 무시 : 만약 맡은사람이 있어서 그사람으로 DFS하면 그 일은 무시되야되니까
		if (check[work]) continue;

		check[work] = true;
        
		//아직 맡은 사람이 없으면
		if (person[work] == 0) {
			person[work] = now;
			num[now]++;
			//두가지일을 다 맡았으면 return
			if (num[now] == 2) return true;
		}
		//내가 아닌 다른 맡은사람이 있으면
		else if (person[work] != now) {
			//원래 하던사람이 다른일을 할수있는지 다시 본다
			num[person[work]]--;
			//다른일이 가능하다면 이 일은 양보해준다
			if (process(person[work])) {
				person[work] = now;
				num[now]++;
				//두가지일을 다 맡았으면 return
				if (num[now] == 2) return true;
			}
			//불가능하면 num복구
			else {
				num[person[work]]++;
			}
		}

	}
	return false;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int amount, tmp;
	for (int i = 1; i <= N; i++) {
		cin >> amount;
		for (int j = 0; j < amount; j++) {
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}

	//매칭
	for (int i = 1; i <= N; i++) {

		//check초기화
		for (int m = 1; m <= M; m++) {
			check[m] = false;
		}
		process(i);
	}
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		if (person[i]) {
			answer++;
			//cout << i << " , " << person[i] << "\n";
		}
	}
	cout << answer;
}
