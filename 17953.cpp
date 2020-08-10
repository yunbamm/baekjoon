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

int N,M;		//주기 날짜수 , 디저트 종류수
int happy[11][100001] = { 0 };		//i디저트를 j일에 먹으면 느끼는 행복	
int answer[11][100001] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//입력받기
	cin >> N >> M;
	for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			cin >> happy[m][n];
		}
	}

	//i일에
	for (int i = 1; i <= N; i++) {
		//j디저트를 먹으면
		for (int j = 1; j <= M; j++) {

			//!!!!!!!!!!!!!!!!!i가 1이면 과거 볼필요X
			if (i == 1) {
				answer[j][i] = happy[j][i];
			}
			else {
				//그전날까지의 결과로 최대값을 구한다 (answer[m][전날] + happy[m][오늘])
				for (int m = 1; m <= M; m++) {
					//전날과 같은 디저트
					if (m == j) {
						answer[j][i] = max(answer[m][i - 1] + happy[j][i] / 2, answer[j][i]);
					}
					//다른 디저트
					else {
						answer[j][i] = max(answer[m][i - 1] + happy[j][i], answer[j][i]);
					}
				}
			}
		}
	}

	//N일에 최대값구하기
	int max_answer = 0;
	for (int m = 1; m <= M; m++) {
		max_answer = max(max_answer, answer[m][N]);
	}
	cout << max_answer;
}
