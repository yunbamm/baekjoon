#include <string>
#include <vector>
#include<iostream>
#include <map>
#include<queue>

using namespace std;

#define INF 987654321

//한번에 한개의 알파벳
//words에 있는 단어로만 변환가능
map<string, int> m;
queue<pair<string,int>> q;		//단어 , 변경횟수
map<string, int>::iterator iter;

//한자리수만 다른지 확인
bool check(string s1, string s2) {
	
	int tmp = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) tmp++;
	}
	
	if (tmp == 1) return true;
	else return false;
}

//탐색
void BFS() {
	while (!q.empty()) {
		string now = q.front().first;
		int cost = q.front().second;
		q.pop();

		//지금까지 찾은 최소 횟수보다 현재 cost가 크면 무시
		if (m.find(now)->second < cost) continue;

		//m을 탐색
		for (iter = m.begin(); iter != m.end(); iter++) {
			string next = iter->first;

			////now == next면 무시
			//if (now == next) continue;

			//한자리만 변경해서 next로 만들수있는지 확인
			if (check(now, next)) {
				if (m.find(next)->second > cost + 1) {
					m.find(next)->second = cost + 1;
					q.push({ next , cost + 1 });
				}
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	
	//map에 추가
	for (int i = 0; i < words.size(); i++) {
		m.insert({ words[i] , INF });
	}	
	//초기 q에 삽입
	q.push({ begin, 0 });

	BFS();
	int answer = 0;

	//있는경우
	if (m.find(target) != m.end()) {
		answer = m.find(target)->second;
	}

	return answer;
}
