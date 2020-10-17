#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;			//수의 개수
int arr[11];		//수 
int num[4];		//+,-,*,/ 개수

vector<int> v;
int max_ans = -987654321;
int min_ans = 987654321;

void cal() {
	
	int now = arr[0];
	int index = 0;

	for (int i = 1; i < N; i++ , index++) {
		int next = arr[i];
		if (v[index] == 0) now += next;
		if (v[index] == 1) now -= next;
		if (v[index] == 2) now *= next;
		if (v[index] == 3) now /= next;
	}

	max_ans = max(max_ans, now);
	min_ans = min(min_ans, now);
}
//조합만들기
void make() {

	if (v.size() == N - 1) {
		cal();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (num[i] > 0) {
			num[i]--;
			v.push_back(i);
			make();
			v.pop_back();
			num[i]++;
		}
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> num[i];

	make();

	cout << max_ans << "\n";
	cout << min_ans << "\n";
}
