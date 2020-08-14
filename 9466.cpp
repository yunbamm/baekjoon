#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DFS

//1.DFS로 순환의 끝부분을 찾는다
//EX) 4 -> 7 -> 6 -> 4 : 4

int T, N;

int post[100001] = { 0 };
bool check[100001];
int team[100001];		//-1(안됨) 0 ( 아직모름) 1(됨)

stack<int> s;

void DFS(int now) {
	int next = post[now];

	//다음꺼도 들린적 없을때
	if (!check[next]) {
		check[next] = true;
		s.push(next);
		DFS(next);
	}
	//들린적이 있는데 team인지 모를때
	else if(team[next] == 0) {
		while (!s.empty()) {
			int tmp = s.top();
			team[tmp] = 1;
			s.pop();

			if (tmp == next) break;
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	while (T--) {
		cin >> N;



		for (int n = 1; n <= N; n++) {
			cin >> post[n];
			team[n] = false;
			check[n] = false;
		}

		//i번째 애를 본다
		for (int i = 1; i <= N; i++) {
			//들린애가 아니라면
			if (!check[i]) {
				check[i] = true;
				s.push(i);
				DFS(i);

				while (!s.empty()) {
					team[s.top()] = -1;
					s.pop();
				}
			}
		}
		int answer = N;

		for (int i = 1; i <= N; i++) {
			if (team[i] == 1) answer--;
		}
		
		cout << answer << "\n";

	}
}

