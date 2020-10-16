#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//1(집) 0 (빈칸)
//죄우위아래 연결 -> 단지
//단지수 , 단지에 속하는 집의 수 오름차순
//N*N

int N;
char arr[25][25];
bool check[25][25];
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int BFS(int sx, int sy) {

	//초기값
	int count = 0;
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	check[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		count++;

		for (int i = 0; i < 4; i++) {
			int nx = x + p[i].first;
			int ny = y + p[i].second;

			//범위벗어나면 무시
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			//들린곳이면 무시
			if (check[nx][ny]) continue;

			//집이있으면 추가
			if (arr[nx][ny] == '1') {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}

	return count;

}
int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans1 = 0;
	vector<int>v;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1' && !check[i][j]) {
				int tmp = BFS(i, j);
				v.push_back(tmp);
				ans1++;
			}
		}
	}
	cout << ans1 << "\n";

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}
