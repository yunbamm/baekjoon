#include<iostream>
#include<string>

using namespace std;

int N;
bool flag = false;

//좋은수열이면 true 아니면 false
bool check(int n, string s) {


	//i == 1 , [N-1] 과 [N-2] 비교
	//i==2 , [N-1] 과 [N-3] ,[N-2] 와 [N-4] 비교


	for (int i = 1; i <= n; i++) {

		int j = i;
		int now = s.size() - 1;
		while (j--) {
			//다르면 break;
			if (s[now] != s[now - i]) break;
			
			//같은데 j가 1이면 나쁜수열
			else if (j == 0) {
				return false;
			}

			now--;
		}
	}

	return true;
}
void DFS(string tmp) {

	//1 ~ half 간격일때 비교를 해야된다
	int half = tmp.size() / 2;
	//이미 구했거나 나쁜수열이면 백
	if (flag || !check(half, tmp)) return;

	//좋은 수열인데 크기가 N이면
	if (tmp.size() == N) {
		cout << tmp << "\n";
		flag = true;
		return;
	}
	for (char c = '1'; c <= '3'; c++) {
		DFS(tmp+c);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;

	string s;
	for (char c = '1'; c <= '3'; c++) {
		s = c;
		DFS(s);
	}
}
