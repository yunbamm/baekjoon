#include<iostream>

using namespace std;

int N, M;			
int arr[10000] = { 0 };

//arr 자연수
int main() {
	
	cin >> N >> M;


	for (int i = 0; i < N; i++) cin >> arr[i];

	int i = 0, j = 0;

	int sum = arr[j];
	int answer = 0;
	while (j < N ) {
		//sum이 M보다 작으면
		if (sum < M) {
			j++;
			sum += arr[j];
		}
		//sum == M (i++ , j++)
		else if (sum == M) {
			sum -= arr[i];
			i++;
			j++;
			sum += arr[j];
			answer++;
		}
		//M보다 크면(i++)
		else {
			sum -= arr[i];
			i++;
		}

	}
	cout << answer;

}
