#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

stack<pair<int, int>> s;		//점수 , 남은시간
int answer = 0;
int N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;

	int n1, n2, n3;

	for (int i = 0; i < N; i++) {
		cin >> n1;
		//1이면 새로운 과제가 들어온다
		if (n1 == 1) {
			cin >> n2 >> n3;
			if (n3 == 1) {
				answer += n2;
			}
			else s.push({ n2, --n3 });
		}
		//0이면 있는 과제를 한다
		else {
			if (!s.empty()) {
				int score = s.top().first;
				int time = s.top().second;
				s.pop();

				//과제끝
				if (time == 1) {
					answer += score;
				}
				//아직 남았다
				else {
					s.push({ score,--time });
				}
			}
		}

	}
	
	cout << answer;
}
