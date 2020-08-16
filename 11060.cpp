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

//왼쪽끝 -> 오른쪽끝 (0 -> N-1)

int N;
int arr[1000];
int DP[1000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	//DPㅊ기화
	for (int i = 0; i < N; i++) DP[i] = INF;

	DP[0] = 0;

	//i번째를 들렸으면
	for (int i = 0; i < N; i++) {
		int tmp = arr[i];
        //i번째에서 한번에 갈수있는 좌표의 DP값을 update
		for (int j = i + 1; j <= i + tmp; j++) {
			DP[j] = min(DP[j], DP[i] + 1);
		}
	}

	
	if (DP[N - 1] >= INF) cout << "-1\n";
	else cout << DP[N - 1];
}



