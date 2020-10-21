#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;		//중요도, index
priority_queue<int> pq;			//중요도

int ans[100];

int solution(vector<int> priorities, int location) {

	for (int i = 0; i < priorities.size(); i++) {
		int now = priorities[i];
		q.push({ now, i });
		pq.push(now);
	}

	int tmp = 1;
	while (!pq.empty()) {
		int now = pq.top();		//현재 가장높은 중요도
		pq.pop();

		//q의 가장앞이 now랑 같을때까지
		while (q.front().first != now) {
			int tmp1 = q.front().first;
			int tmp2 = q.front().second;
			q.pop();
			q.push({ tmp1,tmp2 });
		}

		//q를 뺀다
		ans[q.front().second] = tmp;
		tmp++;
		q.pop();
	}
	int answer = ans[location];
	return answer;
}
