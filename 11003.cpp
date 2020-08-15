#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
#include<stack>
#include<map>

using namespace std;

//1번으로 품

//1.
//pq를 이용하여 최솟값 후보들을 가지고 있는다
//현재 pq에 있는값은 무조건 pq.top에 있는값보다 index가 높다
//만약 pq.top에 있는값보다 작은게 나오면 pq를 비우고 push하면 된다
//만약 현재 pq.top에 있는 값이 i-L+1 ~ i 를 벗어난다면 pop해주고 다시 비교를 해주면 된다


//2. 최솟값 후보 2개를 가진다
//만약 젤작은 후보보다 작다면 v.clear() 후 push
//아니면 두번째값과 비교후 교체
//첫번째꺼가 범위를 벗어나면 두번째꺼가 첫번째로 가고 다시 비교
//12 3
//1 2 3 4 5 6 7 8 1 2 3 4
//이럴때 안된다

int N, L;
priority_queue<pair<int, int>> pq;		//-값 ,index
int answer[5000000];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	int tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;
        
        //후보가 없을때
		if (pq.empty()) {
			answer[n] = tmp;
			pq.push({ -tmp , n });
		}
        //후보존재시
		else {
            //현재 top이 index를 벗어나지 않을때까지 pop
			while (!pq.empty() && pq.top().second < n - L + 1) {
			pq.pop();
			}
            
			//if (pq.top().second < n - L + 1) pq.pop();
            
			//pq가 비었다면
			if (pq.empty()) {
				pq.push({ -tmp , n });
			}
			//아니라면 비교
			else {
				//tmp가 더 크다면
				if (-pq.top().first < tmp) {
					pq.push({ -tmp , n });
				}
                //tmp가 더 작다면 pq를 비우고 push
				else {
					while (!pq.empty())
					{
						pq.pop();
					}
					pq.push({ -tmp,n });
				}
			}

			answer[n] = -pq.top().first;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
}

