#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

//백트래킹
bool use_alpha[26];		//해당 알파벳을 쓰는지
vector<int> alpha;		//사용되는 알파벳 index저장 A(0) ~ Z(25)
bool check[26];			//현재 알파벳 index가 조합에 들어가있는지
int N;					//단어 개수
vector<string> v;		//입력받은 단어
vector<int> index;		//만들어진 조합
int alpha_num = 0;		//사용된 알파벳 개수
int fix_num[26];		//배정받은 번호
long long answer = 0;

void cal() {

	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		string tmp_s = v[i];
		int tmp = 0;
		for (int j = 0; j < tmp_s.size(); j++) {
			int now = tmp_s[j] - 'A';
			tmp *= 10;
			tmp += fix_num[now];
		}

		sum += tmp;
	}

	answer = max(answer, sum);
}
//사용한 알파벳에 한해서 조합을 만든다
void make() {

	//조합의 크기가 사용된 알파벳 크기와 같다면 숫자 배정
	if (index.size() == alpha_num) {
		//숫자 배정
		int tmp = 9;
		for (int i = 0; i < index.size(); i++) {
			fix_num[index[i]] = tmp;
			tmp--;
		}
		//계산시작
		cal();
		return;
	}
	//사용된 알파벳index로 조합을 만든다
	for (int i = 0; i < alpha.size(); i++) {
		if (!check[alpha[i]]) {
			check[alpha[i]] = true;
			index.push_back(alpha[i]);
			make();
			index.pop_back();
			check[alpha[i]] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//입력받기
	cin >> N;
	string s;
	for (int n = 0; n < N; n++) {
		cin >> s;
		v.push_back(s);

		//사용한 알파벳 체크
		for (int i = 0; i < s.size(); i++) {
			use_alpha[s[i]-'A'] = true;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (use_alpha[i]) {
			alpha.push_back(i);
			alpha_num++;
		}
	}

	//조합을 만들자
	make();


	cout << answer;
}
