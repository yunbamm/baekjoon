#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//1.성규 교수님 거리 5이상
//2. 직사각형안에 성규가 아닌학생이 3명이상

int N;
int arr[1000][1000] = { 0 };
pair<int, int> song;
pair<int, int> pro;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> arr[x][y];
			//성규
			if (arr[x][y] == 2) {
				song.first = x;
				song.second = y;
			}
			//교수
			if (arr[x][y] == 5) {
				pro.first = x;
				pro.second = y;
			}
		}
	}

	//1.거리 5이상
	int distance = sqrt((song.first - pro.first) *  (song.first - pro.first) + (song.second - pro.second) * (song.second - pro.second));

	if (distance < 5) {
		cout << "0\n";
		return 0;
	}

	//2.
	int tmp = 0;
	for (int x = min(song.first, pro.first); x <= max(song.first, pro.first); x++) {
		for (int y = min(song.second, pro.second); y <= max(song.second, pro.second); y++) {
			if (arr[x][y] == 1) tmp++;
		}
	}

	if (tmp >= 3) cout << "1\n";
	else cout << "0\n";
}
