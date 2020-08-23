#include<iostream>
#include<string>
#include<vector>

using namespace std;

//못품
//최소 버텍스 커버문제
//이분매칭을 이용

int N, K;		//N * N , 돌맹이 개수
vector<int> arr[501];		//x좌표가 i일때 돌맹이가 존재하는 y좌표를 저장
int cover[501];
bool check[501];

//이분매칭
//y좌표를 보고 아직 커버가 안됐으면 커버
//커버 된 상태면 y좌표를 커버한 x좌표로 가서 다른걸 커버할수있는지 보고 된다면 수정 , 안되면 그냥

bool Match(int x) {

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		//현재 DFS레벨에서 확인한 y좌표면 무시
		if (check[y]) continue;

		check[y] = true;

		//커버가 안됐거나 , 커버한 x좌표가 다른곳으로 갈수있을때
		if (cover[y] == -1 || Match(cover[y])) {
			cover[y] = x;
			return true;
		}
	}

	//끝까지 매칭이 안되면
	return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;

	int x, y;
	for (int k = 0; k < K; k++) {
		cin >> x >> y;
		arr[x].push_back(y);
	}

	//cover초기화
	for (int n = 1; n <= N; n++) cover[n] = -1;

	for (int n = 1; n <= N; n++) {
		//check초기화
		for (int i = 1; i <= N; i++) check[i] = false;

		Match(n);
	}

	int answer = 0;
	for (int n = 1; n <= N; n++) if (cover[n] != -1) answer++;

	cout << answer;
}
