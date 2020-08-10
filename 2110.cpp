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
int N, C;		//집의 개수 , 공유기의 개수
vector<int> v;
vector<int> dis;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int l = 0, r = v.back() - v.front();
	int answer = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		//집간의 거리를 체크하면서 거리가 mid를 넘어갈때마다 분리해준다
		int count = 0;
		int tmp = 0;
		int prev = -1;

		for (int i = 0; i < v.size(); i++) {
			if (i == 0) prev = v[i];
			else {
				tmp += (v[i] - prev);

				if (tmp >= mid) {
					count++;
					tmp = 0;
				}
				prev = v[i];
			}
		}

		if (count + 1 >= C) {
			answer = max(mid, answer);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << answer;
}
