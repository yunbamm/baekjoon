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
vector<int> v;

//1~N까지 만들어주면 된다
//정렬후 처리
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	//!!!!!v[i]<tmp인 경우에는 무시해줘도 된다
	int tmp = 1;
	long long answer = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] >= tmp) {
			answer += (v[i] - tmp);
			tmp++;
		}
	}

	cout << answer;
}
