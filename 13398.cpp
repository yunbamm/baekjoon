#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DP

//!!!!주의 : 한개이상의 수를 선택해야한다
// 만약 -3 하나만 들어오면 first = -3 , second 0 이되기때문에 max값은 0이지만 한개이상을 선택해야하므로 -3이정답이다
int N;
pair<int, int> answer[100000];			//수를 지우지 않을때 , 지울때

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	//answer 초기화 
	for (int i = 0; i < N; i++) {
		answer[i].first = -987654321;
		answer[i].second = -987654321;
	}
	int tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;

		if (n == 0) {
			answer[0].first = tmp;
			answer[0].second = 0;
		}

		else {
			answer[n].first = max(tmp, answer[n - 1].first + tmp);

			//지운경우
			//전에 지운거와 지금 더한거 
			answer[n].second = max(answer[n].second, answer[n - 1].second + tmp);
			//전에 안지운거와 지금 지운거
			answer[n].second = max(answer[n].second, answer[n - 1].first);

		}
	}

	//초기값 : 1번째 수만 선택되었을때
	int max_answer = answer[0].first;
	for (int i = 1; i < N; i++) {
		max_answer = max(max_answer, max(answer[i].first, answer[i].second));
	}
	cout << max_answer;
}




