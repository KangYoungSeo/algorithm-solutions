#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	/*
	최대힙
	*/

	// 첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다
	int N; cin >> N; 
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		// 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다
		int x; cin >> x;

		//x가 0이라면 배열에서 가장 큰 값을 출력
		if (x == 0) {
			if(pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// 만약 x가 자연수라면 배열에 x라는 값을 넣음 
		else if (x > 0) pq.push(x);
	}

	return 0;
}