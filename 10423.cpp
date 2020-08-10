#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N;
vector<int> v;

//MST응용? (모든 정점이 다 연결될 필요가 없다)
//1. 발전소의 parent를 -1로 고정
//2. 크루스칼을 통해 연결하면서 parent를 두 값중 min값으로 update
//3. 크루스칼 돌면서 N개가 모두 parent가 -1이 되면 끝

int parent[1001];
int tmp = 0;

int find(int n) {
	if (parent[n] == n) return n;
	if (parent[n] == -1) return -1;

	return parent[n] = find(parent[n]);
}

void union_set(int n1, int n2) {


	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 < p2) {
		parent[p2] = p1;
		if (p1 == -1) tmp++;
	}
	else {
		parent[p1] = p2;
		if (p2 == -1) tmp++;
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;	//도시 개수 , 케이블 수 , 발전소 개수
	priority_queue<pair<int, pair<int, int>>> pq;		//비용, 두정점
	int n1, n2, weight;

	cin >> N >> M >> K;

	//parent 초기화
	for (int n = 1; n <= N; n++) {
		parent[n] = n;
	}
	for (int k = 0; k < K; k++) {
		cin >> n1;
		parent[n1] = -1;
	}

	
	for (int m = 0; m < M; m++) {
		cin >> n1 >> n2 >> weight;
		pq.push({ -weight,{n1,n2} });
	}

	

	int answer = 0;
	while (!pq.empty()) {
		int now_weight = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		//cycle을 만드는지 확인
		
		if (find(x) == find(y)) continue;

		union_set(x, y);
		answer += now_weight;

		if (tmp == N - K) break;
	}

	cout << answer;
}
