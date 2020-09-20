#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//0~25
//a n t i c 최소 5개는 알아야한다
//모두 소문자
//N 단어수 , K 가르칠수있는 개수
//K<=4 면 answer = 0
//비트연산자 이용?

int N, K;
int answer = 0;
int word[50] = { 0 };
bool check[26];
vector<int> v;

//조합을 만든다 (K - 5) 크기
void make(int index, int size) {

	//조합이 만들어졌으면
	if (size == v.size()) {

		int tmp_answer = 0;

		//현재 배운 언어
		int now_word = 0;
		for (int i = 0; i < v.size(); i++) {
			now_word |= (1 << v[i]);
		}

		//현재 배운언어와 word를 비교
		//만약 현재 배운언어 와 word를 or해서 현재 언어면 현재 언어로만 
		for (int i = 0; i < N; i++) {
			int result = (now_word | word[i]);

			if (result == now_word) tmp_answer++;
		}

		answer = max(answer, tmp_answer);
	}

	//a n t i c는 무시
	for (int i = index; i < 26; i++) {
		if (i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;

		if (!check[i]) {
			check[i] = true;
			v.push_back(i);
			make(i, size);
			v.pop_back();
			check[i] = false;
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> N >> K;

	
	string s;
	for (int n = 0; n < N; n++) {
		cin >> s;

		//a n t i c 를 제외하고 비트연산을 통해 word 저장
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'n' || s[i] == 't' || s[i] == 'i' || s[i] == 'c') continue;

			int tmp = s[i] - 'a';

			word[n] |= (1 << tmp);
		}
	}

	if (K >= 5) {
		//조합을 만들자
		make(0 , K - 5);
	}

	cout << answer;
}
