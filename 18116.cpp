#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//union-find?

#define INF 1000000

int parent[INF + 1];
int answer[INF + 1];
int N;

int find(int N) {
	if (parent[N] == N) return N;

	return parent[N] = find(parent[N]);
}

void union_set(int n1, int n2) {

	int p1 = find(n1);
	int p2 = find(n2);

	//작은쪽으로 union
	if (p1 < p2) {
		parent[p2] = p1;
		answer[p1] += answer[p2];
	}
	else {
		parent[p1] = p2;
		answer[p2] += answer[p1];
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;


	//parent와 answer 초기화 
	for (int i = 1; i <= INF; i++) {
		parent[i] = i;
		answer[i] = 1;
	}

	char c;
	int n1, n2;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'I') {
			cin >> n1 >> n2;

			//같은 set이면 pass
			if (find(n1) == find(n2)) continue;

			union_set(n1, n2);
		}

		if (c == 'Q') {
			cin >> n1;
			cout << answer[find(n1)] << "\n";
		}
	}
	
}
