#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

// N * M , 초원 (.) , 빙판 (+) , 산 (#) , 늑대들 (W)
//늑대는 상하좌우 이동가능 ( 산 X )
//이동한곳이 빙판이면 초원을 밟거나 산에 부딪힐때까지 그 방향으로 미끄러진다


//늑대가 도달할수없고 초원인 부분을 P로 표시해서 출력해라
//check를 통해 해당 방향으로 빙판에 들어온적이 있는지 확인하는게 핵심
int N, M;
char arr[100][100];
bool check[100][100][4];
bool wolf[100][100];

pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };
queue<pair<int, int>> q;

void ice_move(int x, int y , int dir) {

	int nowx = x;
	int nowy = y;

	while (1) {
		int next_x = nowx + p[dir].first;
		int next_y = nowy + p[dir].second;

		//다음이 산이면
		if (arr[next_x][next_y] == '#') {
			q.push({ nowx,nowy });
			break;
		}

		//초원이면
		if (arr[next_x][next_y] == '.') {
			wolf[next_x][next_y] = true;
			q.push({ next_x,next_y });
			break;
		}

		//빙판이면
		check[next_x][next_y][dir] = true;
		nowx = next_x;
		nowy = next_y;
		//범위를 벗어나면
		if (next_x < 0 || N <= next_x || next_y < 0 || M <= next_y) break;
	}
}
void BFS() {
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//좌표를 벗어나면 무시
			if (newx < 0 || N <= newx || newy < 0 || M <= newy) continue;
			//산이거나 ,  늑대가 올수있는 초원이거나 , 전에 들어왔던 방향의 빙판이면
			if (arr[newx][newy] == '#' || wolf[newx][newy] || check[newx][newy][i])continue;

			//여기가 초원이면
			if (arr[newx][newy] == '.') {
				wolf[newx][newy] = true;
				q.push({ newx,newy });
			}
			//빙판이면? check를 해주면 안된다 이동방향에 따라 갈수있는곳이 달라지니까
			else if(arr[newx][newy] == '+') {
				check[newx][newy][i] = true;
				ice_move(newx, newy, i);
			}
			
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> arr[n][m];
		}
	}

	//늑대가 있는곳이라면 BFS
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (arr[n][m] == 'W') {
				wolf[n][m] = true;
				q.push({ n,m });
				BFS();
			}
		}
	}

	//초원인데 늑대가 올수없다면
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (arr[n][m] == '.' && !wolf[n][m]) arr[n][m] = 'P';
		}
	}

	//정답 출력
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cout << arr[n][m];
		}
		cout << "\n";
	}
}
