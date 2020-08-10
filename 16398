#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//크루스칼?

int N;
long long answer = 0;
priority_queue<pair<int, pair<int, int>>> pq;		//-비용, 정점2개
int parent[1001];


int find(int num) {

	if (num == parent[num]) return num;
	
	return parent[num] = find(parent[num]);

}
void union_set(int par, int chi) {
	parent[find(chi)] = par;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	int cost;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost;
			if (i != j) {
				pq.push({ -cost,{i,j} });
			}
		}
	}

	//parent초기화(자기자신)
	for (int i = 1; i <= 1000; i++) parent[i] = i;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		//사이클을 만드는지 확인
		if (find(x) == find(y)) continue;

		//사이클이 아니면
		if (find(x) < find(y)) union_set(find(x), find(y));
		else union_set(find(y), find(x));
		answer += (-cost);
	}

	cout << answer;
}
