#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//0번주사위부터 순서대로 쌓는다

int up[6] = { 5,3,4,1,2,0 };		//i가 밑면일때 윗면이 되는 index
int N;
int arr[10000][6];
bool check[10000][6];
int answer = 0;
//밑면이 되는 index , 층수
void DFS(int down_index , int floor) {
	int up_index = up[down_index];
	int up_num = arr[floor][up_index];

	//마지막층이면 끝
	if (floor + 1 == N) {
		int tmp = 0;
		for (int n = 0; n < N; n++) {
			int max_num = 0;
			for (int i = 0; i < 6; i++) {
				if (!check[n][i]) max_num = max(max_num, arr[n][i]);
			}
			tmp += max_num;
		}
		answer = max(answer, tmp);
		return;
	}
	//다음층에 밑면이될수있는게 있다면
	for (int i = 0; i < 6; i++) {
		if (arr[floor + 1][i] == up_num) {
			check[floor + 1][i] = true;
			check[floor + 1][up[i]] = true;
			DFS(i, floor + 1);
			check[floor + 1][up[i]] = false;
			check[floor + 1][i] = false;
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 6; i++) {
			cin >> arr[n][i];
		}
	}

	//i번이 밑면이될때
	for (int i = 0; i < 6; i++) {
		check[0][i] = true;
		check[0][up[i]] = true;
		DFS(i, 0);
		check[0][i] = false;
		check[0][up[i]] = false;
	}

	cout << answer;
}
