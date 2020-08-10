#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

#define INF 987654321

//1 -> 0 or  0 -> 1 (묶음당 고정된 수가 있고 연결부분만 보면 된다)
vector<pair<char,char>> v;
vector<int> num;
int N;
bool check[10];
int answer = INF;

void process() {

	if (num.size() == N) {
		char pre = '2';
		int tmp = 0;
		for (int i = 0; i < num.size(); i++) {
			int now = num[i];
			
			//처음
			if (pre == '2') pre = v[now].second;
			else {
				
				if (pre != v[now].first) {
					tmp++;
				}
				pre = v[now].second;
			}
			
		}

		answer = min(answer, tmp);
		return;	
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			num.push_back(i);
			process();
			num.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	string s;
	int tmp_answer = 0;
	for (int n = 0; n < N; n++) {
		cin >> s;
		
		int pre = -1;
		for (int i = 0; i < s.size(); i++) {
			if (pre == -1) pre = s[i];
			else {
				if (pre != s[i]) {
					tmp_answer++;
					pre = s[i];
				}
			}
		}
		
		//끝부분을 저장
		v.push_back({ s.front() , s.back() });
	}

	process();
	cout << tmp_answer + answer;
}
