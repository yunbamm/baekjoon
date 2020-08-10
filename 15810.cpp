#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define MAX_N 1000000		//스태프 수
#define MAX_M 1000000		//풍선 수 
#define MAX_A 1000000		//걸리는 시간

int N, M;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	int tmp;
	vector<long long> v;
	for (int n = 0; n < N; n++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	

	long long l = 0, r = 100000000000;
	long long answer = 100000000000;
	while (l <= r) {
		long long mid = (l + r) / 2;

		long long count = 0;
		for (int i = 0; i < v.size(); i++) {
			count += mid / v[i];
		}

		if (count >= M) {
			answer = min(answer, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << answer;
}
