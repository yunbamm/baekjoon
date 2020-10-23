#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//에너지 구술 하나를 고른다 (첫번째 , 마지막은 못고른다)
//x 구술 제거 -> [x-1] * [x+1]에너지를 모을수있다
//N을 1 감소 , 1~N까지 다시 번호를 매긴다

bool check[10];
int arr[10];
int N;

int tmp_answer = 0;
int answer = 0;

void dfs(int size) {

	//처음이랑 끝만 남으면
	if (size == 2) {
		answer = max(answer, tmp_answer);
		return;
	}

	
	for (int i = 0; i < N; i++) {
		//처음, 마지막은 무시
		if (i == 0 || i == N - 1) continue;

		//아직 제거된게 아니면
		if (!check[i]) {
			check[i] = true;

			int l = i - 1;
			int r = i + 1;
			//l과 r을 찾는다
			while (check[l]) l--;
			while (check[r]) r++;

			tmp_answer += (arr[l] * arr[r]);
			dfs(size - 1);
			tmp_answer -= (arr[l] * arr[r]);
			check[i] = false;
		}
	}
}
int main() {
	cin >> N;		//구슬 개수
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(N);

	cout << answer;
}
