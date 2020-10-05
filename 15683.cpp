#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//오른 위 왼 아래 순
//1~5번 감시카메라
//벽 통과 불가 (6)
//카메라 통과 가능

//예를 들어 (1,1) (2,2) 에 cctv가 있을때 (2,2) (1,1)을 중복해서 보는걸 없애고싶다?
//-> vector에 씨씨티비 좌표만 넣고 vector만 처리한다?

pair<int, int>p[4] = { {0,1},{-1,0},{0,-1},{1,0} };
int arr[8][8] = { 0 };
bool check[8][8] = { false };		//cctv인 부분 처리했는지
int N, M;		//세로 가로
int cctv_num = 0;
int answer = 987654321;
vector<pair<int, int>> cctv;

//x,y 기준으로 방향 dir
void cctv_process(int& x, int& y, int dir) {
	int tx = x;
	int ty = y;

	//유효하고 벽이아닌동안
	while ((0 <= tx && tx < N && 0 <= ty && ty < M) && (arr[tx][ty] != 6)) {

		//현재가 빈칸이면 갔다고 표시(7)
		if (arr[tx][ty] == 0) arr[tx][ty] = 7;

		tx += p[dir].first;
		ty += p[dir].second;
	}
}

//src = dest
void copy_map(int src[8][8], int dest[8][8]) {

	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			src[x][y] = dest[x][y];
		}
	}
}


//감시카메라를 만나면 모든 경우에 수를 해줘야한다
void DFS(int& index, int count) {

	if (count == cctv.size()) {
		//answer구하기
		int tmp_answer = 0;

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (arr[x][y] == 0) tmp_answer++;
			}
		}
		answer = min(answer, tmp_answer);
		return;
	}
	for (int j = index; j < cctv.size(); j++) {
		int x = cctv[j].first;
		int y = cctv[j].second;

		//처리한 카메라면 무시
		if (check[x][y]) continue;

		check[x][y] = true;
		//1이면 4가지
		if (arr[x][y] == 1) {
			for (int i = 0; i < 4; i++) {
				int tmp[8][8];
				//tmp에 arr복사
				copy_map(tmp, arr);

				//cctv_process를 해준다
				cctv_process(x, y, i);
				//DFS들어간다
				DFS(j , count + 1);
				//cctv_process를 취소해준다
				copy_map(arr, tmp);
			}
		}
		//2이면 2가지
		if (arr[x][y] == 2) {
			for (int i = 0; i < 2; i++) {
				int tmp[8][8];
				//tmp에 arr복사
				copy_map(tmp, arr);

				//cctv_process를 해준다
				cctv_process(x, y, i);
				cctv_process(x, y, i + 2);
				//DFS들어간다
				DFS(j , count + 1);
				//cctv_process를 취소해준다
				copy_map(arr, tmp);
			}
		}
		//3이면 4가지
		if (arr[x][y] == 3) {
			for (int i = 0; i < 4; i++) {
				int tmp[8][8];
				//tmp에 arr복사
				copy_map(tmp, arr);

				//cctv_process를 해준다
				cctv_process(x, y, i);
				cctv_process(x, y, (i + 1) % 4);
				//DFS들어간다
				DFS(j , count + 1);
				//cctv_process를 취소해준다
				copy_map(arr, tmp);
			}
		}
		//4이면 4가지
		if (arr[x][y] == 4) {
			for (int i = 0; i < 4; i++) {
				int tmp[8][8];
				//tmp에 arr복사
				copy_map(tmp, arr);

				//cctv_process를 해준다
				cctv_process(x, y, i);
				cctv_process(x, y, (i + 1) % 4);
				cctv_process(x, y, (i + 2) % 4);
				//DFS들어간다
				DFS(j , count + 1);
				//cctv_process를 취소해준다
				copy_map(arr, tmp);
			}
		}
		//5이면 1가지
		if (arr[x][y] == 5) {
			int tmp[8][8];
			//tmp에 arr복사
			copy_map(tmp, arr);

			//cctv_process를 해준다
			cctv_process(x, y, 0);
			cctv_process(x, y, 1);
			cctv_process(x, y, 2);
			cctv_process(x, y, 3);
			//DFS들어간다
			DFS(j , count + 1);
			//cctv_process를 취소해준다
			copy_map(arr, tmp);
		}

		//풀어줘야한다
		check[x][y] = false;
	}
}
int main() {

	cin >> N >> M;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> arr[x][y];
			if (1 <= arr[x][y] && arr[x][y] <= 5) {
				cctv.push_back({ x,y });
			}
		}
	}

	int s_index = 0;
	DFS(s_index ,0);

	cout << answer;
}
