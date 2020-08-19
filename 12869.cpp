#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define INF 987654321

//BFS처럼?

int answer[61][61][61];
int N;		//SCV수 (1~3)
int arr[3] = { 0,0,0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//answer초기화
	for (int x = 0; x <= 60; x++) {
		for (int y = 0; y <= 60; y++) {
			for (int z = 0; z <= 60; z++) {
				answer[x][y][z] = INF;
			}
		}
	}

	//입력받기
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {arr[0],arr[1]},arr[2] });
	answer[arr[0]][arr[1]][arr[2]] = 0;
	
	int tmpx, tmpy, tmpz;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		// 9 , 3 ,1
		tmpx = max(0, x - 9);
		tmpy = max(0, y - 3);
		tmpz = max(0, z - 1);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
		// 9 , 1 ,3
		tmpx = max(0, x - 9);
		tmpy = max(0, y - 1);
		tmpz = max(0, z - 3);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
		// 3 , 9 ,1
		tmpx = max(0, x - 3);
		tmpy = max(0, y - 9);
		tmpz = max(0, z - 1);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
		// 3 , 1, 9
		tmpx = max(0, x - 3);
		tmpy = max(0, y - 1);
		tmpz = max(0, z - 9);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
		// 1 , 9, 3
		tmpx = max(0, x - 1);
		tmpy = max(0, y - 9);
		tmpz = max(0, z - 3);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
		// 1 , 3, 9
		tmpx = max(0, x - 1);
		tmpy = max(0, y - 3);
		tmpz = max(0, z - 9);
		if (answer[tmpx][tmpy][tmpz] == INF) {
			answer[tmpx][tmpy][tmpz] = answer[x][y][z] + 1;
			q.push({ {tmpx,tmpy},tmpz });
		}
	}

	cout << answer[0][0][0];
}
