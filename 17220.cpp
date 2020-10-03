#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//위상정렬로 착각할 여지가 있는거같다

int N, M, K;		//마약 공급책 수  , 관계 수	, 경찰이 아는 공급책수 
bool flag[26] = { false };	//true면 경찰이 아는 공급책
int degree[26] = { 0 };		//나의 마약 공급책 수
bool answer[26] = { false };
bool root[26] = { false };		//원산지
vector<int> v[26];			//내가 공급해주는 노드
queue<int> q;

int main() {
	
	cin >> N >> M;

	char pre, post;

	//관계입력처리
	for (int m = 0; m < M; m++) {
		cin >> pre >> post;
		degree[post - 'A']++;
		v[pre - 'A'].push_back(post - 'A');
	}

	//경찰이 아는 공급책
	cin >> K;
	char node;
	for (int k = 0; k < K; k++) {
		cin >> node;
		flag[node - 'A'] = true;
	}

	//0인걸 q에 넣는다 (원산지 체크)
	for (int i = 0; i < N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			root[i] = true;
			answer[i] = true;
		}
	}


	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		//경찰이 아는 공급책이면 무시
		if (flag[now]) continue;

		//공급받는애들 처리
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			//아직확인이 안되었고 , 경찰이 모르는 공급책이면
			if (!answer[next] && !flag[next]) {
				answer[next] = true;
				q.push(next);
			}
		}
	}

	int real_ans = 0;
	for (int i = 0; i < N; i++) {
		//마약을 공급받을수있고 원산지가 아니면
		if (answer[i] && !root[i]) {
			//cout << char(i + 'A') << "\n";
			real_ans++;
		}
	}
	cout << real_ans;
}
