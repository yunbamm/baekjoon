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
int N;
vector<int> v;
long long tmp_answer = 2000000000;
int answer[2];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;

		v.push_back(tmp);
	}

	//정렬
	sort(v.begin(), v.end());
	
	int i = 0, j = N - 1;

	while (i < j) {

		long long now = v[i] + v[j];

		if (abs(tmp_answer) > abs(now)) {
			tmp_answer = now;
			answer[0] = v[i];
			answer[1] = v[j];
		}


		if (now < 0) i++;
		else j--;
	}

	for (int i = 0; i < 2; i++) {
		cout << answer[i] << " ";
	}
}

