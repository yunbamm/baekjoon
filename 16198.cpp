#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//에너지 구술 하나를 고른다 (첫번째 , 마지막은 못고른다)
//x 구술 제거 -> [x-1] * [x+1]에너지를 모을수있다
//N을 1 감소 , 1~N까지 다시 번호를 매긴다

bool check[10];
vector<int> arr;
int N;

int tmp_answer = 0;
int answer = 0;

void copy(vector<int> &v, vector<int> &v2) {

	v.clear();
	for (int i = 0; i < v2.size(); i++) {
		v.push_back(v2[i]);
	}
}
//
void dfs(int size) {

	//처음이랑 끝만 남으면
	if (size == 2) {
		answer = max(answer, tmp_answer);
		return;
	}
	vector<int> tmp;
	copy(tmp, arr);

	for (int i = 0; i < arr.size(); i++) {
		//처음, 마지막은 무시
		if (i == 0 || i == arr.size() - 1) continue;

		tmp_answer += (arr[i - 1] * arr[i + 1]);
		arr.erase(arr.begin() + i);
		dfs(size - 1);
		copy(arr, tmp);
		tmp_answer -= (arr[i - 1] * arr[i + 1]);
	}
}
int main() {
	cin >> N;		//구슬 개수
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}

	dfs(N);

	cout << answer;
}
