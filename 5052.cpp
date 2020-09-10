#include<iostream>
#include<string>

using namespace std;

struct Trie
{
	bool finish;
	Trie* num[10];

	Trie() {
		finish = false;
		for (int i = 0; i < 10; i++) num[i] = NULL;
	}
};

bool insert(Trie* now, int index , bool flag) {

	//없으면 추가
	if (now->num[index] == NULL) {
		now->num[index] = new Trie();
		//마지막이면
		if (flag) now->num[index]->finish = true;
		
		return true;
	}
	//있으면
	else {
		//있는데 finish라면
		if (now->num[index]->finish) return false;
		//있는데 내가 finish라면
		if (flag) {
			now->num[index]->finish = true;
			return false;
		}
		return true;
	}
}
int main() {
	int T, N;
	string s;
	cin >> T;
	while (T--) {
		cin >> N;

		Trie* root = new Trie();
		Trie* now;
		bool flag = true;
		
		//입력받기
		for (int i = 0; i < N; i++) {
			cin >> s;

			now = root;
			//한숫자씩 insert
			for (int j = 0; j < s.size(); j++) {
				if (j != s.size() - 1) {
					if (!insert(now, s[j] - '0', false)) {
						flag = false;
					}
				}
				else {
					if (!insert(now, s[j] - '0', true)) {
						flag = false;
					}
				}
				now = now->num[s[j]-'0'];
			}
		}

		if (!flag) cout << "NO\n";
		else cout << "YES\n";

	}
}
