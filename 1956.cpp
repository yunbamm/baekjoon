#include<iostream>
#include<algorithm>

using namespace std;

#define INF 987654321

int V, E;

int arr[401][401];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		for(int j = 1; j <= V; j++) {
			arr[i][j] = INF;
		}
	}

	int src, dest, cost;
	for (int e = 0; e < E; e++) {
		cin >> src >> dest >> cost;

		arr[src][dest] = min(arr[src][dest], cost);
	}

	for (int i = 1; i <= V; i++) {

		for (int x = 1; x <= V; x++) {
			for (int y = 1; y <= V; y++) {
				if (arr[x][y] > arr[x][i] + arr[i][y]) arr[x][y] = arr[x][i] + arr[i][y];
			}
		}
	}

	int answer = INF;

	for (int i = 1; i <= V; i++) {
		answer = min(answer, arr[i][i]);
	}

	if (answer >= INF) cout << "-1\n";
	else cout << answer;
}
