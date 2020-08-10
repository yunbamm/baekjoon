#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//DFS해서 4이상?
//1. check를 false로 업데이트 안해준거 2. sum이 4이상일때 안멈추고 계속해줘서 시간초과 3. DFS시작할때 check를 안해준거 

int N, M;	//사람수 , 관계수 
vector<vector<int>> v(2000);
bool check[2000];
bool flag = false;
void DFS(int start, int now, int sum) {

	if (sum >= 4) {
		flag = true;
		return;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!check[next]) {
			check[next] = true;
			DFS(start, next, sum + 1);
			check[next] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	
	int p1, p2;
	for (int m = 0; m < M; m++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}


	for (int i = 0; i <= N - 1; i++) {
		//check초기화
		for (int j = 0; j < 2000; j++) check[j] = false;
		check[i] = true;
		DFS(i, i, 0);
		check[i] = false;
		if (flag) break;
	}

	if (flag) cout << "1";
	else cout << "0";
}
