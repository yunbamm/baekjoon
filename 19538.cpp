#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//위상정렬?

int N , M;
pair<int, int> degree[200001];		//주변인 , 루머주변인
int answer[200001];
vector<vector<int>> v(200001);		//주변인 관계

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	//answer초기화
	for (int n = 1; n <= N; n++) answer[n] = -1;

	//입력
	int tmp;
	for (int i = 1; i <= N; i++) {
		while (1) {
			cin >> tmp;
			if (tmp == 0) break;
			degree[i].first++;
			v[i].push_back(tmp);
		}
	}
	

	cin >> M;

	//최초 루머유포자
	queue<int> q;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		q.push(tmp);
		answer[tmp] = 0;
	}

	while (!q.empty()) {
		int  now = q.front();
		q.pop();

		//주변인들 확인
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			//만약 answer이 정해지지 않았고 주변인중에 루머주변인이 절반 이상이면
			if (answer[next] == -1) {
				degree[next].second++;
				if (degree[next].first <= 2 * degree[next].second) {
					q.push({ next });
					answer[next] = answer[now] + 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}
}
