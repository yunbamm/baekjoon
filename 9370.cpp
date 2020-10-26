#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define INF 987654321

//도로는 양방향
//목적지 후보중 불가능한 경우를 제외하고 오름차순으로 출력
//정점사이의 도로는 1개이다


//S-K : S-G + G-H + H-K
//S-K : S-H + H-G + G-K
//왜? G-H도로는 무조건지났다. 그니까 S-G,G-H,H-K == S-K이면 목적지 유효!

int T, N, M, K;		//테스트케이스  , 정점수 , 도로수 , 목적지 후보 개수
int s, g, h;		//출발지 , g-h도로를 지나갔다
vector<pair<int, int>> edge[2001];
vector<int> v;
int dist[2001][2001];

//시작점, 간선 , 후보지
void Dijkstra(int start) {
	priority_queue<pair<int, int>> pq;		//-sum , now
	
	pq.push({ 0,start });

	while (!pq.empty()) {
		int sum = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		//현재 알고있는 경로보다 큰 경로가 오면 무시
		if (dist[start][now] < sum) continue;

		//연결된 간선을 본다
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int cost = edge[now][i].second;

			//만약 next로 가는 최단경로를 갱신하면
			if (dist[start][next] > sum + cost) {
				dist[start][next] = sum + cost;
				pq.push({ -(sum + cost) , next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		cin >> s >> g >> h;
		int src, dest, cost;
		//초기화
		v.clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) dist[i][j] = 0;
				else dist[i][j] = INF;
			}
		}
		for (int i = 1; i <= N; i++) edge[i].clear();

		for (int m = 0; m < M; m++) {
			cin >> src >> dest >> cost;
			edge[src].push_back({ dest,cost });
			edge[dest].push_back({ src,cost });
		}
		int n1;
		for (int k = 0; k < K; k++) {
			cin >> n1;
			v.push_back(n1);
		}
		//다익실행(s,g,h)
		Dijkstra(s);
		Dijkstra(g);
		Dijkstra(h);

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			int tmp = v[i];			//도착점
			if (dist[s][tmp] == dist[s][g] + dist[g][h] + dist[h][tmp]) cout << tmp << " ";
			if (dist[s][tmp] == dist[s][h] + dist[h][g] + dist[g][tmp]) cout << tmp << " ";
		}
		cout << "\n";
	}
}
