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

//BFS를 이용
//N * N
//(0,0) -> (N-1,N-1)

int N;
char arr[50][50];		//1(흰방) 0(검은방)
int answer[50][50];
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

void BFS() {
	queue<pair<pair<int, int>, int>> q;		//좌표 , 바꾼횟수
	q.push({ {0,0},0 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int sum = q.front().second;
		q.pop();

		//더 큰 변경횟수면 무시
		if (answer[x][y] < sum) continue;

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//좌표를 벗어나면 무시
			if (newx<0 || newx>N || newy <0 || newy>N) continue;

			//흰방이고 더 적은횟수로 갈수있으면
			if (arr[newx][newy] == '1' && answer[newx][newy] > sum) {
				answer[newx][newy] = sum;
				q.push({ {newx,newy},sum });
			}
			//검은방이면
			else if(answer[newx][newy] > sum+1){
				answer[newx][newy] = sum + 1;
				q.push({ {newx,newy},sum + 1 });
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
			answer[x][y] = INF;
		}
	}
	
	BFS();

	cout << answer[N - 1][N - 1];
}
