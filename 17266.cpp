#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//??간격 구하고 가장 긴 간격이 정답??
	
//!!!!!!!!!!!!!!!!!처음과 마지막을 제외하고는 간격이 반이되는걸 인지

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;	//굴다리 길이 , 가로등 개수
	cin >> N >> M;
	
	vector<int> tmp;
	int num;
	for (int m = 0; m < M; m++) {
		cin >> num;
		tmp.push_back(num);
	}

	vector<int> v;
	int now = 0;
	for (int i = 0; i < tmp.size(); i++) {
		if (i == 0) v.push_back(tmp[i] - now);
		//!!!!!!!!!!!!!올림으로 계산해서 해줘야한다
		else {
			if((tmp[i]-now)%2==0) v.push_back((tmp[i] - now) / 2);
			else v.push_back((tmp[i] - now) / 2 + 1);
		}
		now = tmp[i];
	}

	v.push_back(N - now);


	int answer = 0;
	for (int i = 0; i < v.size(); i++) answer = max(answer, v[i]);

	cout << answer;
}
