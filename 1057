#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N, A, B;
//!!!!!!!!!!!!!!무조건 B가 A보다 크다고 생각하면 안된다
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> A >> B;

	//A가 홀수고 B가 짝수일때 (1차이면 끝)
	//반대인 경우도 가능
	int round = 1;
	while (1) {
		if (A % 2 == 1 && A + 1 == B) break;
		if (B % 2 == 1 && B + 1 == A) break;

		//아니면 다음라운드로(홀수면 +1한뒤 /2) ( 짝수면 그냥  /2)
		if (A % 2 == 0) A = A / 2;
		else A = (A + 1) / 2;

		if (B % 2 == 0) B = B / 2;
		else B = (B + 1) / 2;

		round++;
	}

	cout << round;
}
