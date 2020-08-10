#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//개수도 따지는거였다
int big[26] = { 0 };
int small[26] = { 0 };
int space = 0;

int main() {

	//65 97
	int N;
	cin >> N;
	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		if (num == 0) space++;
		else if (1 <= num && num <= 26) big[num - 1]++;
		else if (27 <= num && num <= 52) small[num - 27]++;
	}

	string s;
	string tmp;
	getline(cin, tmp);
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];

		if (c == ' ') {
			if (space<=0) {
				cout << "n\n";
				return 0;
			}
			else space--;
		}

		else if ('A' <= c && c <= 'Z') {
			if (big[(int)c - 65] <=0) {
				cout << "n\n";
				return 0;
			}
			else big[(int)c - 65]--;
		}
		else if ('a' <= c && c <= 'z') {
			if (small[(int)c - 97] <= 0) {
				cout << "n\n";
				return 0;
			}
			else small[(int)c - 97]--;
		}
	}

	cout << "y\n";
}
