#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N, M;
long long answer[100001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int tmp;
	for (int n = 1; n <= N; n++) {
		cin >> tmp;
		answer[n] = answer[n - 1] + tmp;
	}

	long long max_answer = 0;

	for (int i = M; i <= N; i++) {
		max_answer = max(max_answer, answer[i] - answer[i - M]);
	}

	cout << max_answer;
}
