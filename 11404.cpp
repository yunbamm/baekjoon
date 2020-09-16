#include<iostream>
#include<algorithm>

using namespace std;

#define INF 987654321

int N, M;
int arr[101][101];

int main() {
	
	cin >> N >> M;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			if (x == y) arr[x][y] = 0;
			else arr[x][y] = INF;
		}
	}

	int src, dest, cost;
	for (int m = 0; m < M; m++) {
		cin >> src >> dest >> cost;

		arr[src][dest] = min(arr[src][dest], cost);
	}

	for (int i = 1; i <= N; i++) {
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {

				if (arr[x][i] + arr[i][y] < arr[x][y]) {
					arr[x][y] = arr[x][i] + arr[i][y];
				}
			}
		}
	}

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {

			if (arr[x][y] >= INF) cout << "0 ";
			else cout << arr[x][y] << " ";
		}
		cout << "\n";
	}
}
