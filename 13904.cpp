#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, D, W;		//과제개수 ,마감일 , 점수

int DP[1001][1001] = { 0 };		//[day][일index]
int tmp[1001][1001] = { 0 };		//
vector<pair<int, int>> v;

int main() {
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> D >> W;
		v.push_back({ D,W });
	}

	sort(v.begin(), v.end());

	//DP시작
	for (int i = 0; i < v.size(); i++) {
		int day = v[i].first;
		int score = v[i].second;

		//0 ~ day-1까지를 검사해서 index도 i-1까지만 보면된다
		for (int x = 0; x < day; x++) {
			for (int y = 0; y < i; y++) {
				
				//얻을 점수가 있으면 현재 과제를 했을때를 고려해준다
				if (DP[x][y] != 0) {
					tmp[x + 1][i] = max(tmp[x + 1][i], DP[x][y] + score);
				}
			}
		}

		//복사해준다
		for (int x = 0; x <= day; x++) {
			for (int y = 0; y <= i; y++) {
				if (tmp[x][y] != 0) {
					DP[x][y] = max(DP[x][y], tmp[x][y]);
					tmp[x][y] = 0;
				}
			}
		}

		//현재일을 첫날했을때 추가
		DP[1][i] = max(DP[1][i], score);
	}

	//최댓값을 찾는다 
	int answer = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			answer = max(answer, DP[i][j]);
		}
	}

	cout << answer;
}
