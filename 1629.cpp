#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int A, B, C;		//A를 B번 곱한수를 C로 나눠라


//짝수일때 , 홀수일때 나누자
//ex) a^6 = (a3)^2
//ex) a^7 = a^6 * a
long long DFS(int A, int B, int C) {

	if (B == 1) return A % C;

	//짝수일때
	if (B % 2 == 0) return (DFS(A, B / 2, C) * DFS(A, B / 2, C)) % C;

	else return (DFS(A, B - 1, C) * DFS(A, 1, C)) % C;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;

	cout<<DFS(A, B, C);
}
