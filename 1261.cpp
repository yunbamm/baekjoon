#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define INF 987654321

int M, N;		//가로크기 , 세로크기
char arr[101][101];
int cost[101][101];
pair<int, int>p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void BFS() {
	queue<pair<int, pair<int, int>>> q;		//제거한 벽수 , 좌표
	q.push({ 0,{1,1} });
	cost[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int c = q.front().first;
		q.pop();

		//현재 찾은거보다 더 많이 부셔야되면 무시
		if (cost[x][y] < c) continue;

		//4방향 이동
		for (int i = 0; i < 4; i++) {
			int nx = x + p[i].first;
			int ny = y + p[i].second;

			//범위를 벗어나면 무시
			if (nx<1 || ny<1 || nx>N || ny>M) continue;

			//벽이면
			if (arr[nx][ny] == '1') {
				if (cost[nx][ny] > c + 1) {
					cost[nx][ny] = c + 1;
					q.push({ c + 1,{nx,ny} });
				}
			}
			//빈칸이면
			else {
				if (cost[nx][ny] > c) {
					cost[nx][ny] = c;
					q.push({ c,{nx,ny} });
				}
			}
		}
	}
}
int main() {
	cin >> M >> N;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cin >> arr[x][y];
			cost[x][y] = INF;
		}
	}
	BFS();

	cout << cost[N][M] << "\n";

}
