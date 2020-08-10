#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int answer[1000001] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque<int> v;	//index를 가진다	

	int N;
	

	cin >> N;
	for (int n = 1; n <= N; n++) v.push_back(n);

	//입력받기
	int order;
	for (int n = N; n > 0; n--) {
		cin >> order;
		int tmp;
		//맨위
		if (order == 1) {
			tmp = v.front();
			v.pop_front();
		}
		//위에서 두번째
		if (order == 2) {
			int tmp2 = v.front();
			v.pop_front();
			tmp = v.front();
			v.pop_front();
			v.push_front(tmp2);
		}
		//맨아래
		if (order == 3) {
			tmp = v.back();
			v.pop_back();
		}
		answer[tmp] = n;
	}


	for (int i = 1; i <= N; i++) cout << answer[i] << " ";
}
