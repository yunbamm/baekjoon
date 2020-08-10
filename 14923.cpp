#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


//BFS

int N, M;

int miro[1001][1001][2];

pair<int, int> start;
pair<int, int> finish;

pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//시작위치
	cin >> start.first >> start.second;
	//탈출위치
	cin >> finish.first >> finish.second;

	int num;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> num;
			//빈공간이면
			if (num == 0) {
				miro[n][m][0] = 0;
				miro[n][m][1] = 0;
			}
			//벽이면
			else {
				miro[n][m][0] = -1;
				miro[n][m][1] = -1;
			}
		}
	}

	//지팡이 사용유무 ( 0  미사용 1 사용 ) , 좌표
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{start.first , start.second} });

	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int z = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//유효한점이고 시작점이 아닐때
			if (1 <= newx && newx <= N && 1 <= newy && newy <= M && !(newx == start.first && newy == start.second)) {
				
				//빈공간일때
				if (miro[newx][newy][z] == 0) {
					q.push({ z,{newx,newy} });
					miro[newx][newy][z] = miro[x][y][z] + 1;
				}
				//벽인데 지팡이 사용을 안했으면
				//!!!!!!실수 : z를 1로 수정해버리면 안됨 for문을 돌리기전에 z가 변경되기 때문에 이상해질수있음
				else if (miro[newx][newy][z] == -1 && z == 0) {
					q.push({ 1,{newx,newy} });
					miro[newx][newy][1] = miro[x][y][0] + 1;
				}
			}
		}
	}

	int answer = 987654321;
	for (int i = 0; i < 2; i++) {
		if (miro[finish.first][finish.second][i] == 0 || miro[finish.first][finish.second][i] == -1) continue;

		answer = min(answer, miro[finish.first][finish.second][i]);
	}

	if (answer == 987654321) cout << "-1\n";
	else cout << answer;
}
