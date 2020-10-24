#include<iostream>
#include<vector>

using namespace std;

int n;		//정점개수
vector<int> in;
vector<int> post;

//항상 end쪽이 root라고 생각하면 된다
void dfs(int in_start, int in_end , int post_start , int post_end) {

	if (in_start > in_end || post_start > post_end) return;

	//항상 현재의 루트는 post[post_end]
	int now = post[post_end];
	cout << now << " ";

	int now_index = 0;
	for (int i = in_start; i <= in_end; i++) {
		if (now == in[i]) {
			now_index = i;
			break;
		}
	}
	int left_size = now_index - in_start;
	int right_size = in_end - now_index;
	
	//left부분
	dfs(in_start, now_index - 1, post_start, post_start + (left_size - 1));
	//right부분
	dfs(now_index + 1, in_end, post_end  - right_size, post_end - 1);
}
int main() {
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		in.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		post.push_back(tmp);
	}
	dfs(0, n-1, 0, n-1);
	
}
