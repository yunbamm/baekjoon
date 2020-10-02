#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//세개 꽃이 하나도 죽지않고 만개하길 원한다.
//(1,1) ~ (N,N)중 한지점에 심을수있다.
//1.다른 꽃잎이나 꽆술에 닿으면 두 꽃 모두 죽는다
//2. 화단밖으로 꽃잎이 나가도 죽는다
//땅마다 비용이 있을때 꽃을 심기 위한 최소비용을 출력한다.

//완전탐색?
int N;
int cost[11][11];
bool arr[11][11];
pair<int, int>p[5] = { {1,0},{0,1},{-1,0},{0,-1} ,{0,0} };
vector<pair<int, int>> v;
int answer = 987654321;

bool check(int x, int y) {
	for (int i = 0; i < 5; i++) {
		if (arr[x+p[i].first][y+p[i].second]) return false;
	}
	return true;
}
void process(int sx, int sy) {

	//v가 3개면 비용 확인
	if (v.size() == 3) {
		int tmp = 0;

		for (int i = 0; i < v.size(); i++) {
			int tx = v[i].first;
			int ty = v[i].second;

			for (int j = 0; j < 5; j++) {
				int nx = tx + p[j].first;
				int ny = ty + p[j].second;
				tmp += cost[nx][ny];
			}
		}

		answer = min(answer, tmp);

		return;
	}
	//전체를 탐색한다
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {

			
			//화단밖으로 나간다면
			if (x == 1 || y == 1 || x == N || y == N) continue;
			//다른꽃에 닿는다면
			if (!check(x, y)) continue;

			//방문처리
			for (int i = 0; i < 5; i++) {
				int nx = x + p[i].first;
				int ny = y + p[i].second;
				arr[nx][ny] = true;
			}
			v.push_back({ x,y });
			//재귀
			process(x, y);
			//방문처리 취소
			v.pop_back();
			for (int i = 0; i < 5; i++) {
				int nx = x + p[i].first;
				int ny = y + p[i].second;
				arr[nx][ny] = false;
			}

		}
	}

}
int main() {


	cin >> N;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> cost[x][y];
		}
	}

	process(1, 1);

	cout << answer;
}
