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
	
	int num;
	vector<int> v;
	for (int i = 0; i < M; i++) {
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {

		for (int j = 0; j < v.size(); j++) {
			int now = v[j];
			if (i % now == 0) {
				answer += i;
				break;
			}
		}
	}

	cout << answer;
}
