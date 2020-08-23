#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

//자릿수 * 10을해서 더한다

//A(65) Z(90)
long long arr[26] = { 0 };		//자릿수 합
int fix_num[26] = { 0 };		//부여된 숫자
vector<string> v;				//입력받은 문자열

int N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	//입력
	cin >> N;
	
	string tmp;
	for (int n = 0; n < N; n++) {
		cin >> tmp;

		v.push_back(tmp);

		queue<char> q;
		for (int i = 0; i < tmp.size(); i++) {
			q.push(tmp[i]);
		}
		//자릿수 더해주기
		while (!q.empty()) {
			int c = q.front();
			q.pop();
			int num = q.size();
			int add = 1;

			while (num--)
			{
				add *= 10;
			}
			arr[c - 'A'] += add;
			num--;
		}
	}

	//합계 , 문자index
	priority_queue<pair<int, int>> pq;

	//한번이라도 등장한 애들을 pq에 들어간다 (최대 10개)
	for (int i = 0; i < 26; i++) {
		if (arr[i] != 0) {
			pq.push({ arr[i],i });
		}
	}

	//숫자부여
	int N = 9;
	while (!pq.empty())
	{
		int index = pq.top().second;
		pq.pop();

		fix_num[index] = N;
		N--;

	}
	//문자열 보면서 답을 구한다
	long long answer = 0;
	for (int i = 0; i < v.size(); i++) {
		string ss = v[i];

		int tmp_num = 0;
		for (int j = 0; j < ss.size(); j++) {
			tmp_num *= 10;
			tmp_num += fix_num[ss[j] - 'A'];
		}
		answer += tmp_num;
	}

	cout << answer;
}
