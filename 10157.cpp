#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int arr[1001][1001] = { 0 };
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int row, col,K;

	cin >> col >> row;
	cin >> K;

	int x = 1, y = 1;
	int dir = 0;

	//exception
	if (row * col < K) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= row * col; i++) {
		arr[x][y] = i;
		if (i == row * col) break;
		//update
		int newx = x + p[dir].first;
		int newy = y + p[dir].second;
		//유효하지 않거나 수가 있는경우 방향전환
		if ((newx <= 0 || newy <= 0 || newx > row || newy > col) || (arr[newx][newy]!=0)) {
			dir++;
			if (dir > 3) dir = 0;
		}
		x += p[dir].first;
		y += p[dir].second;
	}

	for (int x = row; x > 0; x--) {
		for (int y = 1; y <= col; y++) {
			if (arr[x][y] == K) {
				cout << y << " " << x << "\n";
				return 0;
			}
		}
	}
}
