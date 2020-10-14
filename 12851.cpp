#include<iostream>
#include<queue>

using namespace std;

#define INF 987654321

int N, K;		//수빈이 위치 , 동생 위치

int time[100001] = { 0 };			//좌표에 가는데 걸리는 최단시간
int answer[100001] = { 0 };			//시간에 따른 방법 수

//x-1 or x+1 or 2 * x
void BFS() {
	queue<pair<int, int>> q;
	q.push({ N,0 });			//좌표 , 시간
	time[N] = 0;

	while (!q.empty()) {
		int now = q.front().first;
		int c = q.front().second;
		q.pop();
		
		//현재 c가 최단이 아니면 무시
		if (c > time[now]) continue;

		//now가 K일때
		if (now == K) {
			answer[c]++;
		}
		//x-1
		if (0 <= now - 1) {
			//더 최단을 찾으면
			if (time[now - 1] >= c + 1) {
				time[now - 1] = c + 1;
				q.push({ now - 1 , c + 1 });
			}
		}
		//x+1
		if (now  + 1 <= 100000 ) {
			if (time[now + 1] >= c + 1) {
				time[now + 1] = c + 1;
				q.push({ now + 1 , c + 1 });
			}
		}
		//2*now
		if (2 * now <= 100000 ) {
			if (time[2 * now] >= c + 1) {
				time[2 * now] = c + 1;
				q.push({ 2 * now , c + 1 });
			}
		}
		
	}
}
int main() {

	cin >> N >> K;

	//time초기화
	for (int i = 0; i <= 100000; i++) time[i] = INF;
	BFS();

	cout << time[K] << "\n";
	cout << answer[time[K]] << "\n";
}
