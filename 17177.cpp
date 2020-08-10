#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int max = 0;
	int arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	int min1, min2;
	max = arr[0];
	min1 = arr[1];
	min2 = arr[2];

	double degak1 = sqrt((max*max) - (min1 * min1));
	double degak2 = sqrt((max*max) - (min2 * min2));

	if (degak1 <= 0 || degak2 <= 0) {
		cout <<-1;
		return 0;
	}
	double answer = ((degak1 * degak2) - (min1 * min2)) / max;
	if (answer <= 0) {
		cout << -1;
		return 0;
	}
	cout << answer;
}
