#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define INF 987654321

//A->B 최소비용 , 경로 추적 (무조건 경로가 존재한다는 가정)
int N, M;		//도시개수 , 경로개수
priority_queue<pair<int, int>> pq;			//-cost합산 , 현재지점
vector<pair<int, int>> edge[1001];			//dest , cost
int dist[1001];
int pre[1001];

void Dijkstra(int start, int end) {
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int sum = -pq.top().first;
		pq.pop();

		//현재찾은cost보다 더 큰 cost의 경로면 무시
		if (dist[now] < sum) continue;

		//연결된 간선들을 본다
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int cost = edge[now][i].second;

			//더작은걸 찾으면
			if (dist[next] > sum + cost) {
				dist[next] = sum + cost;
				pq.push({ -(sum + cost) , next });
				pre[next] = now;
			}
		}
	}

	cout << dist[end] << "\n";

	stack<int> s;
	for (int now = end; now != -1; now = pre[now]) {
		s.push(now);
	}

	cout << s.size() << "\n";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
int main() {
	cin >> N >> M;
	int src, dest, cost;
	for (int m = 0; m < M; m++) {
		cin >> src >> dest >> cost;
		edge[src].push_back({ dest,cost });
	}

	//dist 초기화 
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		pre[i] = -1;
	}
	cin >> src >> dest;
	Dijkstra(src, dest);

}
