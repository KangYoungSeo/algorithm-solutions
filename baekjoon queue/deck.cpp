#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

	주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
	
	*/

	int N;  cin >> N; // 명령의 수 (1 ≤ N ≤ 10,000)
	deque<int> dq;

	while (N--> 0) {

		string order; cin >> order;

		if (order == "push_front") { //  정수 X를 덱의 앞에 넣는다.
			int num; cin >> num;
			dq.push_front(num);

		}
		else if (order == "push_back") { // 정수 X를 덱의 뒤에 넣는다.
			int num; cin >> num;
			dq.push_back(num);
		}
		else if (order == "pop_front") { 
			// 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 
			// 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (order == "pop_back") {
			//덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 
			//만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (dq.empty()) cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}

		else if (order == "size") {
			//size: 덱에 들어있는 정수의 개수를 출력한다.
			cout << dq.size() << endl;

		}
		else if (order == "empty") {
			//empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
			cout << dq.empty() << endl;
		}
		else if (order == "front") {
			//front: 덱의 가장 앞에 있는 정수를 출력한다.
			//만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
			if (dq.empty()) cout << -1 << endl;
			else cout << dq.front() << endl;
		}
		else if (order == "back") {
			// back: 덱의 가장 뒤에 있는 정수를 출력한다. 
			// 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
			if (dq.empty()) cout << -1 << endl;
			else cout << dq.back() << endl;

		}
	}

	return 0;
}