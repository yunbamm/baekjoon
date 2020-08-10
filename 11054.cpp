#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

//DP??? 따로따로
int one[1001] = { 0 };
int two[1001] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;

		int tmp = 0;
		
		//증가수열 최댓값
		for (int j = 0; j < num; j++) tmp = max(tmp, one[j]);
		one[num] = tmp + 1;
		
		for (int j = 1000; j > num; j--) tmp = max(tmp, two[j]);
		two[num] = tmp + 1;
	}
	
	int answer = 0;
	for (int i = 0; i < 1001; i++) {
		answer = max(answer, one[i]);
		answer = max(answer, two[i]);
	}

	cout << answer;
}
