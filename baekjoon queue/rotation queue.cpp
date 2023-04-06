#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 
	지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다. 지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.
	
	*/

	//큐에 처음에 포함되어 있던 수 N이 주어진다
	//지민이가 뽑아내려고 하는 원소의 M 위치가 주어진다.
	int N, M;  cin >> N >> M;
	deque<int> dq;
	for (int i = 0; i < N; i++) dq.push_back(i + 1);
	
	queue<int> find;
	for (int i = 0; i < M; i++) {
		int temp; cin >> temp;
		find.push(temp);
	}
	int cnt = 0;

	
	//이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.
	while (!find.empty()) {


		if ( dq.front() == find.front()) { 
			// 같을 경우
			find.pop();
			dq.pop_front();
			continue;
		}

		//먼저 원하는 원소가 어느 idx에 있는지 찾아봅니다.
		int idx;

		for (int i = 0; i < dq.size(); i++) {
			if (find.front() == dq[i]) {
				idx = i;
				break;
			}
		}

		//해당 인덱스가 뒤인지 앞인지 확인
		bool clock;

		//중간보다 앞에 있을 경우는 앞 데이터를 뒤로 보내는 편이 좋음
		if (dq.size() / 2 >= idx) clock = true;
		else clock = false;

		//왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak ->  a2, ..., ak, a1이 된다.
		if (clock) { // 정수 X를 덱의 뒤에 넣는다.
			

			while (!(dq.front() == find.front())) {
				int temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
				cnt++;
			}

			dq.pop_front();
			find.pop();

			
		}
		//오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
		else { 

			while (!(dq.front() == find.front())) {
				int temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
				cnt++;

			}

			dq.pop_front();
			find.pop();

		}

	}

	cout << cnt << endl;

	return 0;
}