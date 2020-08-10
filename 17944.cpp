#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N, T;

	int answer = 1;

	cin >> N >> T;
	//false면 + , true면 -
	bool flag = false;
	while (--T) {
		
		if (!flag) {
			if (answer == 2 * N) {
				flag = true;
				answer--;
			}
			else answer++;
		}
		else {
			if (answer == 1) {
				flag = false;
				answer++;
			}
			else answer--;
		}
	}

	cout << answer;
}
