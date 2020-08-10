#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

map<string, string> m;
int N, M;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	string site, pass;
	for (int n = 1; n <= N; n++) {
		cin >> site >> pass;
		m.insert({ site,pass });
	}
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout<<m.find(site)->second << "\n";
	}
}
