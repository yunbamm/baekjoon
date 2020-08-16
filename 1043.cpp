#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//진실을 아는 사람과 같은 파티에 있는 사람은 지신을 안다
//queue에 진실을 아는사람을 넣고 , 그사람이 가는 파티를 봐서 새로진실을 알게되는 사람을 push

int N, M;
queue<int> q;
vector<vector<int>> party(51);		//사람이 출석하는 party
vector<vector<int>> person(51);		//party에 출석하는 사람

bool check_party[51];
bool check_person[51];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	//진실을 아는 사람 수 , 사람 번호
	int num , tmp;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> tmp;
		q.push(tmp);
		check_person[tmp] = true;
	}
	
	//파티에 참석하는 사람 수 , 사람번호 
	for (int m = 1; m <= M; m++) {
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> tmp;
			person[m].push_back(tmp);
			party[tmp].push_back(m);
		}
	}

	
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		//진실을 아는사람이 참석하는 party를 확인
		for (int i = 0; i < party[now].size(); i++) {
			int now_party = party[now][i];

			//현재 party를 확인한적이 없으면
			if (!check_party[now_party]) {
				check_party[now_party] = true;

				//현재 party에 참여한 사람들 확인
				for (int j = 0; j < person[now_party].size(); j++) {
					int now_person = person[now_party][j];
					
					//현재 사람을 확인한적이 없으면
					if (!check_person[now_person]) {
						check_person[now_person] = true;
						q.push(now_person);
					}

				}

			}

		}
	}
	int answer = 0;
	for (int i = 1; i <= M; i++) {
		if (!check_party[i]) {
			answer++;
		}
	}

	cout << answer;
}



