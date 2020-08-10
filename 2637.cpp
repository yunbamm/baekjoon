#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//위상정렬
int N, M;

vector<vector<pair<int, int>>>v(101);		//후속부품 , 개수

int degree[101] = { 0 };
int answer[101] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int post, pre, num;
	for (int i = 0; i < M; i++) {
		cin >> post >> pre >> num;
		v[post].push_back({ pre,num });
		degree[pre]++;
	}


	//완제품부터 start
	queue<pair<int, int>> q;		//부품번호 , 개수
	q.push({ N,1 });

	while (!q.empty()) {
		int now = q.front().first;
		int sum = q.front().second;
		q.pop();


		if (v[now].size() == 0) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int tmp = v[now][i].second;

			answer[next] += sum * tmp;

			if (--degree[next] == 0) {
				//cout << next << " , " << answer[next] << "\n";
				q.push({ next , answer[next]});
			}
		}

		answer[now] = 0;
	}


	for (int i = 1; i <= N; i++) {
		if (answer[i] != 0) cout << i << " " << answer[i] << "\n";
	}
}
