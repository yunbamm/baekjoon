#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N;
vector<pair<int,int>> v;		//중간 , 기말

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		v.push_back({ tmp , i });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first - v[i].second << "\n";
	}

}
