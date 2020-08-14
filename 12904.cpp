#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//못품
//힌트 : 역방향으로 생각한다
//S -> T 가 아니라 T -> S로 생가

//1.맨뒤의 A를 뺀다
//2. 맨뒤의 B를 빼고 뒤집는다

string S, T;

string reverse(string t) {

	string tmp;
	for (int i = t.size() - 1; i >= 0 ; i--) {
		tmp.push_back(t[i]);
	}

	return tmp;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> S >> T;

	while (1) {

		//길이가 같아졌을때 같은지 확인하면 됨
		if (S.size() == T.size()) {
			if (S == T) cout << "1\n";
			else cout << "0\n";
			break;
		}
		//아니라면 처리필요
		else {
			//맨뒤가 A면 그냥 뺀다
			if (T.back() == 'A') {
				T.pop_back();
			}
			//B면 빼고 뒤집는다
			else {
				T.pop_back();
				T = reverse(T);
			}
		}
	}
	
}

