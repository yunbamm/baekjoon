#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main() {

	int N, M;
	int answer = 2000000000;
	int i = 0, j = 0;
	vector<int> v;

	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	while (j < N && i <= j) {
		int cha = abs(v[i] - v[j]);

		//만약 차가 M보다 작다면 j++
		if (cha < M) j++;
		else {
			answer = min(answer, cha);
			i++;
		}
	}
	cout << answer;
}
