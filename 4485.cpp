#include<iostream>
#include<queue>

using namespace std;

#define INF 987654321;

//(0,0) -> (N-1,N-1)
int N;
int arr[125][125];
int cost[125][125];
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void BFS() {
	queue<pair<int, pair<int, int>>> q;		//cost, 좌표 
	q.push({ arr[0][0] , {0,0} });			//(0,0)시작
	cost[0][0] = arr[0][0];

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int c = q.front().first;
		q.pop();

		//만약 현재 좌표에 더 큰값으로 도착한다면 무시
		if (c > cost[x][y]) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + p[i].first;
			int ny = y + p[i].second;

			//범위를 벗어나면 무시
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;

			//더 적게 가는경로를 찾으면
			if (cost[nx][ny] > c + arr[nx][ny]) {
				cost[nx][ny] = c + arr[nx][ny];
				q.push({ c + arr[nx][ny] , {nx,ny} });
			}
		}
	}
}
int main() {
	int tmp = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> arr[x][y];
				cost[x][y] = INF;
			}
		}
		BFS();

		cout << "Problem "<<tmp<<": "<< cost[N - 1][N - 1] << "\n";
		tmp++;
	}
}
