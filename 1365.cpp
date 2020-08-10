#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


//이분탐색
//lower_bound연습

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

		//비어있다면
		if (v.empty()) v.push_back(tmp);
		//back보다 큰게 온다면
		else if (v.back() < tmp) v.push_back(tmp);
		//작은게 온다면 위치를 찾아서 수정해줘야함
		else {
			iter = lower_bound(v.begin(), v.end(), tmp);
			v[iter - v.begin()] = tmp;
		}
	}

	cout << N - v.size();


}
