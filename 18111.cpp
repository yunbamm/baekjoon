#include<iostream>

using namespace std;

//땅고르기 작업
//N*M
//1.(i,j)가장위의 블록을 제거
//2. 인벤의 블록을 하나 꺼내 (i,j)가장 위에 둔다
//1번은 2초,2번은 1초

//땅높이는 256초과X

//!!!!!!!!!!!!!!!!!!process에서 해당 위치에서 인벤에 블록이 있는지 보는게 아니라 처리가 완료된후 block이 있는지 ㅐ봐야한다!!!!!!!!!

bool height[257];		//true면 해봐야한다
int N, M, B;
int arr[500][500];
int tmp[500][500];
int ans_time = 987654321;
int ans_height = 0;

//h로 다 맞추기
void process(int h) {

	//tmp=arr
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	int block = B;
	int tmp_time = 0;
	//h로 다 맞추자
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//h일때는 할필요가없다
			if (tmp[i][j] != h) {
				//h보다 클때 제거
				if (h < tmp[i][j]) {
					block += (tmp[i][j] - h);
					tmp_time += 2 * (tmp[i][j] - h);
				}
				//h보다 작을때
				else {
					block -= (h - tmp[i][j]);
					tmp_time += (h - tmp[i][j]);
				}
			}
		}
	}

	if (block >= 0) {
		if (tmp_time <= ans_time) {
			ans_time = tmp_time;
			ans_height = h;
		}
	}
}
int main() {
	//입력받기
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 257; i++) {
		process(i);
	}
	cout << ans_time << " " << ans_height << "\n";
}
