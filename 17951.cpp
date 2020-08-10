#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//!!!!!!!!!!!!!!!이분탐색으로

int N, K;		//시험지 개수 , 그룹 수(10^5이하)
int score[100001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//최소 , 최대
	int l = 0, r = 0;

	//입력
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> score[n];
		r += score[n];
	}

	int answer = 0;
	//이분탐색 시작
	while (l <= r) {
		int mid = (l + r) / 2;


		int tmp_score = 0, tmp_group = 0;
		for (int i = 1; i <= N; i++) {

			tmp_score += score[i];
			if (tmp_score >= mid) {
				tmp_group++;
				tmp_score = 0;
			}
		}

		//더많은 그룹으로 나누어도 점수를 충족하면 점수를 상향조정
		if (tmp_group >= K) {
			answer = max(answer, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << answer;
}
