#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//n번째 행에 있는 k번째 수

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	//n-1 C k-1을 계산?
	
	if (K == 1) cout << "1\n";
	else {
		N--;
		K--;

		if (N / 2 < K) {
			K = N - K;
		}
		long long up = 1;
		int tmp = K;
		while (tmp--) {
			up *= N;
			N--;
		}
		long long down = 1;
		tmp = K;
		while (tmp--) {
			down *= K;
			K--;
		}
		cout << up / down;
	}
}
