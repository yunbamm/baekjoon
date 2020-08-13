#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//최장증가수열
//DP
//이분탐색으로 못풀었다...아마 숫자가 중복되는 부분에서 예외가 생긴거 같다

int N;
int num[1000];
int tmp_size[1000];
int pre_index[1000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];

		int max_size = -1;
		int pre = -1;

		for (int j = i - 1; j >= 0; j--) {
			if (max_size < tmp_size[j] && num[i] > num[j]) {
				max_size = tmp_size[j];
				pre = j;
			}
		}

		tmp_size[i] = max_size + 1;
		pre_index[i] = pre;
	}


	int max_size = -1;
	int index = -1;

	for (int i = 0; i < N; i++) {
		if (max_size < tmp_size[i]) {
			max_size = tmp_size[i];
			index = i;
		}
	}

	cout << max_size + 1 << "\n";
	stack<int> s;

	while (index != -1) {
		s.push(num[index]);
		index = pre_index[index];
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

