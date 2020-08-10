#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//다익스트라? 플로이드?
//지헌 성하 위치는 고려X
//시간의 합 최소 , 지헌<= 성하 , 지헌이 시간이 가장 적은곳
	
#define INF 987654321

int V, M;	//장소후보 수 , 장소 연결하는 길의 수
int dis[101][101];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> V >> M;

	//dis초기화
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}

	

	int v1, v2, weight;
	for (int m = 0; m < M; m++) {
		cin >> v1 >> v2 >> weight;
		dis[v1][v2] = min(dis[v1][v2], weight);
		dis[v2][v1] = min(dis[v2][v1], weight);
	}

	//지헌위치 , 성하위치
	cin >> v1 >> v2;

	//i를 들렸을때
	for (int i = 1; i <= V; i++) {
		for (int x = 1; x <= V; x++) {
			for (int y = 1; y <= V; y++) {

				if (dis[x][y] > dis[x][i] + dis[i][y]) dis[x][y] = dis[x][i] + dis[i][y];
			}
		}
	}

	

	//v1이 지헌 , v2가 성하
	int sum = 987654321;

	//우선 최소 시간 찾기
	for (int i = 1; i <= V; i++) {
		if (i == v1 || i == v2) continue;
		sum = min(sum, dis[v1][i] + dis[v2][i]);
	}

	int time = 987654321;
	int answer = -1;
	for (int i = 1; i <= V; i++) {
		if (i == v1 || i == v2) continue;
		if (sum != dis[v1][i] + dis[v2][i]) continue;

		//최소인 애들중에서 
		//성하가 먼저 도착하면 짤
		if (dis[v1][i] > dis[v2][i]) continue;

		//지헌이 시간이 최소인애
		if (time > dis[v1][i]) {
			time = dis[v1][i];
			answer = i;
		}
	}

	cout << answer;
}
