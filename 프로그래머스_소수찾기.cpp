#include <string>
#include <vector>
#include<iostream>

using namespace std;

//우선 에라토스테네스의체를 이용해서 소수 판별
bool check[10000000];		//false면 소수
bool use[10000000];			//이미 찾은소수인지
int num[10] = { 0 };
int answer = 0;
vector<int> v;
void process() {
	check[1] = true;			//1은따로 처리
	for (int i = 2; i <= 10000000; i++) {
		//소수인거의 배수들을 true로 바꿔주면 된다
		if (!check[i]) {
			for (int j = 2 * i; j <= 10000000; j += i) {
				check[j] = true;
			}
		}
	}
}
//size 크기를 가진 조합 만들기
void make(int size) {
	
	if (v.size() == size) {
		int tmp = 0;
		for (int i = 0; i < v.size(); i++) {
			tmp *= 10;
			tmp += v[i];
		}

		if (!use[tmp] && !check[tmp]) {
			use[tmp] = true;
			answer++;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] > 0) {
			num[i]--;
			v.push_back(i);
			make(size);
			v.pop_back();
			num[i]++;
		}
	}
}
int solution(string numbers) {

	process();		//소수를 먼저 찾아놓는다
	for (int i = 0; i < 10; i++) num[i] = 0;

	for (int i = 0; i < numbers.size(); i++) {
		char c = numbers[i];
		num[c - '0']++;
	}
	
	for (int i = 1; i <= numbers.size(); i++) {
		make(i);
	}
	return answer;
}
