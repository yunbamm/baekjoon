#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//혼자 못품
//!!!!!!!!!!연속되는 가장 긴 증가수열을 찾아야댐 ex) 123 , 345
// 1 3 4 같은 경우는 안댐

int location[1000001];		//해당 번호가 나온 index
int arr[1000001];			//현 번호까지 연속증가수열 크기
int N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int num;


	for (int n = 0; n <= N; n++) {
		arr[n] = 1;
		location[n] = -1;
	}

	for (int n = 0; n < N; n++) {
		cin >> num;

		location[num] = n;
		
		//그전에 나왔다면
		if (location[num-1] != -1 ) {
			arr[num] = arr[num - 1] + 1;
		}

	}

	int answer = 0;
	for (int n = 0; n <= N; n++) {
		answer = max(answer, arr[n]);
	}

	cout <<  N - answer;

}
