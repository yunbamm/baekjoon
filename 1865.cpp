#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 987654321

//플로이드 와샬 두번해서 거리가 줄어드는 곳이 있는지 확인
//밸만포드 연습!

int N, M, W;		//지점수 , 도로수 ,웜홀수
int T;				//테이스케이스 수
vector<pair<int, pair<int, int>>> edge;		//cost , src , dest
int dist[501];

bool Bellman_Ford(int start) {

	bool flag = false;		//음수사이클 존재여부

	//dist를 초기화
	for (int i = 1; i <= N; i++) {
		if (i == start) dist[i] = 0;
		else dist[i] = INF;
	}

	//N-1번 반복해서 간선들을 보면서 dist update
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int src = edge[j].second.first;
			int dest = edge[j].second.second;
			int cost = edge[j].first;

			//최단경로에 해당하는 간선으로 update
			if (dist[dest] > dist[src] + cost) dist[dest] = dist[src] + cost;

		}
	}
	//최단경로를 찾았는데 또 최단경로가 발견되면 이건 음의 사이클이 있는거다
	//간선을 보면서 dist[dest] > dist[src] + cost 인걸 발견하면 음의 사이클이 존재하는거다
	for (int i = 0; i < edge.size(); i++) {
		int src = edge[i].second.first;
		int dest = edge[i].second.second;
		int cost = edge[i].first;

		if (dist[dest] > dist[src] + cost) {
			flag = true;
			break;
		}
	}
	return flag;
}
int main() {
	
	cin >> T;
	while (T--) {
		cin >> N >> M >> W;
	
		//양방향도로
		int src, dest,cost;
		for (int m = 0; m < M; m++) {
			cin >> src >> dest>>cost;
			edge.push_back({ cost , {src,dest} });
			edge.push_back({ cost , {dest,src} });
		}
		//웜홀
		for (int w = 0; w < W; w++) {
			cin >> src >> dest >> cost;
			edge.push_back({ -cost , {src,dest} });
		}

		if (Bellman_Ford(1)) {
			cout << "YES\n";
		}
		else cout << "NO\n";

		//edge초기화
		edge.clear();
	}

}
