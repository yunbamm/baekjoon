#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//나무 M 미터 필요
//절단 높이 H

//H보다 큰 나무면 절단 , 작으면 절단 X
//H의 최댓값
int N, M;			//나무의 수 , 필요한 나무길이
int answer = -987654321;
vector<int> v;

void binary_search() {
	int l = 0;
	int r = v.back();
	while (l <= r) {
		int mid = (l + r) / 2;		//절단 높이!

		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > mid) sum += (v[i] - mid);
		}

		//필요보다 적으면 절단기 낮춰야한다
		if (sum < M) {
			r = mid - 1;
		}
		//M미터를 가져갈수있다
		else {
			answer = max(answer, mid);
			l = mid + 1;
		}
	}
}
int main() {
	cin >> N >> M;
	
	int h;
	for (int i = 0; i < N; i++) {
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(), v.end());
	binary_search();

	cout << answer;
}
