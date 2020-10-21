#include <string>
#include <vector>
#include<queue>

using namespace std;

//네트워크

bool check[201];
queue<int> q;

void BFS(vector<vector<int>> computers , int n) {

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (i != now && computers[now][i] == 1 && !check[i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			answer++;
			check[i] = true;
			q.push(i);
			BFS(computers , n);
		}
	}
	return answer;
}
