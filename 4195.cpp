#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

using namespace std;

int tmp = 0;		//친구네트워크번호(0번부터 증가)
int num[100000] = { 0 };			//index 네트워크의 인원수
int parent[100000];
int T,F;

int find(int& now) {
	if (now == parent[now]) return now;
	else return parent[now] = find(parent[now]);
}
void union_func(int n1, int n2) {
	int p1 = find(n1);
	int p2 = find(n2);

	if (p1 == p2) {
		cout << num[p1] << '\n';
	}
	else if (p1 < p2) {
		parent[p2] = p1;
		num[p1] += num[p2];
		cout << num[p1] << "\n";
	}
	else {
		parent[p1] = p2;
		num[p2] += num[p1];
		cout << num[p2] << "\n";
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> F;		//친구 관계수
		string s1, s2;

		//num초기화 
		for (int i = 0; i < 100000; i++) {
			parent[i] = i;
			num[i] = 1;
		}
		//tmp 초기화
		tmp = 0;
		map<string, int> m;			//이름 , 부여받은 숫자


		for (int f = 0; f < F; f++) {
			cin >> s1 >> s2;

			if (m.find(s1) == m.end()) {
				m.insert({ s1,tmp });
				tmp++;
			}
			if (m.find(s2) == m.end()) {
				m.insert({ s2,tmp });
				tmp++;
			}

			int n1 = m.find(s1)->second;
			int n2 = m.find(s2)->second;

			union_func(n1, n2);
		}
	}

}
