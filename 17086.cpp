#include<iostream>
#include<queue>
#include<vector>

using namespace std;

#define INF 987654321

int N, M;
int arr[50][50];
int cost[50][50];
vector<pair<int, int>> v;
pair<int, int>p[8] = { {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,-1},{1,1},{-1,1} };

void BFS(int x ,int y) {
	queue<pair<int, pair<int, int>>> q;		//cost, x , y
	q.push({ 0,{x,y} });
	cost[x][y] = 0;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int c = q.front().first;
		q.pop();
		
		//cost가 크면 무시
		if (c > cost[x][y]) continue;

		for (int i = 0; i < 8; i++) {
			int nx = x + p[i].first;
			int ny = y + p[i].second;

			//좌표 범위면 무시
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (cost[nx][ny] > c + 1) {
				cost[nx][ny] = c + 1;
				q.push({ c + 1,{nx,ny} });
			}
		}
	}
}
int main() {
	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> arr[x][y];
			//빈칸
			if (arr[x][y] == 0) {
				cost[x][y] = INF;
			}
			//아기상어
			else {
				v.push_back({ x,y });
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		BFS(x, y);

	}

	int answer = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			answer = max(answer, cost[x][y]);
		}
	}

	cout << answer;
}
