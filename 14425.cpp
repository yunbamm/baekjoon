#include<iostream>
#include<map>
#include <string>

using namespace std;

int N, M;
string s;

int main() {

	map<string, int> m;

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		cin >> s;

		if (m.find(s) == m.end()) m.insert({ s,1 });
	}
	int answer = 0;
	for (int i = 0; i < M; i++) {
		cin >> s;

		if (m.find(s) != m.end()) answer++;

	}
	cout << answer;

}
