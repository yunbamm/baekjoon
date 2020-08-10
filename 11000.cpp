#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//못풀었다
//힌트 : 강의실 개수를 구하는거다
//pq에 종료시간을 넣고 , 시작시간이 젤 빠른거와 비교해서 들을수있는지 본다
//시작시간과 젤 차이 안나는 종료시간을 가진 강의실에 넣는게 유리하다?
//-> 이렇게 할필요가 없는게 차피 강의들을 시작시간이 빠른순으로 정리했기때문에 별로 관계없다 (이해안감)
//그냥 빨리 빈 강의실에 빨리채워넣는다 생각

int N;
priority_queue<int>pq;
vector<pair<int, int>> v;		//시작시간 , 끝 시간

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int start, end;
	for (int n = 0; n < N; n++) {
		cin >> start >> end;

		v.push_back({ start, end });
	}

	sort(v.begin(), v.end());
	
	
	//시작시간 0으로 시작
	pq.push(-0);

	for (int i = 0; i < v.size(); i++) {
		int tmp_start = v[i].first;
		int tmp_end = v[i].second;

		int now = -pq.top();

		//젤 빨리 비는 강의실에서 들을수있을때
		if (now <= tmp_start) {
			pq.pop();
			pq.push(-tmp_end);
		}
		//없으면 뒤에 강의실은 더 늦게 끝나기때문에 보나마나
		else {
			pq.push(-tmp_end);
		}
	}

	cout << pq.size();
}
