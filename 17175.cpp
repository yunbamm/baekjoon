#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

long long arr[51] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= 50; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] + 1) % 1000000007;
	}

	int N;
	cin >> N;

	cout << arr[N];
}
