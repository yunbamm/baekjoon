#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//네트워크 플로우 공부

//A->Z : 0 -> 25
//노드는 대문자 or 소문자
//간선이 양방향이다..
//0번부터 BFS를 통해 25로 가는 경로가 있는지 확인
//없다면 끝
//있다면 경로상에 최솟값 찾기
//경로상의 f를 update
//반복

//왜 역방향은 고려를 안하는지 모르겠다..

int N;
int c[52][52] = { 0 };
int f[52][52] = { 0 };
vector<vector<int>> v(52);		//인접한 간선을 가지고있는다
int answer = 0;

void Network() {

	//0 -> 25로 가는 경로를 못찾을때까지
	while (1) {

		queue<int> q;
		int pre[52];
		for (int i = 0; i < 52; i++) pre[i] = -1;

		//경로 찾기
		q.push(0);
		pre[0] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			//인접한 간선 확인
			for (int i = 0; i < v[now].size(); i++) {
				int next = v[now][i];

				//next로 갈수있는 유량 존재하고 들른적이 없는곳이면
				if (c[now][next] - f[now][next] > 0 && pre[next] == -1) {
					q.push(next);
					pre[next] = now;
				}
			}
		}


		//경로가 없으면 break
		if (pre[25] == -1) break;
		
		//경로가 있다면 해당 경로를 통해 흐를수있는 유량을 찾는다 (최솟값 찾기)
		int tmp = 25;
		int tmp_min = 987654321;
		while (tmp != 0) {
			tmp_min = min(tmp_min, c[pre[tmp]][tmp] - f[pre[tmp]][tmp]);
			tmp = pre[tmp];
		}

		//최솟값만큼 update (역방향도 해줘야한다!)
		tmp = 25;
		while (tmp != 0) {
			f[pre[tmp]][tmp] += tmp_min;
			tmp = pre[tmp];
		}

		//총 흐르는양 update
		answer += tmp_min;
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	char src, dest;
	int capacity;

	for (int n = 0; n < N; n++) {
		cin >> src >> dest >> capacity;

		int n1, n2;
		if ('A' <= src && src <= 'Z') n1 = src - 'A';
		else n1 = src - 'a' + 26;
		if ('A' <= dest && dest <= 'Z') n2 = dest - 'A';
		else n2 = dest - 'a' + 26;

		c[n1][n2] += capacity;
		c[n2][n1] += capacity;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}


	//네트워크플로우
	Network();

	cout << answer;
}



