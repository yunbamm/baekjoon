#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//부분집합S에 속한 모든 정점쌍이 서로 인접하지 않으면 S = 독립집합
//크기 = 독립집합에 속한 정점들의 가중치 합
//output : 최대독립집합
//입력은 트리가 들어온다

/*변수*/
int N;
int weight[10001] = { 0 };
int DP[10001][2];			//0이 포함 , 1 미포함
bool check[10001];
vector<int> edge[10001];
vector<int> v;				//독립집합에 포함되는 정점

//현재 노드가 S에 포함이면 -> 인접한 노드들은 S포함 X
//현재 노드가 S에 포함 X -> 인접한 노드는 포함 or 포함 X 중 max값을 구하면 된다
void DFS(int now) {

	//위에해주는 이유 next에서 now로 edge가 있으니까
	check[now] = true;

	//자식을 본다
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];

		//이미 처리된 자식이면
		if (check[next]) continue;

		DFS(next);

		//포함이면 인접한 노드들은 미포함
		DP[now][0] += DP[next][1];
		//미포함이면 포함 or 미포함
		DP[now][1] += max(DP[next][0], DP[next][1]);
	}
}

//1. flag == 0 
//현재것이 포함되어야한다. next는 1 (미포함)
//2.flag == 1
//max값에 따라 결정 (0이더크면 trace(next,0) , 1이더크면 trace(next,1))
void trace(int now , int flag) {

	check[now] = true;

	//현재것 포함
	if (flag == 0) {
		v.push_back(now);
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];

			if (check[next]) continue;
			//다음건 무조건 미포함
			trace(next, 1);
		}
	}
	//현재것 미포함
	else if (flag == 1) {
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];

			if (check[next]) continue;
			//다음건 max값이 뭐인지에 따라 결정
			if (DP[next][0] >= DP[next][1]) {
				trace(next, 0);
			}
			else trace(next, 1);
		}
	}
}
int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> weight[i];

	//dp초기화 
	for (int i = 1; i <= N; i++) {
		DP[i][0] = weight[i];
		DP[i][1] = 0;
	}
	int n1, n2;
	for (int i = 0; i < N - 1; i++) {
		cin >> n1 >> n2;
		edge[n1].push_back(n2);
		edge[n2].push_back(n1);
	}

	DFS(1);

	//check초기화 
	for (int i = 1; i <= N; i++) check[i] = false;

	if (DP[1][0] >= DP[1][1]) trace(1, 0);
	else trace(1, 1);

	sort(v.begin(), v.end());

	cout << max(DP[1][0], DP[1][1]) << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
