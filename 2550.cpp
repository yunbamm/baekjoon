#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N;
int num[10001];		//해당 index번째의 스위치번호
int src[10001];		//해당 스위치 번호의 start 위치

int dest[10001];	//i번째 스위치의 end위치
int end_num[10001];		//end에서 해당 index의 스위치번호

int pre[10001] = { 0 };

vector<int> v;
priority_queue<int> answer;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tmp;

	cin >> N;

	//src
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		num[i] = tmp;
		src[tmp] = i;
	}

	//dest
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		end_num[i] = tmp;
		dest[src[tmp]] = i;
	}


	//최장증가수열 찾기
	vector<int>::iterator iter;
	for (int i = 1; i <= N; i++) {
		tmp = dest[i];

		//v가 비었을때
		if (v.empty()) {
			v.push_back(tmp);
			pre[tmp] = 0;
		}
		//아닐때
		else {
			//맨뒤의 값보다 크다면 그냥 푸시
			if (v.back() < tmp) {
				pre[tmp] = v.back();
				v.push_back(tmp);
			}
			//아니면 적절한 위치를 찾아서 푸시
			else {
				iter = lower_bound(v.begin(), v.end(), tmp);
				v[iter - v.begin()] = tmp;

				if (iter - v.begin() == 0) {
					pre[tmp] = 0;
				}
				else {
					pre[tmp] = v[iter - v.begin() - 1];
				}
			}
		}
	}


	int now = v.back();

	while (now != 0) {
		answer.push(-end_num[now]);
		now = pre[now];
	}
	
	cout << answer.size() << "\n";
	while (!answer.empty()) {
		cout << -answer.top() << " ";
		answer.pop();
	}

}

