#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//지름길들 sort후 DP?

int N, D;	//지름길 개수 , 고속도로 길이
int answer[10001];		//걸리는 시간
vector<pair<pair<int, int>, int>> v;		//시작 , 끝 ,길이

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//ansewr초기화
	for (int i = 0; i <= 10000; i++) answer[i] = i;
	
	//입력
	cin >> N >> D;

	int s, e, w;
	for (int i = 0; i < N; i++) {
		cin >> s >> e >> w;
		v.push_back({ {s,e},w });
	}

	//정렬
	sort(v.begin(), v.end());

	//지름길을 보면서 answer update

	for (int i = 0; i < v.size(); i++) {
		int start = v[i].first.first;
		int end = v[i].first.second;
		int weight = v[i].second;

		//만약 어떤 위치에 가는 최솟값이 update되었으면 그 구간 뒤로 다 update
		if (answer[end] > answer[start] + weight) {
			answer[end] = answer[start] + weight;

			for (int j = end; j <= 10000; j++) {
				answer[j] = min(answer[j], answer[end] + (j - end));
			}

		}
	}

	cout << answer[D];
}




