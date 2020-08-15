#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//stack에 넣으면서 
//작은게 들어오면 그냥 push
//큰게 들어오면 작은걸 만나거나 , 비어있을때까지 pop
//stack을 int로 할때는 안되다가 char로 하니까 맞음..
int N, K;
stack<char> s;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;

	char c;

	for (int i = 0; i < N; i++) {
		cin >> c;

		if (s.empty()) s.push(c);
		else {

			while (K > 0 && !s.empty() && s.top() < c)
			{
				s.pop();
				K--;
			}
			s.push(c);
		}
	}

	while (K > 0) {
		s.pop();
		K--;
	}

	stack<char> answer;
	while (!s.empty()) {
		answer.push(s.top());
		s.pop();
	}

	while (!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}
}

