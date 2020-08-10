#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//!!!!!!!!!!!!!위상정렬 ( queue )
//후행
vector<vector<int>> v(1001);
//degree
int degree[1001] = { 0 };
int answer[1001] = { 0 };
int N, M;	//과목수 , 선수조건 수

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	int pre, post;
	for (int m = 0; m < M; m++) {
		cin >> pre >> post;
		v[pre].push_back(post);
		degree[post]++;
	}

	queue<pair<int,int>> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push({ i, 1 });
		}
	}

	while (!q.empty()) {
		int now = q.front().first;
		int sum = q.front().second;
		q.pop();
		answer[now] = sum;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (--degree[next] == 0) {
				q.push({ next , sum + 1 });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << answer[i] << " ";
	}
}
