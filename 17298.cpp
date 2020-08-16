#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//stack이용?

//stack의 top보다 큰값이 오면 작은값이 올때까지 pop하면서 answer[index] = 입력값으로 
//작은게 오면 그냥 push

int N;
stack<pair<int,int>> s;		//값, index
int answer[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	//answer초기화
	for (int n = 0; n < N; n++) answer[n] = -1;
	int tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;

		//비교 대상이 없으면 그냥 push
		if (s.empty()) s.push({ tmp , n });
		else {
			//비어있지않는데 , top값이 작다면
			while (!s.empty() && s.top().first < tmp) {
				answer[s.top().second] = tmp;
				s.pop();
			}
			s.push({ tmp,n });
		
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
	
}



