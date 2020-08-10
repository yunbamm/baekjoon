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

#define INF 10000000000

int N, K;		//주전자 개수 , 친구들수

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	vector<int> v;
	int tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	int l = 0, r = (1 << 31) - 1;
	int answer = 0;
	while (l <= r) {
		int mid = (l + r) / 2;


		int count = 0;
		for (int i = 0; i < v.size(); i++) {
			count += v[i] / mid;
		}

		if (count >= K) {
			l = mid + 1;
			answer = max(answer, mid);
		}
		else r = mid - 1;
	}
	cout << answer;
}
