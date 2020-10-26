#include<iostream>

using namespace std;

//세그먼트 트리

int N, Q;		//수의개수 , 턴의 개수
int x, y, a;
long long b;
//x y  a b -> x~y까지 출력 a번쨰를 b로 바꿔라

//트리를 배열로 나타낸다
long long arr[100001] = { 0 };
long long tree[100001 * 4] = { 0 };

//초기 세그먼트 트리 생성
long long init(int left, int right, int node) {

	//leaf 노드이면
	if (left == right) {
		tree[node] = arr[left];
		return tree[node];
	}
	int mid = (left + right) / 2;
	return tree[node] = init(left, mid, node * 2) + init(mid + 1, right, node * 2 + 1);
}

//a가 속하는 node들마다 +diff를 해준다
void update(int left , int right , int a , long long diff,int node) {
	//범위가 벗어나면 원래 node값 return
	if (a < left || right < a) return;

	//a가 속해있는 범위면 +diff
	tree[node] += diff;

	//a범위의 노드면 left , right를 볼필요X
	if (left == right && right == a) return;

	//a가 속해있는 노드면 left, right로 내려간다
	int mid = (left + right) / 2;
	update(left, mid, a, diff,node * 2);
	update(mid + 1, right, a, diff,node * 2 + 1);
}
//x~y에 해당하는 값들의 합 찾기
long long find(int left, int right, int x, int y, int node) {

	//완전범위가 벗어나면 끝
	if (right < x || left > y) {
		return 0;
	}
	//범위가 완전 겹치면
	if (x <= left && right <= y) {
		return tree[node];
	}
	//일부분 겹치면 left right로 내려가야한다
	int mid = (left + right) / 2;
	return find(left, mid, x, y, node * 2) + find(mid + 1, right, x, y, node * 2 + 1);

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	//초기 세그먼트트리 생성
	init(1, N, 1);

	
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		//탐색
		if (x > y) {
			cout << find(1, N, y, x, 1) << "\n";
		}
		else cout << find(1, N, x, y, 1) << "\n";
		//수정
		long long diff = b - arr[a];
		arr[a] = b;
		update(1, N, a, diff,1);
	}
}
