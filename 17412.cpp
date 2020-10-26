#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//1->2로가는 서로다른경로를 최대한으로 찾고싶다
//한경로에 포함된길이 다른 경로에 포함되면 안된다 -> 간선의 유량을 1씩 늘리면 될듯 
//1~N
int N, P;			//도시개수, 단방향 길개수
int c[401][401] = { 0 };	//흐를수있는 유량
int f[401][401] = { 0 };	//흐르는 유량
int answer = 0;
vector<int> edge[401];

void network_flow() {

	while (1) {
		//경로를 알기위해 변수필요
		int prev[401];
		for (int i = 1; i <= N; i++) prev[i] = -1;

		queue<int> q;
		q.push(1);		//1번에서 출발

		//우선 경로가 존재하는지 찾는다
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			
			//2번이면 도착이니까 break;
			if (now == 2) break;
			//간선을 보자
			for (int i = 0; i < edge[now].size(); i++) {
				int next = edge[now][i];

				//next가 이미 prev가 있다면 볼필요X
				if (prev[next] != -1) continue;

				if (c[now][next] - f[now][next] > 0) {
					q.push(next);
					prev[next] = now;
				}
			}
		}

		//경로가 없다면 빠져나온다
		if (prev[2] == -1) break;
		//경로상의 존재하는간선들의 최소가능값을 찾는다
		int min_c = 987654321;
		for (int now = 2; now != 1; now = prev[now]) {
			int tmp = prev[now];		//전 노드
			min_c = min(min_c, c[tmp][now] - f[tmp][now]);
		}
		//최소값만큼 c를 update
		for (int now = 2; now != 1; now = prev[now]) {
			int tmp = prev[now];		//전 노드
			f[tmp][now] += min_c;
			f[now][tmp] -= min_c;		//역방향 추가
		}

		//가능한 경로의 경우의수 추가
		answer += min_c;
	}
}
int main() {
	cin >> N >> P;

	//c , f초기화 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			c[i][j] = 0;
			c[j][i] = 0;
			f[i][j] = 0;
			f[j][i] = 0;
		}
	}
	int src, dest;
	for (int i = 0; i < P; i++) {
		cin >> src >> dest;
		edge[src].push_back(dest);
		c[src][dest]++;

		//역방향 간선 추가
		edge[dest].push_back(src);
	}

	network_flow();
	cout << answer << "\n";
}
