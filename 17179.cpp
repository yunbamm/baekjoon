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
int N, M, L;		//자르는 횟수가 담긴 목록길이, 자르는 지점 , 길이
vector<int> v;

int main() {

	cin >> N >> M >> L;

	int prev = 0;
	int now = 0;
	for (int i = 0; i < M; i++) {
		cin >> now;
		v.push_back(now - prev);
		prev = now;
	}

	//!!!!!!!!!마지막 조각
	v.push_back(L - prev);

	int cnt;		//자르는횟수

	for (int n = 0; n < N; n++) {
		cin >> cnt;

		int l = 0, r = L;
		int answer = 0;

		while (l <= r) {
			int mid = (l + r) / 2;

			int tmp = 0;
			int count = 0;
			for (int i = 0; i < v.size(); i++) {
				tmp += v[i];
				if (tmp >= mid) {
					tmp = 0;
					count++;
				}
			}

			//토막수는 자르는횟수+1이므로
			if (count >= cnt + 1) {
				l = mid + 1;
				answer = max(answer, mid);
			}
			else r = mid - 1;
		}


		cout << answer << "\n";
	}
}
