#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//이모티콘 S개 만들기

//초기 화면 : 1개
//1.화면에 있는 이모티콘 모두 클립보드 복사 
//2. 클립보드 이모티콘 화면에 붙여넣기
//3. 화면 있는 이모티콘 하나 삭제

int time[1001];
bool check[1001][1001];		//화면에 이모티콘수 , 클립보드 수

queue<pair<int, pair<int,int>>> q;		//화면에 이모티콘 개수 , 클립보드 개수  , 시간

void BFS() {

	q.push({ 1,{0,0} });
	check[1][0] = true;			

	while (!q.empty()) {
		int now = q.front().first;
		int clip = q.front().second.first;
		int t = q.front().second.second;

		q.pop();

		//최솟값이면 update
		if (t < time[now]) time[now] = t;


		//화면 -> 클립보드
		if (!check[now][now]) {
			check[now][now] = true;
			q.push({ now , {now , t + 1} });
		}
		//클립보드 -> 화면
		if (now + clip <= 1000 && !check[now + clip][clip]) {
			check[now + clip][clip] = true;
			q.push({ now + clip , {clip , t + 1}});
		}

		//화면-1
		if (now -1 >= 0 && !check[now - 1][clip]) {
			check[now - 1][clip] = true;
			q.push({ now - 1 , {clip , t + 1} });
		}

		
	}
}
int main() {
	
	//time초기화
	for (int i = 0; i <= 1000; i++) time[i] = 987654321;

	BFS();

	int S;
	cin >> S;
	cout << time[S];
}
