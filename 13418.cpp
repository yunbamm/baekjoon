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
int N, M;		//건물개수 , 도로개수
priority_queue<pair<int, pair<int, int>>> max_pq;		//오르막(0) , 두 건물번호
priority_queue<pair<int, pair<int, int>>> min_pq;		//내리막(1) , 두 건물번호
int parent[1001];
int max_answer = 0;
int min_answer = 0;

//parent찾기(같은 집합인지 판별) , cycle판별
int find(int N) {
	if (parent[N] == N) return N;
	
	return parent[N] = find(parent[N]);
}

//집합 합치기
void union_set(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 < p2) {
		parent[p2] = p1;
	}
	else parent[p1] = p2;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//parent초기화
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	int A, B , C;
	//입구랑 1번연결까지 포함해서 +1
	for (int i = 0; i < M + 1; i++) {
		cin >> A >> B >> C;
		max_pq.push({  -C,{A,B} });
		min_pq.push({ C,{A,B} });
	}

	
	while (!max_pq.empty()) {
		int n1 = max_pq.top().second.first;
		int n2 = max_pq.top().second.second;
		int tmp = -max_pq.top().first;
		max_pq.pop();


		//같은 집합이면 무시
		if (find(n1) == find(n2)) continue;

		//아니면 union
		union_set(n1, n2);
		if (tmp == 0) max_answer++;
	}

	//parent초기화
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	while (!min_pq.empty()) {
		int n1 = min_pq.top().second.first;
		int n2 = min_pq.top().second.second;
		int tmp = min_pq.top().first;
		min_pq.pop();


		//같은 집합이면 무시
		if (find(n1) == find(n2)) continue;

		//아니면 union
		union_set(n1, n2);
		if (tmp == 0) min_answer++;
	}

	int answer = (max_answer * max_answer) - (min_answer * min_answer);
	cout<<answer;
}
