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
int N, S, D, F, B, K;
bool polic[100001];
int check[100001];

void BFS() {

	//check -1로 초기화
	for (int n = 1; n <= N; n++) check[n] = -1;

	queue<int> q;
	q.push(S);
	check[S] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//집이면 끝
		if (now == D) return;

		//1.+F
		if (now + F <= N && check[now+F] == -1 && !polic[now+F]) {
			q.push(now + F);
			check[now + F] = check[now] + 1;
		}
		//2.-B
		if (1 <= now - B && check[now - B] == -1 && !polic[now - B]) {
			q.push(now - B);
			check[now - B] = check[now] + 1;
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S >> D >> F >> B >> K;
	//경찰서 위치
	int tmp;
	for (int k = 0; k < K; k++) {
		cin >> tmp;
		polic[tmp] = true;
	}

	//S -> D
	BFS();

	if (check[D] == -1) cout << "BUG FOUND";
	else cout << check[D];
}
