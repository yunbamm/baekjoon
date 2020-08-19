#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N, M;		//헛간개수 , 길 개수
int dis[20001];
vector<vector<int>> v(20001);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//dis -1로 초기화 
	for (int n = 1; n <= N; n++) dis[n] = -1;

	int src, dest;
	for (int m = 0; m < M; m++) {
		cin >> src >> dest;
		v[src].push_back(dest);
		v[dest].push_back(src);
	}


	//1번부터 시작
	queue<int> q;
	q.push(1);
	dis[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (dis[next] != -1) continue;

			dis[next] = dis[now] + 1;
			q.push(next);
		}
	}

	int max_distance = -1;
	for (int i = 1; i <= N; i++) {
		max_distance = max(max_distance, dis[i]);
	}
	int index = -1;
	for (int i = 1; i <= N; i++) {
		if (dis[i] == max_distance) {
			index = i;
			break;
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (dis[i] == max_distance) count++;
	}
	

	cout << index << " " << max_distance << " " << count;
}
