#include<iostream>
#include<string>
#include<vector>

using namespace std;

//KMP
string T, P;
int failure[1000000] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> T >> P;


	//Failure function
	//p[i] == p[j] 면 F[j] = i+1
	int j = 0;
	for (int i = 1; i < P.size(); i++) {

		//j가 0보다 크고 다르면 j를 수정
		while (j > 0 && P[j] != P[i]) {
			j = failure[j - 1];
		}

		//j가 0이거나 문자열이 같거나
		if (P[i] == P[j]) {
			failure[i] = j + 1;
			j++;
		}
	}


	//KMP
	j = 0;
	for (int i = 0; i < T.size(); i++) {

		//j가 0보다 크고 다르면 j를 수정
		while (j > 0 && P[j] != T[i]) {
			j = failure[j - 1];
		}

		//j가 0이거나 문자열이 같거나
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				cout << "1\n";
				return 0;
			}
			j++;
		}
	}

	cout << "0\n";
}
