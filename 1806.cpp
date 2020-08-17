#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//투포인터

//수가 모두 자연수이다
//더하면 더할수록 커질수밖에없음

int N, S;		//연속 부분합이 S이상되는것중 가장짧은 길이
int answer = 987654321;
int arr[100000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}


	int i = 0, j = 0;
	int sum = arr[i];

	while (i < N && j < N && i <= j) {

		//sum이 15보다 작으면 j++
		if (sum < S) {
			j++;
			sum += arr[j];
		}
		//크면 i++
		else {
			answer = min(answer, j - i + 1);
			sum -= arr[i];
			i++;
		}
	}

	if (answer >= 987654321) cout << 0;
	else cout << answer;
}




