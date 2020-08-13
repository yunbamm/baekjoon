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
//못풀었다
//이분탐색


//이분탐색을 숫자를 입력받을때 가능한 자리수를 알수있다
//ex) 1 3 2 4 -> 0 1 1 2

int N;
int location[1000000];
int num[1000000];

vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	vector<int>::iterator iter;

	//location초기화
	for (int i = 0; i < 1000000; i++) {
		location[i] = -1;
	}
	for (int n = 0; n < N; n++) {
		cin >> num[n];

		if (v.empty()) {
			v.push_back(num[n]);
			location[n] = 0;
		}
		else {

			if (v.back() < num[n]) {
				v.push_back(num[n]);
				location[n] = v.size() - 1;
			}
			else {
				iter = lower_bound(v.begin(), v.end(), num[n]);
				v[iter - v.begin()] = num[n];
				location[n] = iter - v.begin();
			}
		}
	}

	int now = v.size() - 1;
	cout << v.size() << "\n";

	//거꾸로찾아야 맞는답이나온다!!!!!!!!!!!!!
	stack<int> answer;
	for (int i = 1000000; i >= 0; i--) {
		if (location[i] == now) {
			now--;
			answer.push(num[i]);
		}
	}

	while (!answer.empty())
	{
		cout << answer.top() << " ";
		answer.pop();
	}
}

