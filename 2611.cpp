#include<iostream>
#include <queue>
#include <stack>

using namespace std;

#define INF 987654321

//합계  , 장소
priority_queue<pair<int, int>> pq;
vector<pair<int,int>> v[1001];		//i에서 갈수있는 {지점 , 비용}
int N, M;		//지점 개수 , 도로개수
int p, q, r;
int answer[1001] = { 0 };
int pre[1001];

void Dijkstra() {
	
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int now = pq.top().second;
		int sum = pq.top().first;

		pq.pop();

		//만약 1로 돌아오면 무시
		if (now == 1 && sum != 0) continue;

		//더 작은값이 오면 무시
		if (sum < answer[now]) continue;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int cost = v[now][i].second;

			//만약 더큰 경로를 찾으면
			if (answer[next] < cost + sum) {
				pre[next] = now;
				answer[next] = cost + sum;
				pq.push({ cost + sum , next });
			}
		}
	
	}
	
}
int main() {

	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		cin >> p >> q >> r;		//p->q가 r이 든다
		v[p].push_back({ q,r });
	}
	

	Dijkstra();

	stack<int> s;
	int now = 1;
	while (1) {
		s.push(now);
		now = pre[now];
		if (now == 1) {
			s.push(now);
			break;
		}
	}

	cout << answer[1] << "\n";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

}
