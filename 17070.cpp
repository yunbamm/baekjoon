#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//백트래킹?? DFS??

//방향에 따라
//1. 가로 : ( +0 , +1 , 가로) , ( +1 , +1 , 대각선)
//2. 세로 : ( +1 , +0 , 세로) , ( +1 , +1, 대각선)
//3. 대각선 : (+0, +1, 가로) , (+1, +0 , 세로) , (+1, +1 , 대각선)

//시작 ( 1 , 2 , 가로)
//주의 : 가로 or 세로로 갈때는 해당 부분만 빈칸이면 되지만
//대각선으로 갈때는 (+1, +1) , (+0 , +1) , ( +1, +0) 부분이 빈칸이어야한다

int N;
int arr[17][17];
int answer = 0;

//0 가로 1 세로 2 대각
void DFS(int x, int y, int dir) {

	//만약 (N,N)이면
	if (x == N && y == N) {
		answer++;
		return;
	}

	//1. 가로 : ( +0 , +1 , 가로) , ( +1 , +1 , 대각선)
	if (dir == 0) {
		if (y + 1 <= N && arr[x][y + 1] == 0) {
			DFS(x, y + 1, 0);
		}
		if (x + 1 <= N && y + 1 <= N && arr[x + 1][y + 1] == 0 && arr[x + 1][y] == 0 && arr[x][y + 1] == 0) {
			DFS(x + 1, y + 1, 2);
		}
	}
	//2. 세로 : ( +1 , +0 , 세로) , ( +1 , +1, 대각선)
	if (dir == 1) {
		if (x + 1 <= N && arr[x + 1][y] == 0) {
			DFS(x + 1, y, 1);
		}
		if (x + 1 <= N && y + 1 <= N && arr[x + 1][y + 1] == 0 && arr[x + 1][y] == 0 && arr[x][y + 1] == 0) {
			DFS(x + 1, y + 1, 2);
		}
	}
	//3. 대각선 : (+0, +1, 가로) , (+1, +0 , 세로) , (+1, +1 , 대각선)
	if (dir == 2) {
		if (y + 1 <= N && arr[x][y + 1] == 0) {
			DFS(x, y + 1, 0);
		}
		if (x + 1 <= N && arr[x + 1][y] == 0) {
			DFS(x + 1, y, 1);
		}
		if (x + 1 <= N && y + 1 <= N && arr[x + 1][y + 1] == 0 && arr[x + 1][y] == 0 && arr[x][y + 1] == 0) {
			DFS(x + 1, y + 1, 2);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	//입력받기
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> arr[x][y];
		}
	}

	DFS(1, 2, 0);

	cout << answer;
}
