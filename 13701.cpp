#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//!!!!!!!!!!!!!!!!! 비트를 사용
//int 는 32bit 그니까 0~31까지 숫자가 들어왔는지 확인가능

int arr[1 << 20];  //2^20 * 2^5 => 2^25

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	int num;
	while (1){
		cin >> num;
		if (cin.eof()) break;
		int x = num / 32;
		int y = num % 32;

		if (arr[x] & (1 << y)) continue;
		else {
			cout << num << " ";
			arr[x] |= (1 << y);
		}
	}
}
