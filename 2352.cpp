#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//최장증가수열을 찾아서 N - 최장증가수열길이

int N;
vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int tmp;
	vector<int>::iterator iter;

	for (int n = 0; n < N; n++) {
		cin >> tmp;

		if (v.empty()) v.push_back(tmp);
		else {
			if (v.back() < tmp) v.push_back(tmp);
			else {
				iter = lower_bound(v.begin(), v.end(), tmp);
				v[iter - v.begin()] = tmp;
			}
		}
	}

	cout << v.size();
}
