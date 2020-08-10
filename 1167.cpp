#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//임의의 점에서 가장 멀리있는 정점이 지름을 이루는 2정점중 하나이다

int V;		//정점개수
vector < vector<pair<int, int>>> v(100001);		//연결된 정점 , 거리

//1번에 대해서 거리
int tmp_dis[100001] = { 0 };

int answer[100001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> V;

	int par, chi, dis;
	for (int i = 1; i <= V; i++) {
		cin >> par;
		while (1) {
			cin >> chi;
			if (chi == -1) break;
			cin >> dis;
			v[par].push_back({ chi,dis });
		}
	}

	queue<pair<int, int>> q;		//정점번호 , 거리
	q.push({ 1,0 });
	tmp_dis[1] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int sum = q.front().second;
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int tmp = v[now][i].second;

			if (next != 1 && tmp_dis[next] == 0) {
				tmp_dis[next] = tmp + sum;
				q.push({ next , tmp + sum });
			}

		}
	}

	int tmp_max = 0;
	int tmp_index = 0;

	for (int i = 1; i <= V; i++) {
		if (tmp_max < tmp_dis[i]) {
			tmp_max = tmp_dis[i];
			tmp_index = i;
		}
	}

	//tmp_index에서 가장 먼 거리를 찾으면 그게 지름
	q.push({ tmp_index,0 });
	answer[tmp_index] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int sum = q.front().second;
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int tmp = v[now][i].second;

			if (next != tmp_index && answer[next] == 0) {
				answer[next] = tmp + sum;
				q.push({ next , tmp + sum });
			}

		}
	}

	int real_answer = 0;
	for (int i = 1; i <= V; i++) {
		real_answer = max(real_answer, answer[i]);
	}

	cout << real_answer;
}
