#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 맨 왼쪽은 0번째라고 하자. 두 번째 줄에는 N개 문서의 중요도가 차례대로 주어진다. 
	// 중요도는 1 이상 9 이하의 정수이고, 중요도가 같은 문서가 여러 개 있을 수도 있다.

	int T;  cin >> T; // 첫 줄에 테스트케이스의 수
	while (T--> 0) {
		int N; cin >> N; //문서의 개수 N(1 ≤ N ≤ 100)
		int M; cin >> M; // 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지를 나타내는 정수 M
		//첫번째 queue에 있는 M번째에 있는 값이 몇번째로 인쇄 되는지 확인하는 문제
		//중요도는 '순서'가 아님. 그저 수치일 뿐.

		queue<pair<int,int>> list;
		priority_queue<int> pq; // 우선순위 큐

		int MAX = 0;
		int cnt = 0;
		
		for(int i = 0; i < N; i++) {
			int temp;  cin >> temp;
			list.push(make_pair(temp,i));
			pq.push(temp);

			//마지막 최대값을 확인하기
			if (temp > MAX) MAX = temp;
		}

		//queue 탐색
		while (!list.empty()) {

			//맨 앞의 값을 확인하자
			int value = list.front().first;
			int idx = list.front().second;

			list.pop();

			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (idx ==M) {
					cout << cnt << endl;
					break;
				}
			}
			else list.push(make_pair( value, idx ));
		}
		
	}

	return 0;
}