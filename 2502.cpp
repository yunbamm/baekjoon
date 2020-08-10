#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>

using namespace std;

//힐링

pair<int, int> p[31];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	p[1] = { 1,0 };
	p[2] = { 0,1 };

	int D, K;

	cin >> D >> K;
	for (int i = 3; i <= D; i++) {
		p[i].first = p[i - 1].first + p[i - 2].first;
		p[i].second = p[i - 1].second + p[i - 2].second;
	}


	int num1 = 1;
	while (1) {

		if ((K - num1 * p[D].first) % p[D].second == 0) {
			cout << num1 << "\n" << (K - num1 * p[D].first) / p[D].second;
			return 0;
		}
		num1++;
	}
}
