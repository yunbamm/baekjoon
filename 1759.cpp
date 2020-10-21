#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//L개의 알파벳 소문자로 구성
//최소 한개의 모음(a,e,i,o,u) 와 최소 두개의 자음
//암호는 증가순서로

int L, C;		//암호의 길이 , 주어지는 알파벳개수
vector<int> alpha;
vector<int> v;
bool check[26];

void make(int index) {

	if (v.size() == L) {
		//모음이 있는지
		int ja = 0;
		int mo = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 'a' - 'a' || v[i] == 'e' - 'a' || v[i] == 'i' - 'a' || v[i] == 'o' - 'a' || v[i] == 'u' - 'a') ja++;
			else mo++;
		}
		if (ja>=1 && mo >=2) {
			for (int i = 0; i < v.size(); i++) {
				cout << (char)(v[i] + 'a');
			}
			cout << "\n";
		}
		return;
	}
	for (int i = index; i < alpha.size(); i++) {
		int now = alpha[i];

		if (!check[now]) {
			check[now] = true;
			v.push_back(now);
			make(i);
			v.pop_back();
			check[now] = false;
		}
	}
}
int main() {

	cin >> L >> C;

	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		alpha.push_back(c - 'a');
	}

	sort(alpha.begin(), alpha.end());
	make(0);

}
