#include<iostream>
#include<queue>

using namespace std;

#define INF 50000000000
//혼자 못풀었다

//K개의 도로를 포장하여 서울->포천 시간을 단축하려한다
//이미 있는 도로만 포장가능->포장하면 시간 0이된다
//서울:1 , 포천:N이다
//항상 1->N까지 도달가능하다
//도로는 양방향 도로

//본래 dist[]배열을 dist[][]로 만들어서 포장한 도로개수를 카운팅하면된다
//그냥 다익스트라인데 cnt가 하나 추가된 다익을 하면된다
//살짝 벽부수고 이동하기 느낌?

int N, M, K;		//도시수 , 도로수, 포장할 수
vector<pair<int,long long>> edge[10001];			//dest, cost
priority_queue < pair<long long, pair<int, int>>> pq;		//-sum , now , 지금까지 포장한 도로개수
long long dist[10001][21];
long long answer = 50000000000;

void Dijkstra() {

	//1번출발
	pq.push({ 0,{1,0} });
	dist[1][0] = 0;

	while (!pq.empty()) {
		int now = pq.top().second.first;
		int cnt = pq.top().second.second;
		long long sum = -pq.top().first;
		pq.pop();

		//현재찾은 경로보다 더 긴 경로면 무시
		if (dist[now][cnt] < sum) continue;

		//간선을 본다
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			long long cost = edge[now][i].second;

			//일단 포장 안했을때
			if (dist[next][cnt] > sum + cost) {
				dist[next][cnt] = sum + cost;
				pq.push({ -(sum + cost) , {next, cnt} });
			}
			//포장한다치면
			if (cnt + 1 <= K) {
				if (dist[next][cnt + 1] > sum) {
					dist[next][cnt + 1] = sum;
					pq.push({ -sum , {next,cnt + 1} });
				}
			}
		}
	}
}
int main() {
	cin >> N >> M >> K;
	int city1, city2;
	long long cost;
	for (int m = 0; m < M; m++) {
		cin >> city1 >> city2 >> cost;
		edge[city1].push_back({ city2 , cost });
		edge[city2].push_back({ city1 , cost });
	}

	//dist초기화 
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 20; j++) {
			dist[i][j] = INF;
		}
	}

	//다익 시작
	Dijkstra();

	//최소시간찾기
	for (int i = 0; i <= K; i++) {
		answer = min(answer, dist[N][i]);
	}
	cout << answer;
}
