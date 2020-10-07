#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
	
int N;		//정정 개수
vector<int> edge[1000001];		//간선 정보
bool check[1000001];
int dp[1000001][2];				//[0] = O , [1] = X

//(1,0) , (1,1) 두 경우로
void dfs(int now) {

	check[now] = true;

	//자식을 본다
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];

		//친구가 이미 간적있으면 무시! (부모일 경우는 추가를 안해줘도 된다 -> 왜? 어차피 부모에서 나를 추가할거니까)
		if (check[next]) continue;
		
		dfs(next);
		//두가지경우
		//내가 얼리어답터면 친구들은 아무거나 상관 X
		dp[now][0] += min(dp[next][0], dp[next][1]);
		//내가 얼리어답터가 아니면 친구들은 얼리어답터
		dp[now][1] += dp[next][0];
	}
}
int main() {
	
	cin >> N;

	//dp초기화
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = 0;
	}
	//트리 간선은 N-1개
	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
	}

	dfs(1);

	int answer = min(dp[1][0], dp[1][1]);

	cout << answer;
}
