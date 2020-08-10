#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//왜 그리디?
int N, M;
int arr[50][50];
int tmp[50][50];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	char c;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> c;
			if (c == '0') arr[n][m] = 0;
			else arr[n][m] = 1;
		}
	}
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> c;
			if (c == '0') tmp[n][m] = 0;
			else tmp[n][m] = 1;
		}
	}


	int answer = 0;
	for (int x = 0; x + 2 < N; x++) {
		for (int y = 0; y + 2 < M; y++) {
			//바꿔준다
			if (arr[x][y] != tmp[x][y]) {
				answer++;
				for (int i = x; i <= x + 2; i++) {
					for (int j = y; j <= y + 2; j++) {
						if (arr[i][j] == 0) arr[i][j] = 1;
						else arr[i][j] = 0;
					}
				}
			}
		}
	}

	//확인
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (arr[n][m] != tmp[n][m]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << answer;
}
