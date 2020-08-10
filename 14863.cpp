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
int N, K;		//도시 개수 , 제한시간
pair<int, int> road[100];
pair<int, int> bicycle[100];

int answer[100001] = { 0 };
int tmp[100001] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int n = 0; n < N; n++) {
		cin >> road[n].first >> road[n].second;
		cin >> bicycle[n].first >> bicycle[n].second;
	}


	for (int n = 0; n < N; n++) {
		int tmp_time = road[n].first;
		int tmp_monery = road[n].second;
		
		if (n == 0) {
			answer[tmp_time] = tmp_monery;
		}
		else {
			for (int k = 0; k <= K; k++) {
				if (answer[k] != 0 && k + tmp_time <= K) {
					tmp[k + tmp_time] = max(tmp[k + tmp_time], answer[k] + tmp_monery);
				}
			}
		}
		
		tmp_time = bicycle[n].first;
		tmp_monery = bicycle[n].second;

		if (n == 0) {
			answer[tmp_time] = max(answer[tmp_time], tmp_monery);
		}
		else {
			for (int k = 0; k <= K; k++) {
				if (answer[k] != 0 && k + tmp_time <= K) {
					tmp[k + tmp_time] = max(tmp[k + tmp_time], answer[k] + tmp_monery);
				}
			}
		}
		

		if (n != 0) {
			//tmp에 있는거 복사
			for (int k = 0; k <= K; k++) {
				if (tmp[k] != 0) {
					answer[k] = tmp[k];
					tmp[k] = 0;
					//cout << " ( " << k <<" , "<< answer[k] << " ) ";
				}
				else answer[k] = 0;
			}
			//cout << "\n";
		}
	}

	int tmp = 0;
	for (int k = 0; k <= K; k++) {
		tmp = max(tmp, answer[k]);
	}
	cout << tmp;
}
