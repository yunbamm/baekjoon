#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


//힌트
//MST는 간선의 개수가 N-1개이다 
//입력은 연결그래프가 주어진다

int T;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		int n1, n2;
		for (int m = 0; m < M; m++) {
			cin >> n1 >> n2;
		}

		cout << N - 1 << "\n";
	}
	
}
