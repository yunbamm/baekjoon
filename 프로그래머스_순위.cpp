#include <string>
#include <vector>

using namespace std;

#define INF 987654321

//플로이드 와샬?	
//ex) src 가 i 한테 지는데 i 가 dest한테 지면 src는 dest한테 진다
//ex) src 가 i 한테 이기는데 i 가 dest한테 이기면 src는 dest를 이긴다
//자기를 제외한 n-1개와의 승부결과를 모두 알면 자기 순위는 확실히 알수있다

int arr[101][101];			//1(이긴다) -1(진다) INF(모른다)

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	//arr를 초기화 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	//results에서 정보를 빼온다
	for (int i = 0; i < results.size(); i++) {
		int win = results[i][0];
		int lose = results[i][1];
		arr[win][lose] = 1;
		arr[lose][win] = -1;
	}

	//플로이드 시작
	//i번째와의 결과를 통해 알수있는값 update
	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				//i와의 결과를 모르면 볼필요가 없다
				if (arr[x][i] == INF) continue;
				if (arr[x][i] == arr[i][y]) arr[x][y] = arr[x][i];
			}
		}
	}
	//정답 찾기
	for (int x = 1; x <= n; x++) {
		int count = 0;
		for (int y = 1; y <= n; y++) {
			if (arr[x][y] != INF) count++;
		}
		//자기를 제외하고 다른상대와의 승패를 안다면 자기 순위를 알수있다
		if (count == n - 1) answer++;
	}

	return answer;
}
