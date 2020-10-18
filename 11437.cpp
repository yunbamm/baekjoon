#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//1~N
//root 1

int N, M;		//정점개수, 알고싶은 쌍
vector<int> edge[50001];	//간선
int parent[50001];			//index의 부모
bool check[50001];
int depth[50001];

void makeTree() {
	queue<int> q;
	q.push(1);
	check[1] = true;
	depth[1] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//연결된 정점을 확인
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];

			if (check[next]) continue;

			check[next] = true;
			q.push(next);
			parent[next] = now;
			depth[next] = depth[now] + 1;
		}
	}
}
int main() {
	
	cin >> N;
	int n1, n2;
	for (int i = 0; i < N - 1; i++) {
		cin >> n1 >> n2;
		edge[n1].push_back(n2);
		edge[n2].push_back(n1);
	}
	
	//parent초기화 
	for (int i = 1; i <= N; i++) parent[i] = i;
	//tree로 만들면서 parent , depth 정보 저장
	makeTree();

	
	//query부분
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		//n1과 n2의 높이를 우선 맞춘다
		while (depth[n1] != depth[n2]) {
			if (depth[n1] < depth[n2]) n2 = parent[n2];
			else n1 = parent[n1];
		}
		
		while (n1 != n2) {
			n1 = parent[n1];
			n2 = parent[n2];
		}
		cout << n1 << "\n";
	}
}
