#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	


	//13 1
	//100 12 1

	int answer = 0;
	while (1) {
		if (N < M) {
			answer += N;
			break;
		}
		answer += N;
		N = N / M;
	}

	cout << answer;
}
