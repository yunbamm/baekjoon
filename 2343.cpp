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
//힌트
//left를 유의해야한다!!!!!!!(레슨중에 최대 길이)

int N, M;		//레슨 수, 블루레이 수
vector<long long> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int l = 0, r = 2000000000;
	int answer = 2000000000;
	int tmp;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		l = max(l, tmp);
		v.push_back(tmp);
	}

	
	while (l <= r) {
		int mid = (l + r) / 2;		//임시 블루레이 크기

		int sum = 0;
		int count = 1;
		for (int i = 0; i < v.size(); i++) {

			//임시 크기를 넘기면 새 블루레이에 저장
			if (sum + v[i] > mid) {
				count++;
				sum = 0;
			}

			sum += v[i];
		}

		//더 적은개수로도 저장가능하다면
		if (count <= M) {
			r = mid - 1;
			answer = min(answer, mid);
		}
		else l = mid + 1;
	}

	cout << answer;
}
