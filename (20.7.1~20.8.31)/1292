#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

//힐링

int arr[1000] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int num = 1;
	int trial = 1;
	for (int i = 0; i < 1000; i++) {
		arr[i] = num;
		if (--trial == 0) {
			trial = ++num;
		}
	}

	int A, B;
	cin >> A >> B;

	int answer = 0;
	for (int i = A - 1; i < B; i++) {
		answer += arr[i];
	}
	cout << answer;
}
