#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//N*M
//1~N행에는 적의 위치
//N+1행에는 성
//M개중 3명 궁수 배치
//궁수는 거리가 D이하인 가장가까운적 공격 , 여럿일경우 가장 왼쪽에있는 적
//공격받은 적은 제외,  공격이 끝난뒤 아래로 한칸씩 이동 
//N+1까지 내려오면 제외 
//모든칸에 적이 없으면 끝

int N, M, D;
int arr[17][17];		//격자판
int tmp[17][17];		//격자판
vector<pair<int,int>> v;			//궁수가 배치될 칸 (y,x)
vector<pair<int, int>> enemy;	//적의 위치 (y , x)로 해야 처리가 편하다
bool check[17];
bool attack[15 * 15];			//공격받을 적의 index
int answer = 0;

int find() {
	int re = 0;
	sort(enemy.begin(), enemy.end());

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].second;
		int y = v[i].first;

		//가장가까운적찾기
		int index = -1;
		int tmp = 987654321;
		for (int j = 0; j < enemy.size(); j++) {
			int nx = enemy[j].second;
			int ny = enemy[j].first;

			int dis = abs(x - nx) + abs(y - ny);

			//D이하이면서 가장가까운적
			if (dis <= D && tmp > dis) {
				index = j;
				tmp = dis;
			}
		}

		//가장가까운적 공격 표시 
		attack[index] = true;
	}

	//공격받을적 지워준다
	for (int i = 0; i < 15 * 15; i++) {
		if (attack[i]) {
			re++;
			attack[i] = false;
			int x = enemy[i].second;
			int y = enemy[i].first;
			tmp[x][y] = 0;
		}
	}

	return re;
}
void move() {
	for (int x = N; x >= 1; x--) {
		for (int y = 1; y <= M; y++) {
			if (x == 1) tmp[x][y] = 0;
			else tmp[x][y] = tmp[x - 1][y];
		}
	}
}

void make_enemy() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (tmp[x][y] == 1) enemy.push_back({ y,x });
		}
	}
}
//처리부분
void process() {
	int tmp_answer = 0;

	//tmp = arr
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			tmp[x][y] = arr[x][y];
		}
	}
	//모든칸에 적이 없을때까지 반복
	while (1) {

		//적을 enemy에 담는다
		make_enemy();
		//적이 없으면 끝
		if (enemy.empty()) break;
		//가장가까운거리적을 공격 , 없애준다
		tmp_answer += find();
		//한칸씩 내려오고
		move();
		//enemy초기화
		enemy.clear();
	}

	answer = max(answer, tmp_answer);
}
//M개중에 3칸선택해서 궁수 배치
void make(int index) {

	//3칸 선택했으면 process
	if (v.size() == 3) {
		process();
	}
	for (int i = index; i <= M; i++) {
		if (!check[i]) {
			v.push_back({ i,N + 1 });
			check[i] = true;
			make(i);
			check[i] = false;
			v.pop_back();
		}
	}
}
int main() {
	
	//입력
	cin >> N >> M >> D;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			cin >> arr[x][y];
		}
	}

	//궁수배치 
	make(0);

	cout << answer;
}
