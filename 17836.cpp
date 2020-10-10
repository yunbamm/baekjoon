#include<iostream>
#include<queue>

using namespace std;

#define INF 987654321

int arr[101][101][2];		//x,y,z ( 0 검 획득 X )
int map[101][101];			//
int N, M, T;				//성의 크기 , 제한시간
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void BFS() {
	queue<pair<int, pair<int, int>>> q;		//검 , 좌표
	q.push({ 0 , {1,1} });
	arr[1][1][0] = 0;

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int sord = q.front().first;
		int cost = arr[x][y][sord];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//범위를 벗어나면 무시
			if (newx < 1 || newy < 1 || newx > N || newy >M) continue;

			//벽이고 sord가 1일때
			if (map[newx][newy] == 1 && sord == 1) {
				if (arr[newx][newy][sord] > cost + 1) {
					arr[newx][newy][sord] = cost + 1;
					q.push({ sord , {newx,newy} });
				}
			}
			//소드면
			if (map[newx][newy] == 2) {
				if (arr[newx][newy][1] > cost + 1) {
					arr[newx][newy][1] = cost + 1;
					q.push({ 1 , {newx,newy} });
				}
			}
			//빈칸이면
			if (map[newx][newy] == 0) {
				if (arr[newx][newy][sord] > cost + 1) {
					arr[newx][newy][sord] = cost + 1;
					q.push({ sord , {newx,newy} });
				}
			}
		}
	}
}
int main() {
	
	cin >> N >> M >> T;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cin >> map[x][y];
			arr[x][y][0] = INF;
			arr[x][y][1] = INF;
		}
	}
	BFS();

	int min_time = min(arr[N][M][0], arr[N][M][1]);

	if (T < min_time) cout << "Fail\n";
	else cout << min_time << "\n";
}
