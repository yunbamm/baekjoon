#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check[100000 * 20 + 1];
bool tmp_check[100000 * 20 + 1];
int N;
vector<int> v;

int main() {
	
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());

	//v를 본다
	for (int i = 0; i < v.size(); i++) {
		int now = v[i];

		//100000*20 +1까지 보면서 check가 true인걸 만나면 [index+v[i]]도 true로 바꾼다
		for (int j = 0; j <= 100000 * 20 + 1; j++) {
			if (check[j]) {
				tmp_check[j + now] = true; 
			}
		}

		//tmp_check가 된부분을 추가로 표시
		for (int j = 0; j <= 100000 * 20 + 1; j++) {
			if (tmp_check[j]) {
				check[j] = true;
				tmp_check[j] = false;

			}
		}

		//now를 true로
		check[now] = true;
	}

	for (int i = 1; i <= 100000 * 20 + 1; i++) {
		if (!check[i]) {
			cout << i << "\n";
			break;
		}
	}
}
