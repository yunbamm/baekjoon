#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//못풀었다
//3sum??
//우선 정렬이 필요
//0 ~ i까지 보는데 j = i + 1 , k = 맨끝으로 하고 탐색 시작
//a[i] + a[j] + a[k] 가 0보다 작으면? j값을 늘려주고 크면 k값을 줄여준다
//O(N^2)이란다

int N;
vector<int> v;

int answer_index[3];
long long answer = 5000000000000;

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


	//i는 고정시키고 , j , k를 이용
	for (int i = 0; i < N; i++) {
		long long now;

		int j = i + 1;
		int k = N - 1;

		//j<k인 동안
		while (j < k) {
			now = v[i];

			now += v[j];
			now += v[k];

			if (abs(answer) > abs(now)) {
				answer = now;
				answer_index[0] = v[i];
				answer_index[1] = v[j];
				answer_index[2] = v[k];
			}

			//만약 now가 0보다 작다면
			if (now < 0) j++;
			else k--;
		}
	}

	for (int i = 0; i < 3; i++) {
		cout << answer_index[i] << " ";
	}
}

