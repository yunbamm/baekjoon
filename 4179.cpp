#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

//!!!!!!!!!!!!!!!!!!불이 하나라는 가정이 없다
#define INF 987654321

int jihoon[1000][1000];
int fire[1000][1000];

int R, C;
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };
int jihoonx, jihoony;

void BFS_fire() {
	queue<pair<int, int>> q;

	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			if (fire[x][y] == 0) {
				q.push({ x,y });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//유효한좌표
			if (0 <= newx && newx < R && 0 <= newy && newy < C) {

				//퍼질수있는곳이고 아직 퍼지기전
				if (fire[newx][newy] == INF) {
					fire[newx][newy] = fire[x][y] + 1;
					q.push({ newx,newy });
				}
			}
		}
	}
}
void BFS_jihoon() {
	queue<pair<int, int>> q;
	q.push({ jihoonx,jihoony });


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//유효한좌표
			if (0 <= newx && newx < R && 0 <= newy && newy < C) {

				//갈수있고 아직 불이안퍼졌다면???
				if (jihoon[newx][newy] == INF && jihoon[x][y] + 1 < fire[newx][newy]) {
					jihoon[newx][newy] = jihoon[x][y] + 1;
					q.push({ newx,newy });
				}
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> R >> C;

	char c;
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cin >> c;

			//벽
			if (c == '#') {
				jihoon[x][y] = -1;
				fire[x][y] = -1;
			}
			if (c == 'J') {
				jihoon[x][y] = 0;
				fire[x][y] = INF;
				jihoonx = x;
				jihoony = y;
			}
			if (c == 'F') {
				fire[x][y] = 0;
				jihoon[x][y] = INF;
			}
			if (c == '.') {
				jihoon[x][y] = INF;
				fire[x][y] = INF;
			}

		}
	}

	BFS_fire();		//불먼저 퍼짐
	BFS_jihoon();

	/*for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cout << fire[x][y] << " ";
		}
		cout << "\n";
	}*/
	/*for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {
			cout << jihoon[x][y] << " ";
		}
		cout << "\n";
	}*/
	
	//가장자리중에서 -1 INF 가 아니면서 최소인값을 찾아라?
	int answer = INF;
	
	for (int x = 0; x < R; x++) {
		for (int y = 0; y < C; y++) {

			if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
				if (jihoon[x][y] != -1) {
					answer = min(answer, jihoon[x][y] + 1);
				}
			}
		}
	}

	if (answer >= INF) cout << "IMPOSSIBLE\n";
	else cout << answer;
}
