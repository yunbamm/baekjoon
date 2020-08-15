#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//stack이용

string s, tmp;
stack<char> st;
stack<char> tmp_st;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	cin >> tmp;

	//하나씩 넣으면서 만약 tmp마지막과 같은게 들어오면 처리한다
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];

		st.push(c);

		//tmp마지막과 같다면 꺼내면서 tmp와 같은지 비교
		if (c == tmp.back()) {
			bool flag = true;
			for (int i = tmp.size() - 1; i >= 0; i--) {
				//다르다면 (이때 런에러 조심)
				if (st.empty() || tmp[i] != st.top()) {
					flag = false;
					break;
				}
				//같다면
				else if(tmp[i] ==st.top() && !st.empty()) {
					tmp_st.push(st.top());
					st.pop();
				}
			}
			//tmp와 같다면 지워준다
			if (flag) {
				while (!tmp_st.empty()) tmp_st.pop();
			}
            //다르면 다시 push
			else {
				while (!tmp_st.empty()) {
					st.push(tmp_st.top());
					tmp_st.pop();
				}
			}
		}
	}
    
    //정답 출력
	stack<char> answer;

	while (!st.empty()) {
		answer.push(st.top());
		st.pop();
	}

	if (answer.empty()) {
		cout << "FRULA\n";
		return 0;
	}
	while (!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}
}

