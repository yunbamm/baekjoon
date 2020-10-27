#include<iostream>
#include<queue>

using namespace std;

//컴퓨터-컴퓨터 모두 연결
//경로존재 -> 연결되어있다 
//최소비용 출력 
//모두연결못하는 경우는 없다 

//pq를 이용해서 비용이 적은 선들을 먼저 보면서 처리 (크루스칼)

int N, M;		//컴퓨터 수 , 선의 수
priority_queue < pair<int, pair<int, int>>> pq;			//-비용 , 컴퓨터2대
int parent[1001];
int answer = 0;

int find(int now) {
	if (now == parent[now]) return now;
	else return parent[now] = find(parent[now]);
}
void union_func(int p1 , int p2) {
	if (p1 < p2) parent[p2] = p1;
	else parent[p1] = p2;
}
int main() {
	cin >> N >> M;

	int com1, com2, cost;
	for (int m = 0; m < M; m++) {
		cin >> com1 >> com2 >> cost;
		pq.push({ -cost , {com1,com2} });
	}

	//parent초기화 
	for (int i = 1; i <= N; i++) parent[i] = i;

	while (!pq.empty()) {
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();

		//n1과 n2가 같은 집합인지 확인
		int p1 = find(n1);
		int p2 = find(n2);

		if (p1 == p2) continue;

		//같은 집합이 아니면 union
		union_func(p1, p2);
		answer += c;
	}

	cout << answer << "\n";
}
