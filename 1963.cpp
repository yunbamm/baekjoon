#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//우선 에라토스테네스의 체를 통해 소수 판별
bool sosu[10000];			//false면 소수

void sosu_process() {

	for (int i = 2; i <= 9999; i++) {

		//이미 소수가 아니면 무시
		if (sosu[i]) continue;

		//소수의 배수를 소수가 아닌걸로 check
		for (int j = i + i; j <= 9999; j += i) {
			sosu[j] = true;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	sosu_process();

	int T;
	cin >> T;

	int src, dest;
	while (T--) {
		cin >> src >> dest;

		queue<int> q;
		int answer[100000];

		//answer초기화
		for (int i = 1000; i <= 9999; i++) answer[i] = -1;

		q.push(src);
		answer[src] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == dest) break;
			int one = now / 1000;
			int two = ((now % 1000) - (now % 100)) / 100;
			int three = ((now % 100) - (now % 10)) / 10;
			int four = (now % 10);
			int tmp = 0;

			//첫번쨰 숫자를 바꾸면
			for (int i = 1; i <= 9; i++) {
				tmp += i * 1000;
				tmp += two * 100;
				tmp += three * 10;
				tmp += four;

				//소수이고 만든적이 없으면
				if (!sosu[tmp] && answer[tmp] == -1) {
					answer[tmp] = answer[now] + 1;
					q.push(tmp);
				}
				tmp = 0;
 			}

			//두번쨰 숫자를 바꾸면
			for (int i = 0; i <= 9; i++) {
				tmp += one * 1000;
				tmp += i * 100;
				tmp += three * 10;
				tmp += four;

				//소수이고 만든적이 없으면
				if (!sosu[tmp] && answer[tmp] == -1) {
					answer[tmp] = answer[now] + 1;
					q.push(tmp);
				}
				tmp = 0;
			}

			//세번쨰 숫자를 바꾸면
			for (int i = 0; i <= 9; i++) {
				tmp += one * 1000;
				tmp += two * 100;
				tmp += i * 10;
				tmp += four;

				//소수이고 만든적이 없으면
				if (!sosu[tmp] && answer[tmp] == -1) {
					answer[tmp] = answer[now] + 1;
					q.push(tmp);
				}
				tmp = 0;
			}

			//네번쨰 숫자를 바꾸면
			for (int i = 0; i <= 9; i++) {
				tmp += one * 1000;
				tmp += two * 100;
				tmp += three * 10;
				tmp += i;

				//소수이고 만든적이 없으면
				if (!sosu[tmp] && answer[tmp] == -1) {
					answer[tmp] = answer[now] + 1;
					q.push(tmp);
				}
				tmp = 0;
			}
		}

		if (answer[dest] == -1) cout << "Impossible\n";
		else cout << answer[dest] << "\n";
	}
}
