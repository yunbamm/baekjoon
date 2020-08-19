#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define INF 987654321

//DP
//1. answer[x-2][y] , arr[x][y] , op = arr[x-1][y]
//2. answer[x-1][y-1] , arr[x][y] , op  = arr[x][y-1]
//3. answer[x][y-2] , arr[x][y] , op = arr[x][y-1]
//4. answer[[x-1][y-1] , arr[x][y] , op = arr[x-1][y]

int N;
char arr[6][6];
int answer[6][6] = { 0 };
int min_answer[6][6] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> arr[x][y];
		}
	}

	//answer와 min_answer초기화
	for (int x = 0; x <= N; x++) {
		for (int y = 0; y <= N; y++) {
			answer[x][y] = -INF;
			min_answer[x][y] = INF;
		}
	}
	answer[1][1] = atoi(&arr[1][1]);
	min_answer[1][1] = answer[1][1];


	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {

			if (arr[x][y] == '+' || arr[x][y] == '-' || arr[x][y] == '*') continue;
			int now = atoi(&arr[x][y]);

			//1
			if (1 <= x - 2) {
				char op = arr[x - 1][y];
				if (op == '+') answer[x][y] = max(answer[x][y], answer[x - 2][y] + now);
				if (op == '-') answer[x][y] = max(answer[x][y], answer[x - 2][y] - now);
				if (op == '*') answer[x][y] = max(answer[x][y], answer[x - 2][y] * now);

				if (op == '+') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 2][y] + now);
				if (op == '-') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 2][y] - now);
				if (op == '*') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 2][y] * now);
			}
			//2
			if (1 <= x - 1 && 1 <= y - 1) {
				char op = arr[x][y - 1];
				if (op == '+') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] + now);
				if (op == '-') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] - now);
				if (op == '*') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] * now);

				if (op == '+') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] + now);
				if (op == '-') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] - now);
				if (op == '*') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] * now);
			}
			//3
			if (1 <= y - 2) {
				char op = arr[x][y - 1];
				if (op == '+') answer[x][y] = max(answer[x][y], answer[x][y - 2] + now);
				if (op == '-') answer[x][y] = max(answer[x][y], answer[x][y - 2] - now);
				if (op == '*') answer[x][y] = max(answer[x][y], answer[x][y - 2] * now);

				if (op == '+') min_answer[x][y] = min(min_answer[x][y], min_answer[x][y - 2] + now);
				if (op == '-') min_answer[x][y] = min(min_answer[x][y], min_answer[x][y - 2] - now);
				if (op == '*') min_answer[x][y] = min(min_answer[x][y], min_answer[x][y - 2] * now);
			}
			//4
			if (1 <= x - 1 && 1 <= y - 1) {
				char op = arr[x -  1][y];
				if (op == '+') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] + now);
				if (op == '-') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] - now);
				if (op == '*') answer[x][y] = max(answer[x][y], answer[x - 1][y - 1] * now);

				if (op == '+') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] + now);
				if (op == '-') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] - now);
				if (op == '*') min_answer[x][y] = min(min_answer[x][y], min_answer[x - 1][y - 1] * now);
			}
		}
	}

	cout << answer[N][N] << " " << min_answer[N][N];
}
