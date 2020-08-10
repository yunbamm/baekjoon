#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//!!!!!!!!!!백트래킹

int answer = 11;
int N, M;		//문제 수 , 학생 수
vector<vector<int>> v(11);
bool check[11];
bool pick[11];
int solve[11] = { 0 };		//학생마다 푼 문제수??
vector<int> problem;

void DFS(int count , int m) {

	if (problem.size() == N) {
		answer = min(answer, m);
		/*for (int i = 0; i < problem.size(); i++) {
			cout << problem[i] << " , ";
		}
		cout << "\n";*/
		return; 
	}
	for (int i = 1; i <= M; i++) {
		//안뽑힌학생이면
		if (!pick[i]) {
			pick[i] = true;
			//뽑힌학생이 풀수있는문제 표시
			for (int j = 0; j < v[i].size(); j++) {
				if (!check[v[i][j]]) {
					check[v[i][j]] = true;
					solve[i]++;
					problem.push_back(v[i][j]);
				}
			}

			DFS(count , m+1);

			//다시 복구
			while (solve[i] > 0) {
				int tmp = problem.back();
				check[tmp] = false;
				problem.pop_back();
				solve[i]--;
			}
			pick[i] = false;
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//입력받기
	cin >> N >> M;
	int tmp, num;
	for (int m = 0; m < M; m++) {
		cin >> tmp;
		for (int i = 0; i < tmp; i++) {
			cin >> num;
			v[m + 1].push_back(num);
		}
	}
	DFS(0 , 0);
	//출력
	if (answer == 11) cout << "-1\n";
	else cout << answer;
}
