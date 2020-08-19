#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//union_find를 사용

int N, M;	//왕국의 수, 동맹 관계의 수
int parent[100001];		//i번째가 해당하는 집합의 리더
int C, H, K;		//CTP왕국번호 , 한솔왕국 번호 , 추가동맹기회
int amount[100001] = { 0 };		//i가 리더인 집합에 크기
priority_queue<pair<int, int>> pq;		//집합의 크기 , 리더 

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

	//parent초기화
	for (int i = 1; i <= N; i++) parent[i] = i;

	int X, Y;		//X와 Y가 동맹
	for (int m = 0; m < M; m++) {
		cin >> X >> Y;

		//같은 집합이면 무시
		if (find(X) == find(Y)) continue;

		union_set(X, Y);
	}
	
	cin >> C >> H >> K;

	//CTP를 제외한 가장 힘이 쎈 집합과 union하면 된다
	
	//find를 한번씩 더해줘서 확실히 최종 부모를 가지게 해준다!!!!
	for (int i = 1; i <= N; i++) {
		find(i);
	}

	//우선 집합들의 크기를 알아본다
	for (int i = 1; i <= N; i++) {
		amount[parent[i]]++;
	}

	//CTP의 집합 리더
	int CTP_parent = find(C);
	int H_parent = find(H);

	//pq에 push
	for (int i = 1; i <= N; i++) {
		//동맹국이 없거나 , CTP동맹국이거나  , 한솔 동맹국이면 무시
		if (amount[i] == 0 || i == CTP_parent || i == H_parent) continue;
		else pq.push({ amount[i] , i });
	}

	int answer = amount[CTP_parent];


	while (!pq.empty()) {
		int tmp = pq.top().first;
		pq.pop();

		if (K == 0) break;
		answer += tmp;
		K--;
	}

	cout << answer;

}
