#include<iostream>
#include<algorithm>

using namespace std;

int H, W;		//세로 , 가로
int arr[500];

int answer = 0;

int main() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < W; i++) {
		//처음과 끝은 무시
		if (i == 0 || i == W - 1) continue;

		//현재칸을 기준으로 왼쪽최대값 , 오른쪽 최대값을 구한다
		int l = arr[i];
		int r = arr[i];
			
		for (int j = i - 1; j >= 0; j--) l = max(l, arr[j]);
		for (int j = i + 1; j < W; j++) r = max(r, arr[j]);

		int tmp_H = min(l, r);		//둘중 작은높이까지만 물이찰수있다
		if (tmp_H > arr[i]) {
			answer += (tmp_H - arr[i]);
		}
	}
	cout << answer;
}
