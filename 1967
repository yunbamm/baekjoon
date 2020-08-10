#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//어렵다
//dfs두번 이용
//!!!!!!!!!!!원의 성질을 이용 (어떤 정점에서 가장 먼 정점이 지름을 결정하는 두 정점주 하나)
//그 정점에서 다시 가장 먼 정점을 구한다 (요게 지름)
//루트는 항상 1 
//부모 , 자식 , 가중치 순으로 입력
//부모번호가 작은거부터 입력이 들어온다

vector<vector<pair<int,int>>> v(10001);		//자식, 가중치
int distacnce[10001] = { 0 };
bool check[10001];

void DFS(int vertex , int sum) {
	//현재까지 거리 update
	distacnce[vertex] = sum;

	for (int i = 0; i < v[vertex].size(); i++) {
		int next = v[vertex][i].first;
		if (!check[next]) {
			check[next] = true;
			DFS(next, sum + v[vertex][i].second);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	

	int par, chi, weight;
	for (int i = 0; i < N - 1; i++) {
		cin >> par >> chi >> weight;
		v[par].push_back({ chi,weight });
		v[chi].push_back({ par,weight });
	}

	DFS(1, 0);

	int max_distance = 0;
	int vertex1 = 1;
	for (int i = 1; i <= N; i++) {
		if (max_distance < distacnce[i]) {
			max_distance = distacnce[i];
			vertex1 = i;
		}
	}

	//check초기화
	for (int i = 0; i <= 10000; i++) check[i] = false;
	//vertex1에서 가장 먼 거리 찾으면 그게 지름
	DFS(vertex1, 0);


	max_distance = 0;
	for (int i = 1; i <= N; i++) {
		max_distance = max(max_distance, distacnce[i]);
	}

	cout << max_distance;
}
