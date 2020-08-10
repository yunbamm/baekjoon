#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

//힐링

int N, M;
char arr[100][100];
bool check[100][100];
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int tmp = 0;
void DFS(int x, int y , int num) {

	tmp++;

	for (int i = 0; i < 4; i++) {
		int newx = x + p[i].first;
		int newy = y + p[i].second;

		if (0 <= newx && newx < M && 0 <= newy && newy < N) {
			if (!check[newx][newy] && arr[x][y] == arr[newx][newy]) {
				check[newx][newy] = true;
				DFS(newx, newy,num+1);
			}
		}
	}

	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
		}
	}
	
	int ans1 = 0, ans2 = 0;

	for (int x = 0; x < M; x++) {
		for (int y = 0; y < N; y++) {
			if (!check[x][y]) {
				check[x][y] = true;
				DFS(x, y,1);

				if (arr[x][y] == 'W')  ans1 += tmp * tmp;

				else ans2 += tmp * tmp;

				tmp = 0;
			}
		}
	}

	cout << ans1 << " " << ans2;
}
