#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//BFS?

int N, S;
int arr[100001] = { 0 };
bool check[100001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	cin >> S;

	queue<int> q;
	q.push(S);
	check[S] = true;

	while (!q.empty()) {
		int x = q.front();
		int tmp = arr[x];
		q.pop();

		if (x + tmp <= N && !check[x+tmp]) {
			check[x+tmp] = true;
			q.push(x + tmp);
		}
		if (x - tmp >= 1 && !check[x - tmp]) {
			check[x - tmp] = true;
			q.push(x - tmp);
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i]) answer++;
	}

	cout << answer;
}
