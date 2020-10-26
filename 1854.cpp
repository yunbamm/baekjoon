#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define INF 987654321

int N, M, K;		//도시개수 , 도로수, K번째
vector<pair<int, int>> edge[1001];		//dest, cost
priority_queue<pair<int, int>> pq;		//-sum , now
priority_queue<int> dist[1001];			//1->index까지 가는데 비용들을 가진다

//K번째 최단경로를 찾기 (src 1번)
void Dijkstra(int start) {
	pq.push({ 0,1 });
	dist[1].push(0);

	while (!pq.empty()) {
		int now = pq.top().second;
		int sum = -pq.top().first;
		pq.pop();

		//연결된 정점을 본다
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int cost = edge[now][i].second;

			//dist[next]의 사이즈가 k보다 작으면 무조건 push
			if (dist[next].size() < K) {
				dist[next].push(sum + cost);
				pq.push({ -(sum + cost) , next });
			}
			//크면 top과 비교후 더 작은값이 올때 push
			else {
				if (dist[next].top() > sum + cost) {
					dist[next].pop();
					dist[next].push({ sum + cost });
					pq.push({ -(sum + cost) , next });
				}
			}
		}
	}

	//1~N번까지 출력
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() < K) cout << "-1\n";
		else cout << dist[i].top() << "\n";
	}
}

int main() {
	cin >> N >> M >> K;

	int src, dest, cost;
	for (int i = 0; i < M; i++) {
		cin >> src >> dest >> cost;
		edge[src].push_back({ dest,cost });
	}

	Dijkstra(1);

}
