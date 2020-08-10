#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


//stack

int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> N;
		if (N == 0) break;

		stack<pair<long long,long long>> s;		//높이 , x위치
		long long answer = 0;

		int h;
		for (int n = 0; n < N; n++) {
			cin >> h;

			//비어있으면
			if (s.empty()) s.push({ h,n });
			//아니면
			else {
				long long tmp = n;

				//top에 더 작은게 있거나 s가 빌때까지 처리
				while (!s.empty()) {
					
					//큰게오면 그냥 push
					if (s.top().first < h) break;
					//작거나 같은게 오면
					else {
						tmp = s.top().second;
						answer = max(answer, s.top().first * (n - s.top().second));
						s.pop();
					}
				}

				s.push({ h , tmp });
			}

		}

		//입력다받고 s에 남은게 있다면
		while (!s.empty()) {
			answer = max(answer, s.top().first * (N - s.top().second));
			s.pop();
		}
		cout << answer << "\n";
	}


}
