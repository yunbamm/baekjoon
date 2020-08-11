#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//플로이드

int N, M;

int dis[501][501] = { 0 };


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> dis[x][y];
		}
	}

	//플로이드
	for (int i = 1; i <= N; i++) {

		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				if (dis[x][y] > dis[x][i] + dis[i][y]) {
					dis[x][y] = dis[x][i] + dis[i][y];
				}
			}
		}
	}

	int A, B, T;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> T;

		if (dis[A][B] <= T) {
			cout << "Enjoy other party\n";
		}
		else cout << "Stay here\n";
	}
}
