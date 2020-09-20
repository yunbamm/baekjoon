#include<iostream>
#include<queue>

using namespace std;

//8*8
//맨위에것도 7번이면 다 내려온다

pair<int, int>p[9] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
bool map[8][8][9];			//8초후엔 모든게 빈칸이된다
bool arr[8][8][9];			

//map_update
void map_update() {

	//i초 뒤에 map
	for (int i = 1; i < 9; i++) {

		for (int x = 0; x < 8; x++) {
			for (int y = 0; y < 8; y++) {
				//8초후엔 벽이 있을수가없다
				if (i == 8) map[x][y][i] = true;
				//첫번째줄은 내려오는게 없으니까 무조건 빈칸
				else if (x == 0) map[x][y][i] = true;
				//나머지는 위에걸 가져온다
				else {
					map[x][y][i] = map[x - 1][y][i - 1];
				}
			}
		}
	}
}

void BFS() {
	queue<pair<int, pair<int,int>>> q;
	q.push({ 0,{7,0} });
	while (!q.empty()) {
		int t= q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;

		q.pop();

		for (int i = 0; i < 9; i++) {
			int newx = x + p[i].first;
			int newy = y + p[i].second;
			int newt = t + 1;

			//8초가 넘어가면 그냥 8초 map을 보면 된다
			if (newt >= 8) newt = 8;

			//유효하지않으면
			if (newx < 0 || newx > 7 || newy < 0 || newy > 7) continue;

			//현재시간에 벽이아니고 , 다음시간에 벽이아니면
			if (map[newx][newy][newt] && map[newx][newy][t]) {
				//갔다는 표시가 없었으면
				if (!arr[newx][newy][newt]) {
					arr[newx][newy][newt] = true;
					q.push({ newt , {newx,newy} });
				}
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//입력받기
	char flag;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			cin >> flag;
			if (flag == '#') map[x][y][0] = false;
			if (flag == '.') map[x][y][0] = true;
		}
	}
	map_update();

	BFS();

	if (arr[0][7][8]) cout << "1\n";
	else cout << "0\n";
}
