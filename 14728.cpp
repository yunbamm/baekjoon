#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DP?
//sort필요
vector<pair<int, int>> v;		//공부시간, 배점
int N, T;		//단원 수 , 시간
int arr[10001] = { 0 };		//그 시간에 얻을수있는 최대 배점
int tmp[10001] = { 0 };		//임시 배열

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;

	int study, score;
	for (int n = 0; n < N; n++) {
		cin >> study >> score;
		v.push_back({ study,score });
	}

	sort(v.begin(), v.end());


	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j <= T; j++) {
			if (arr[j] != 0 && j + v[i].first <= T) {
				tmp[j + v[i].first] = arr[j] + v[i].second;
			}
		}
		//arr update
		for (int j = 0; j <= T; j++) {
			if (tmp[j] != 0) {
				arr[j] = max(arr[j], tmp[j]);
				tmp[j] = 0;
			}
		}
		//현재 공부도 update
		arr[v[i].first] = max(arr[v[i].first], v[i].second);
	}

	int answer = 0;
	for (int i = 0; i <= T; i++) {
		answer = max(answer, arr[i]);
	}
	cout << answer;
}
