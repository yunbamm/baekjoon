#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//그리디

int N, M;

int six_min = 987654321;
int one_min = 987654321;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int n1, n2;
	for (int m = 0; m < M; m++) {
		cin >> n1 >> n2;

		six_min = min(six_min, n1);
		one_min = min(one_min, n2);
	}


	//하나로만 샀을때 , 묶음으로만 샀을때, 섞어서 샀을때
	int tmp = N / 6;
	int remainder = N - (tmp * 6);
	int answer = min(N * one_min, tmp * six_min + remainder * one_min);
	answer = min(answer, six_min * (tmp + 1));
	cout << answer;
}
