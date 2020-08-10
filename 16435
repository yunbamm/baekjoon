#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//sort

int N, L;		//과일 개수 , 초기 길이
vector<int> v;		//과일 높이

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L;

	int h;
	for (int n = 0; n < N; n++) {
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= L) {
			L++;
		}
	}
	cout << L;
}
