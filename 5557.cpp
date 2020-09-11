#include<iostream>

using namespace std;

//?DP란다

int arr[101];
long long check[21] = { 0 };		//현재 단계에 i값이 몇개있는지
long long tmp[21] = { 0 };			//복사용
int N;

int main() {
	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	//처음값을 넣는다
	check[arr[0]] = 1;
	for (int n = 1; n < N - 1; n++) {

		//0~20까지 숫자가 유효하니까
		for (int i = 0; i <= 20; i++) {
			//지금까지 연산을 통해 i가 나올수있다면
			if (check[i] != 0) {
				//현재 arr값을 더한값이 20이하면
				if (i + arr[n] <= 20) tmp[i + arr[n]] += check[i];
				//현재 arr값을 뺀값이 0이상이면
				if (i - arr[n] >= 0) tmp[i - arr[n]] += check[i];
			}
		}

		//tmp값을 복사
		for (int i = 0; i <= 20; i++) {
			if (tmp != 0) check[i] = tmp[i];
			
			else check[i] = 0;
			tmp[i] = 0;
		}
	}

	cout << check[arr[N - 1]];
}
