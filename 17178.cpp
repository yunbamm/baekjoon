#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//줄을 queue로 대기공간을 stack으로 관리
//queue의 맨앞과 stack의 top을 보고 그사람 차례면 입장
//아니면 queue의 맨앞을 stack에 push후 다시본다
//만약 다 하고나서 queue , stack이 비어있으면 good 아니면 bad
//해당차례를 찾는게 핵심?

priority_queue<pair<int, int>> pq;		//순서대로 저장됨
queue<pair<int, int>> q;
stack<pair<int, int>> s;
int main() {

	int N;
	cin >> N;

	char c, tmp;
	int num;
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 5; i++) {
			cin >> c >> tmp;
			cin >> num;
			pq.push({ -(int)c,-num });
			q.push({ c,num });
		}
	}

	while (1) {
		int now_alpha = -pq.top().first;
		int now_num = -pq.top().second;

		//우선 스택을 본다
		//대기공간에 있는사람 차례라면
		if (!s.empty() && (s.top().first == now_alpha && s.top().second == now_num)) {
			s.pop();
			pq.pop();
			if (pq.empty()) {
				cout << "GOOD\n";
				break;
			}
			now_alpha = -pq.top().first;
			now_alpha = -pq.top().second;
		}
		//??
		else {
			if (q.empty()) {
				cout << "BAD\n";
				break;
			}
			if (q.front().first == now_alpha && q.front().second == now_num) {
				q.pop();
				pq.pop();
				if (pq.empty()) {
					cout << "GOOD\n";
					break;
				}
				now_alpha = -pq.top().first;
				now_alpha = -pq.top().second;
			}
			else {
				s.push({ q.front().first , q.front().second });
				q.pop();
			}
		}

		if (q.empty()) {
			//둘다 비면 GOOD
			if (s.empty()) {
				cout << "GOOD\n";
				break;
			}
		}
	}
}
