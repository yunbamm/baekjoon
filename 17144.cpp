#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int R, C, T;		//x크기 , y크기 , T초
int arr[51][51];	//-1이면 공기청정기
int tmp[51][51];	//먼지의 변동량을 가지고 있다
vector<pair<int, int>> air_cleaner;
pair<int, int> p[4] = { {1,0},{-1,0},{0,1},{0,-1} };

//1.미세먼지 확산
//인접한 4방향으로 (공기청정기가 있는곳은 X)
//arr[r][c]/5만큼씩 확산 남은양 
void first() {

	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			//미세먼지가 있으면
			if (arr[x][y] > 0) {
				for (int i = 0; i < 4; i++) {
					int newx = x + p[i].first;
					int newy = y + p[i].second;

					//좌표를 벗어나면 무시
					if (newx < 1 || newx > R || newy < 1 || newy > C) continue;

					//공기청정기가 있는곳이면 무시
					if (arr[newx][newy] == -1) continue;

					//아니면 확산
					tmp[newx][newy] += (arr[x][y] / 5);
					tmp[x][y] -= (arr[x][y] / 5);
				}
			}
		}
	}
	//변동량을 더한다
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			arr[x][y] += tmp[x][y];
			tmp[x][y] = 0;
		}
	}
}

//2.위쪽 공기청정기 (반시계방향)
//아래쪽은 시계방향 
//만약 공기청정기로 들어가면 모두 정화!
void second() {

	//위쪽 공기청정기
	int x = air_cleaner[0].first;
	int y = air_cleaner[0].second;
	
	x--;
	//1
	while (1) {
		if (x == 1) break;
		arr[x][y] = arr[x - 1][y];
		x--;
	}
	//3
	while (1) {
		if (y == C) break;
		arr[x][y] = arr[x][y + 1];
		y++;
	}
	//4
	while (1) {
		if (x == air_cleaner[0].first) break;
		arr[x][y] = arr[x + 1][y];
		x++;
	}
	//5
	while (1) {
		if (y == air_cleaner[0].second) break;
		arr[x][y] = arr[x][y - 1];
		y--;
	}
	//아래
	x = air_cleaner[1].first;
	y = air_cleaner[1].second;
	x++;
	//1
	while (1) {
		if (x == R) break;
		arr[x][y] = arr[x + 1][y];
		x++;
	}
	//3
	while (1) {
		if (y == C) break;
		arr[x][y] = arr[x][y + 1];
		y++;
	}
	//4
	while (1) {
		if (x == air_cleaner[1].first) break;
		arr[x][y] = arr[x - 1][y];
		x--;
	}
	//5
	while (1) {
		if (y == air_cleaner[1].second) break;
		arr[x][y] = arr[x][y - 1];
		y--;
	}

	//공기청정기 바로 옆칸은 무조건 0
	arr[air_cleaner[0].first][air_cleaner[0].second + 1] = 0;
	arr[air_cleaner[1].first][air_cleaner[1].second + 1] = 0;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			cin >> arr[x][y];

			if (arr[x][y] == -1) {
				air_cleaner.push_back({ x,y });
			}
		}
	}
	
	while (T--)
	{
		first();
		second();
	}
	int answer = 0;
	for (int x = 1; x <= R; x++) {
		for (int y = 1; y <= C; y++) {
			if (arr[x][y] > 0) answer += arr[x][y];
		}
	}

	cout << answer;
}



