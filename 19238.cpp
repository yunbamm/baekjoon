#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


//택시에서 가장 가까운 승객을 태운다 (여러명이면 행이 가장 작고 , 열이 가장 작은 승객) 이조건 중요!!
//한칸당 1을 소모
//목적지까지 가면 승객을 태우고 소모한 연료량의 두배가 충전된다

int N, M, fuel;		//N * N , 승객 수 , 초기 연료
int arr[21][21];		//1이면 못간다
int tmp[21][21];
bool person[401];			//i번째 승객을 태웠으면 true
pair<int, int> s[401];
pair<int, int> e[401];
pair<int, int> p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

pair<int, int> taxi;
queue<pair<int, int>> q;

bool finish = false;

//가장 가까운 승객 index를 return (-1이면 승객이 더이상없다)
int find_person() {
	//tmp초기화
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			tmp[x][y] = -1;
		}
	}
	//현재 택시 위치를 push
	q.push({ taxi.first, taxi.second });
	tmp[taxi.first][taxi.second] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//범위를 벗어나거나 , 벽이거나 , 이미 들른적이 있으면 무시
			if (newx <1 || newx > N || newy < 1 || newy > N) continue;
			if (arr[newx][newy] == 1) continue;
			if (tmp[newx][newy] != -1) continue;

			tmp[newx][newy] = tmp[x][y] + 1;
			q.push({ newx,newy });
		}
	}

	int distance = 987654321;
	int index = -1;

	for (int i = 1; i <= M; i++) {
		int p_x = s[i].first;
		int p_y = s[i].second;

		//이미 태운 손님이면 무시
		if (person[i]) continue;

		//더가까운 손님이 있으면
		if (distance > tmp[p_x][p_y]) {
			distance = tmp[p_x][p_y];
			index = i;
		}
		//거리가 같다면
		else if (distance == tmp[p_x][p_y]) {
			//행이 작거나 행이 같은데 열이 작을때
			if ((s[index].first > s[i].first) || (s[index].first == s[i].first && s[index].second > s[i].second)) {
				index = i;
			}
		}
	}
	return index;
}
//현재 승객위치에서 목적지까지
bool DEST_BFS(int p_index) {
	//tmp초기화
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			tmp[x][y] = -1;
		}
	}
	//현재 택시 위치를 push
	q.push({ taxi.first, taxi.second });
	tmp[taxi.first][taxi.second] = fuel;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//연료가 바닥났으면 무시
		if (tmp[x][y] == 0) continue;

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//범위를 벗어나거나 , 벽이거나 , 이미 들른적이 있으면 무시
			if (newx <1 || newx > N || newy < 1 || newy > N) continue;
			if (arr[newx][newy] == 1) continue;
			if (tmp[newx][newy] != -1) continue;

			tmp[newx][newy] = tmp[x][y] - 1;
			q.push({ newx,newy });
		}
	}
	//목적지까지 도착했으면
	if (tmp[e[p_index].first][e[p_index].second] != -1) {
		//연료보충
		fuel += (fuel - tmp[e[p_index].first][e[p_index].second]);
		//택시 위치 수정
		taxi.first = e[p_index].first;
		taxi.second = e[p_index].second;
		//승객을 태웠다고 표시
		person[p_index] = true;
		return true;
	}
	//목적지 도착 불가시
	else return false;
}
//현재 택시위치에서 승객위치까지
bool SRC_BFS() {
	//가장 가까운 승객을 찾는다
	int p_index = find_person();
	//다태워서 승객이 없으면
	if (p_index == -1) {
		finish = true;
		return false;
	}

	//tmp초기화
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			tmp[x][y] = -1;
		}
	}
	//현재 택시 위치를 push
	q.push({ taxi.first, taxi.second });
	tmp[taxi.first][taxi.second] = fuel;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//연료가 바닥났으면 무시
		if (tmp[x][y] == 0) continue;

		for (int i = 0; i < 4; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;

			//범위를 벗어나거나 , 벽이거나 , 이미 들른적이 있으면 무시
			if (newx <1 || newx > N || newy < 1 || newy > N) continue;
			if (arr[newx][newy] == 1) continue;
			if (tmp[newx][newy] != -1) continue;

			tmp[newx][newy] = tmp[x][y] - 1;
			q.push({ newx,newy });
		}
	}

	//승객을 태울수있으면
	if (tmp[s[p_index].first][s[p_index].second] != -1) {
		//택시위치수정
		taxi.first = s[p_index].first;
		taxi.second = s[p_index].second;
		fuel = tmp[s[p_index].first][s[p_index].second];
		return DEST_BFS(p_index);
	}
	//없으면
	else return false;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> fuel;

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> arr[x][y];
		}
	}
	
	cin >> taxi.first >> taxi.second;

	for (int m = 1; m <= M; m++) {
		cin >> s[m].first >> s[m].second;
		cin >> e[m].first >> e[m].second;
	}

	while (1) {
		bool flag = SRC_BFS();
		if (!flag) {
			//승객을 다 태웠으면
			if (finish) {
				cout << fuel;
				break;
			}
			else {
				cout << "-1\n";
				break;	
			}
		}
	}
}
