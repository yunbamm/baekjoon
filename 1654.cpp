#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//이분탐색

int K, N;	//이미가진 랜선개수 , 필요한 랜선 개수
vector<long long> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> N;
	int num;
	for (int k = 0; k < K; k++) {
		cin >> num;
		v.push_back(num);
	}

	long long l = 0, r = (1 << 31) - 1;
	long long answer = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;

		long long count = 0;
		for (int i = 0; i < v.size(); i++) {
			count += v[i] / mid;
		}

		if (count >= N) {
			answer = max(answer, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << answer;
}
