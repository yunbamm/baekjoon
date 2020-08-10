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
vector<int> v;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, C;
	cin >> N >> C;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	int answer = 0;
	for (int i = 1; i <= C; i++) {

		for (int j = 0; j < v.size(); j++) {
			int now = v[j];
			if (i %now == 0) {
				answer++;
				break;
			}
		}
	}

	cout << answer;
}
