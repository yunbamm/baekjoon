#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//BFS
//1. X보다 잘한 애들
//2. X보다 못한 애들

int N, M, X;
vector<vector<int>> pre(100001);
vector<vector<int>> post(100001);
bool check[100001];

int BFS1(int N) {

	int tmp = 1;
	check[N] = true;

	queue<int> q;
	q.push(N);

	while (!q.empty()){
		int now = q.front();
		q.pop();

		for (int i = 0; i < pre[now].size(); i++) {
			int next = pre[now][i];

			if (!check[next]) {
				check[next] = true;
				q.push(next);
				tmp++;
			}
		}
	}

	return tmp;
}
int BFS2(int N) {

	int tmp = 0;
	check[N] = true;

	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < post[now].size(); i++) {
			int next = post[now][i];

			if (!check[next]) {
				check[next] = true;
				q.push(next);
				tmp++;
			}
		}
	}

	return tmp;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	int n1, n2;		//n1 < n2

	for (int m = 0; m < M; m++) {
		cin >> n1 >> n2;
		pre[n2].push_back(n1);		//n2보다 n1이 잘한다
		post[n1].push_back(n2);		//n1이 n2보다 잘한다
	}


	//X보다 잘한애들 수 구하기
	cout << BFS1(X) << " ";

	//check초기화
	for (int i = 1; i <= N; i++) check[i] = false;
	cout << N - BFS2(X);
}
