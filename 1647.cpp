#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//MST

int N, M;		//집개수, 길개수
priority_queue<pair<int, pair<int, int>>> pq;		//비용, 집 번호
int parent[100001];

int find(int N) {
	if (parent[N] == N) return N;
	return parent[N] = find(parent[N]);
}

void union_set(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 < p2) parent[p2] = p1;
	else parent[p1] = p2;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//parent초기화
	for (int i = 1; i <= N; i++) parent[i] = i;

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		pq.push({ -C , {A,B} });
	}
	
	int answer = 0;
	int last_weight = 0;

	while (!pq.empty()) {
		int weight = -pq.top().first;
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		pq.pop();

		//cycle이면 pass
		if (find(n1) == find(n2)) continue;

		union_set(n1, n2);
		answer += weight;
		last_weight = weight;
	}

	//마지막으로 통합될때의 weight를 빼버리면 
	//두개 집합으로 될떄의 최소비용을 알수있다
	cout << answer - last_weight << "\n";
}
