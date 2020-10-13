#include<iostream>
#include<queue>

using namespace std;

int arr[6];

void swap(int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void print() {
	for (int i = 1; i <= 5; i++) cout << arr[i] << " ";
	cout << "\n";
}
int main() {
	
	for (int i = 1; i <= 5; i++) cin >> arr[i];

	while (1) {
		//1~4위치변경
		for (int i = 1; i <= 4; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);

				//출력
				print();
			}
		}
		//5.1 2 3 4 5 순서인지 확인
		bool flag = true;
		for (int i = 1; i <= 5; i++) {
			if (arr[i] != i) {
				flag = false;
				break;
			}
		}

		if (flag) break;
	}
}
