#include <string>
#include <vector>

using namespace std;

//s길이 : 1~5
//s의 맨앞 + , -

int solution(string s) {
	int answer = 0;
	int index = 0;
	bool flag = true;		//true면 양수 , false면 양수
	if (s[0] == '-') {
		index++;
		flag = false;
	}
	if (s[0] == '+') {
		index++;
	}
	for (int i = index; i < s.size(); i++) {
		answer *= 10;
		answer += s[i] - '0';
	}

	if (!flag) answer = answer * -1;
	return answer;
}
