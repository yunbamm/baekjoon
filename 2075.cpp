#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int N;
priority_queue<int> pq;		//작은거부터 가진다

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;

			//vsize 가 N보다 작으면
			if (pq.size() < N) {
				pq.push(-tmp);
			}
			//젤작은거 하나를 뺴고 찾아야함
			else {
				if (-pq.top() < tmp) {
					pq.pop();
					pq.push(-tmp);
				}
			}
		}
	}

	cout << -pq.top() << "\n";
}
