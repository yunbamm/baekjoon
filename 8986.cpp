#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//이분탐색 하다가 못품
//삼분탐색

vector<int> v;
int N;

long long process(long long tmp) {

	long long result = 0;
	long long now = tmp;
	for (int i = 1; i < v.size(); i++) {
		result += abs(now - v[i]);
		now += tmp;
	}

	return result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}


	long long l = 0, r = v.back();
	long long answer = 200000000000000;


	//길이가 최소 3은 되야지 3등분이 가능하다
	while (r - l >= 3) {
		//3등분
		long long p = (2 * l + r) / 3;
		long long q = (l + 2 * r) / 3;


		long long now = 0;
		long long p_answer = process(p);
		long long q_answer = process(q);


		//비교

		//q가 더 크다면 q이후로는 다 날려도 된다
		if (p_answer < q_answer) r = q - 1;

		//p가 더 크다면 1~p까지 날려도 된다
		else l = p + 1;
	}

	//끝에가 답이아니라 구간이나오기때문에 구간을 확인해야한다

	for (long long i = l; i <= r; i++) {
		answer = min(answer, process(i));
	}
	cout << answer;
}

