#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//남초 , 여초 대학을 연결하는 도로로만
//어떤 대학교에서든 모든 대학교로 이동 가능하다
//최단거리가 되어야한다

int N, M;		//학교 수, 도로 개수
char arr[1001];
int parent[1001];

priority_queue<pair<int, pair<int, int>>> pq;		//-가중치 , 두 대학교

int find(int N) {
	if (N == parent[N]) return N;
	return parent[N] = find(parent[N]);
}

void union_set(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 < p2) parent[p2] = p1;
	else parent[p1] = p2;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//여초인지 , 남초인지 입력
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//parent 자기자신으로 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	//도로 정보 입력
	int n1, n2, weight;
	for (int i = 1; i <= M; i++) {
		cin >> n1 >> n2 >> weight;
		if (arr[n1] == 'W' && arr[n2] == 'M') {
			pq.push({ -weight,{n1,n2} });
		}
		if (arr[n1] == 'M' && arr[n2] == 'W') {
			pq.push({ -weight,{n1,n2} });
		}
	}

	int answer = 0;
	int tmp_m = 0;
	while (!pq.empty()) {
		int n1 = pq.top().second.first;
		int n2 = pq.top().second.second;
		int weight = -pq.top().first;
		pq.pop();

		//같은 집합이면 무시
		if (find(n1) == find(n2)) continue;
		
		answer += weight;
		tmp_m++;
		union_set(n1, n2);
	}
	
	//간선 개수가 N-1이면
	if (tmp_m == N - 1) cout << answer;
	else cout << "-1\n";

}
