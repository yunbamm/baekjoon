#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//총 개수 - 가장 긴 증가 수열

int N;
vector<pair<int, int>> v;
int DP[101];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	//DP초기화
	for (int i = 0; i < N; i++) DP[i] = 1;

	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int nowx = v[i].first;
		int nowy = v[i].second;
		
		for (int j = 0; j < i; j++) {
			int tmpx = v[j].first;
			int tmpy = v[j].second;

			if (tmpx < nowx && tmpy < nowy) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
			
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, DP[i]);
	}

	cout << N - answer;
}
