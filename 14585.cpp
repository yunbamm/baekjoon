#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N, M;		//사탕바구니 , 바구니당 사탕수
vector<pair<int, int>> v;
int arr[301][301] = { 0 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int tmp_x, tmp_y;
	for (int n = 0; n < N; n++) {
		cin >> tmp_x >> tmp_y;
		v.push_back({tmp_x , tmp_y} );
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int nowx = v[i].first;
		int nowy = v[i].second;

		int tmp_max = 0;
		int tmpx = 0, tmpy = 0;
		//최대값 우선 찾기
		for (int x = 0; x <= nowx; x++) {
			for (int y = 0; y <= nowy; y++) {
				if (tmp_max < arr[x][y]) {
					tmpx = x;
					tmpy = y;
					tmp_max = arr[x][y];
				}
			}
		}

		int tmp_distance = nowx + nowy;

		if (M - tmp_distance <= 0) continue;

		arr[nowx][nowy] += arr[tmpx][tmpy] + M - tmp_distance;
	}


	int answer = 0;
	for (int x = 0; x <= 300; x++) {
		for (int y = 0; y <= 300; y++) {
			answer = max(answer, arr[x][y]);
		}
	}
	
	cout << answer;
}
