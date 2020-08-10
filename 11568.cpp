#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int arr[1000];
int dp[1000];
int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	
	//dp ㅊ기화
	for (int i = 0; i < N; i++) dp[i] = 1;

	//i번째를 기준으로 하나씩 앞에걸로 이동하면서 본다
	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, dp[i]);
	}

	cout << answer;
}
