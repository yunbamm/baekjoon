#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

int N, M;	// 학생, 과목수
//과목별 수강인원
int arr[1001] = { 0 };
vector<int> v[1001];		//과목에 신청한 학생번호
vector<int> answer[1001];	//학생이 신청성공한 과목번호

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	//과목별 수강인원
	for (int m = 1; m <= M; m++) {
		cin >> arr[m];
	}

	//n번 학생의 수강신청(1차)
	int num;
	for (int n = 1; n <= N; n++) {
		while (1) {
			cin >> num;
			if (num == -1) break;
			v[num].push_back(n);
		}
	}
	//1차후 수용인원보다 적게 신청한 과목들은 신청됨
	for (int m = 1; m <= M; m++) {
		if (v[m].size() <= arr[m]) {

			for (int i = 0; i < v[m].size(); i++) {
				int student = v[m][i];
				answer[student].push_back(m);
			}

			arr[m] -= v[m].size();
			v[m].clear();
		}
	}
	//2차
	for (int n = 1; n <= N; n++) {
		while (1) {
			cin >> num;
			if (num == -1) break;
			v[num].push_back(n);
		}
	}
	//2차후 
	for (int m = 1; m <= M; m++) {
		if (v[m].size() <= arr[m]) {

			for (int i = 0; i < v[m].size(); i++) {
				int student = v[m][i];
				answer[student].push_back(m);
			}
		}
	}

	//오름차순
	for (int n = 1; n <= N; n++) {
		if (answer[n].size() == 0) {
			cout << "망했어요\n";
			continue;
		}
		else {
			sort(answer[n].begin(), answer[n].end());
			for (int i = 0; i < answer[n].size(); i++) {
				cout << answer[n][i] << " ";
			}
			cout << "\n";
		}
	}
}
