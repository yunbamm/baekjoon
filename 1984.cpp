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

//다익스트라(보통과 다르게 젤 큰가중치를 찾는다)
//!!!!!!!!!!주의점은 q에 중복된 도시번호가 들어가면 안된다 (도시에서 도시로가는 도로가 하나가 아니기때문에)
	/*4 5
	1 2 4
	2 4 4
	1 3 2
	3 2 2
	2 4 4
	1 4*/		//이런 입력이 들어오면 틀린다
    
int N, M;		//도시 개수,도로 개수 
int S, D;		//시작점, 도착점
int dis[10001];		//시작점으로부터 거리
vector<pair<int,int>> load[10001];		//도착지 번호, 가중치
priority_queue<pair<int, int>> pq;		//가중치 합, 현재 도시번호
bool check[10001];

vector<int> pre[10001];

void Dijkstra() {

	while (!pq.empty()) {
		int sum = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		//보통 다익스트라와 다르게 작은값이 들어오면 무시
		if (sum < dis[now])	continue;


		for (int i = 0; i < load[now].size(); i++) {
			int next = load[now][i].first;
			int cost = load[now][i].second;

			//더큰값이 들어오면 pre를 초기화
			if (dis[next] < cost + sum) {

				pre[next].clear();
				pre[next].push_back(now);

				dis[next] = cost + sum;
				pq.push({ -(cost + sum) , next });
			}
			else if (dis[next] == cost + sum) {
				pre[next].push_back(now);
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	int src, dest, weight;
	for (int m = 0; m < M; m++) {
		cin >> src >> dest >> weight;
		load[src].push_back({ dest,weight });
	}

	cin >> S >> D;

	//dis초기화
	for (int i = 1; i <= N; i++) {
		dis[i] = 0;
	}
	pq.push({ 0,S });
	Dijkstra();

	int answer = 0;


	////pre확인 
	//for (int i = 1; i <= N; i++) {
	//	cout << i << " : ";

	//	for (int j = 0; j < pre[i].size(); j++) cout << pre[i][j] << " , ";

	//	cout << "\n";
	//}



	//도로추적 
	queue<int> q;
	q.push(D);
	check[D] = true;
	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < pre[next].size(); i++) {
			int now = pre[next][i];

			answer++;

			//아직 q에 들어간적이 없으면
			if (!check[now]) {
				check[now] = true;
				q.push(now);
			}
		}
	}
	cout << dis[D] << "\n";
	cout << answer;
}

