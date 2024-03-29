#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	/*
	정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
	명령은 총 다섯 가지이다.
	*/

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
	첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
	주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
	문제에 나와있지 않은 명령이 주어지는 경우는 없다.
	
	*/

	int N;  cin >> N;

	vector<int> stack;
	
	//Q1 : string 비교 할 때 이렇게 (==으로) 해도 되는 것일까??? 내 기억으론 비교 방법이 있었는데
	// -> .compare 함수를 활용한다. 같을 경우 ==> 0, 다를 경우 ==> 1 을 활용한다.

	for (int i = 0; i < N; i++) {
		// 명령어 하나 입력
		string temp; cin >> temp;
		int num;

		//값 push 일 경우
		//push X : 정수 X를 스택에 넣는 연산이다.
		if (temp == "push") {
			cin >> num;
			stack.push_back(num);
		}
		//pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
		//만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		else if (temp == "pop") {
			if (stack.empty()) cout << -1 << endl;
			else {
				cout << stack.back() << endl;
				stack.pop_back();
			}
		}
		//size: 스택에 들어있는 정수의 개수를 출력한다.
		else if (temp == "size") {
			cout << stack.size() << endl;
		}
		//empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
		else if (temp == "empty") {
			cout << stack.empty() << endl;
		}
		//top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
		else if (temp == "top") {
			if (stack.empty()) cout << -1 << endl;
			else cout << stack.back() << endl;
			
		}
	}

	return 0;
}