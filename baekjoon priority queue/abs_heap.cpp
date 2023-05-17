#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2)) 
			return true;
		else if (abs(n1) == abs(n2)) {
			if (n1 > n2) return true;
			else return false;
		}
		return false;

	}
};

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	/*
	절댓값 힙
	*/


	// 첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 
	int N; cin >> N; 
	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < N; i++) {
		//다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
		int x; cin >> x;

		// x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, 
		else pq.push(x);
	}

	return 0;
}