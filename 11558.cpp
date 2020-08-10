#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DFS

int arr[10001] = { 0 };
int T, N;

int DFS(int now, int sum) {

	if (sum > N) return 0;
	if (now == N) return sum;

	return DFS(arr[now], sum + 1);
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;

		for (int n = 1; n <= N; n++) {
			cin >> arr[n];
		}

		cout << DFS(1,0)<<"\n";
	}
}
