#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//힌트 : stack

int N;
stack<pair<int, int>> s;		//높이 시간
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	int h;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> h;

		int tmp = i;

		//비어있다면 push
		if (s.empty()) s.push({ h,i });
		//아니라면 처리필요
		else {

			while (!s.empty()) {

				//더 큰게 온다면 push후 break;
				if (s.top().first < h) {
					s.push({ h,tmp });
					break;
				}
				//작거나 같으면 pop해서 처리 필요
				else {
					tmp = s.top().second;		//i - tmp가 x축 길이라고 생각하면 편하다
					answer = max(answer, s.top().first * (i - s.top().second));
					s.pop();

					//!!!!!!!!!처리와중에 s가 비면 현재 입력을 push해줘야함
					if (s.empty()) {
						s.push({ h,tmp });
						break;
					}
				}
			}
		}
	}

	while (!s.empty()) {
		answer = max(answer, s.top().first * ( N + 1 - s.top().second));
		s.pop();
	}
	cout << answer;
}
