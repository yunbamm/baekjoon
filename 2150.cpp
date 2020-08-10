#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//SCC
//DFS 두번

int V, E;		//정점개수 , 간선개수

vector<vector<int>> edge(10001);
vector<vector<int>> flip_edge(10001);
vector<vector<int>> answer(10001);

bool check[10001];
stack<int> s;

bool check2[10001];
int SCC[10001] = { 0 };
priority_queue<int> pq;

void DFS(int n) {

	for (int i = 0; i < edge[n].size(); i++) {
		int next = edge[n][i];
		if (!check[next]) {
			check[next] = true;
			DFS(next);
		}
	}

	s.push(n);
}

void find_SCC(int leader , int n) {


	for (int i = 0; i < flip_edge[n].size(); i++) {
		int next = flip_edge[n][i];
		if (SCC[next] == 0) {
			//cout << n << " , " << next << "\n";
			SCC[next] = leader;
			find_SCC(leader , next);
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	//입력받기
	int A, B;
	for (int e = 0; e < E; e++) {
		cin >> A >> B;
		edge[A].push_back(B);
		flip_edge[B].push_back(A);
	}

	//1번 DFS는 stack을 만들기위해서
	for (int i = 1; i <= V; i++ ) {
		if (!check[i]) {
			check[i] = true;
			DFS(i);
		}
	}

	int SCC_num = 0;

	//2번 DFS는 SCC를 찾기위해
	while (!s.empty()) {
		int now = s.top();
		s.pop();

		if (SCC[now] == 0) {
			SCC_num++;
			pq.push(-now);
			SCC[now] = now;
			find_SCC(now, now);
		}
	}

	cout << SCC_num << "\n";
	//이거 처리하느라 삽질
	for (int i = 1; i <= V; i++) {
		int now_leader = SCC[i];

		if (!check2[now_leader]) {
			check2[now_leader] = true;

			for (int j = 1; j <= V; j++) {
				if (SCC[j] == now_leader) cout << j << " ";
			}
			cout << "-1\n";
		}
	}
	
}
