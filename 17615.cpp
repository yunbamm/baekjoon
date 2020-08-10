#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//혼자 못품
int N;
char arr[500000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}


	int answer = 987654321;
	bool flag = true;
	int tmp = 0;
	
	//1. R을 왼쪽으로 몰기
	for (int n = 0; n < N; n++) {
		if (flag && arr[n] == 'B') flag = false;
		if (!flag && arr[n] == 'R') tmp++;
	}
	answer = min(answer, tmp);

	//2. B을 왼쪽으로 몰기
	flag = true;
	tmp = 0;
	for (int n = 0; n < N; n++) {
		if (flag && arr[n] == 'R') flag = false;
		if (!flag && arr[n] == 'B') tmp++;
	}
	answer = min(answer, tmp);

	//3. R을 오른쪽으로 몰기
	flag = true;
	tmp = 0;
	for (int n = N-1; n >= 0; n--) {
		if (flag && arr[n] == 'B') flag = false;
		if (!flag && arr[n] == 'R') tmp++;
	}
	answer = min(answer, tmp);

	//4. B을 오른쪽으로 몰기
	flag = true;
	tmp = 0;
	for (int n = N - 1; n >= 0; n--) {
		if (flag && arr[n] == 'R') flag = false;
		if (!flag && arr[n] == 'B') tmp++;
	}
	answer = min(answer, tmp);

	cout << answer;
}
