#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

//나보다 낮은 등수 애들을 봤을때 2번째 등수도 낮으면 해당신입사원은 제외!

vector<pair<int, int>> v;		//첫번쨰 등수, 두번쨰 등수
int T, N;
stack<int> s;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;
		int n1, n2;
		for (int i = 1; i <= N; i++) {
			cin >> n1 >> n2;
			v.push_back({ n1,n2 });
		}
		
		sort(v.begin(), v.end());
		int answer = 0;
		
		for (int i = 0; i < v.size(); i++) {
			int next = v[i].second;

			if (s.empty()) s.push(next);
			else {
				if (s.top() > next) s.push(next);
			}
		}

		cout << s.size() << "\n";
	
		while (!s.empty()) s.pop();
		v.clear();
	}

}
