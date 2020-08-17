#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

string A, B;
int DP[1001][1001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {

			if (A[i] == B[j]) {
				DP[i + 1][j + 1] = DP[i][j] + 1;
			}
			else {
				DP[i + 1][j + 1] = max(DP[i + 1][j], DP[i][j + 1]);
			}
		}
	}

	cout << DP[A.size()][B.size()];
}



