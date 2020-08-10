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

int X, Y;
bool check[250][250];
int arr[250][250] = { 0 };
pair<int, int> p[8] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
queue<pair<int, int>> q;

void BFS() {
	
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			if (0 <= newx && newx < X && 0 <= newy && newy < Y) {

				if (!check[newx][newy] && arr[newx][newy] == 1) {
					check[newx][newy] = true;
					q.push({ newx,newy });
				}
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X >> Y;

	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			cin >> arr[x][y];
		}
	}

	int answer = 0;
	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			//BFS돌려야함
			if (!check[x][y] && arr[x][y] == 1) {
				answer++;
				q.push({ x,y });
				check[x][y] = true;
				BFS();
			}
		}
	}

	cout << answer;
}
