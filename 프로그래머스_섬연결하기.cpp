#include <string>
#include <vector>
#include<queue>
#include<iostream>

using namespace std;

//n개 섬 사이에 다리 건설하는 비용 (cost)
//최소비용으로 모든섬이 통행가능하게 만들자
//n: 1~100
//cost: (n-1)*n / 2
//costs에는 [0].[1]에 섬의 번호 , [2]에 cost

//MST
//간선을 처리할때 사이클을 이루는지 확인하면 된다

int parent[101];			//집합의정보를 알수있다 (가장 번호가 작은애를 parent로)
priority_queue<pair<int, pair<int, int>>> pq;			//cost, 정점번호

int find(int now) {
	//현재값이 parent면 return
	if (now == parent[now]) return now;
	//아니면 
	
	return parent[now] = find(parent[now]);
}

//더작은 값으로 union시켜준다
void union_func(int n1,int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 < p2) parent[p2] = p1;
	else parent[p1] = p2;
}
int solution(int n, vector<vector<int>> costs) {
	
	//parent초기화 
	for (int i = 0; i < n; i++) parent[i] = i;

	//cost정보 pq에 넣는다
	for (int i = 0; i < costs.size(); i++) {
		int n1 = costs[i][0];
		int n2 = costs[i][1];
		int c = costs[i][2];
		pq.push({ -c,{n1,n2} });
	}

	int answer = 0;
	//간선을 하나씩 꺼내면서 본다
	while (!pq.empty()) {
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();

		
		//현재 두개가 같은정점이면 무시
		if (find(n1) == find(n2)) continue;

		//union!
		union_func(n1, n2);
		answer += c;
	}
	return answer;
}
