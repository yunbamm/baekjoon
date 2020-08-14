#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define INF 987654321

//혼자 못품
//다익스트라 

//1.최단값 찾으면서 최단거리를 가지는 도로를 저장해놓는다

int N, M;		//장소 수, 도로 수
int S, D;		//시작, 끝
vector<pair<int, int>> load[500];		//인접한 도로 , 가중치
vector<int> pre[500];					//최단도로 정보를 가진다
priority_queue<pair<int, int>> pq;		//가중치 합산 , 장소번호
bool check[500][500];					//true이면 최단도로이니까 무시해야한다

int dis[500];

void Dijkstra() {


	while (!pq.empty()) {
		int sum = -pq.top().first;
		int now = pq.top().second;

		pq.pop();


		//현재찾은경로보다 더 멀다면 무시
		if (dis[now] < sum) continue;

		//연결된 도로를 확인한다
		for (int i = 0; i < load[now].size(); i++) {
			int next = load[now][i].first;
			int cost = load[now][i].second;

			//최단도로면 무시해야된다
			if (check[now][next]) continue;

			//더 짧은 경로를 찾으면
			if (sum + cost < dis[next]) {
				dis[next] = sum + cost;
				pq.push({ -(sum + cost) , next });
				//최단도로에 포함
				pre[next].clear();
				pre[next].push_back(now);
			}
			//길이가 같은 경로를 찾으면 최단 도로에 껴준다
			else if (sum + cost == dis[next]) {
				pre[next].push_back(now);
			}

		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		cin >> N >> M;

		if (N == 0 && M == 0) break;
		cin >> S >> D;

		//dis초기화
		for (int i = 0; i < N; i++) {
			if (i == S) dis[i] = 0;
			else dis[i] = INF;
		}

		//도로 입력
		int src, dest, weight;
		for (int m = 0; m < M; m++) {
			cin >> src >> dest >> weight;
			load[src].push_back({ dest,weight });
		}

		//최단거리 , 최단 도로 구했다
		pq.push({ 0,S });
		Dijkstra();

		//최단도로 표시하는 과정
		queue<int> q;
		q.push(D);
		while (!q.empty()) {
			int now = q.front();
			q.pop();


			for (int i = 0; i < pre[now].size(); i++) {
				int next = pre[now][i];

				//최단도로임을 표시
				check[next][now] = true;
				q.push(next);
			}
		}

		//dist다시 초기화
		for (int i = 0; i < N; i++) {
			if (i == S) dis[i] = 0;
			else dis[i] = INF;
		}

		//다시 S에서 부터 다익스트라 시작
		pq.push({ 0,S });
		Dijkstra();


		if (dis[D] == INF) cout << "-1\n";
		else cout << dis[D] << "\n";


		//chekc load pre 초기화 
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = false;
			}
		}

		for (int i = 0; i < N; i++) {
			load[i].clear();
			pre[i].clear();
		}
	}
}

