#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define INF 987654321

//힌트를 너무 많이 봄
//u에 바로 위에서부터 왔을때를 저장
//l에 바로 직전수에서부터 왔을때를 저장 (직전수는 위에서 왔을때 , 왼쪽에서 왔을때 큰값을 취급)
//r도 마찬가지

//DP

int N, M;
int arr[1001][1001] = { 0 };
int answer[1001][1001] = { 0 };
int l[1001];
int r[1001];
int u[1001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
			//최소로 초기화
			answer[n][m] = -INF;
		}
	}
	//1,1부터 시작이니까
	answer[1][1] = arr[1][1];

	for (int n = 1; n <= N; n++) {
		//첫줄
		if (n == 1) {
			//왼쪽에서만 올수있음
			for (int m = 1; m <= M; m++) {
				answer[n][m] = max(answer[n][m], answer[n][m - 1] + arr[n][m]);
			}
		}
		//나머지(!!!!!!핵심!!!!!!!!!!!!!!)
		else {
			//위에서부터 내려왔을경우 (이미 위에는 answer이 결정됨)
			for (int m = 1; m <= M; m++) {
				u[m] = answer[n - 1][m] + arr[n][m];
			}
			//왼쪽에서부터 왔을때 (위에서 파생된 왼쪽 수와 왼쪽에서 파생된 왼쪽 수중에 큰수랑 더해준다)
			for (int m = 1; m <= M; m++) {
				//!!왼쪽 끝이면 없다...
				if (m == 1) l[m] = -INF;
				else l[m] = max(u[m - 1] , l[m-1]) + arr[n][m];
			}
			//오른쪽에서부터 왔을때(위에서 파생된 오른쪽 수와  오른쪽에서 파생된 오른쪽 수중에 큰수랑 더해준다)
			for (int m = M; m >= 1; m--) {
				//오른쪽 끝이면 값이 없다...
				if (m == M) r[m] = -INF;
				else r[m] = max(u[m + 1] , r[m+1]) + arr[n][m];
			}


			//이중에 최대값이 answer이 된다
			for (int m = 1; m <= M; m++) {
				answer[n][m] = max(u[m], max(l[m], r[m]));
			}
		}
	}

	cout << answer[N][M];
}

