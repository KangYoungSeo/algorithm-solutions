#include <iostream>
#include <stack>
using namespace std;

int main() {

	/*
	장부 관리 but 장부 
	재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
	재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다.
	*/

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 
	int K;  cin >> K;
	stack<int> stack;

	//정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
	for (int i = 0; i < K; i++) {
		// 명령어 하나 입력
		int temp; cin >> temp;

		//값이 0일 경우
		if (temp == 0) stack.pop();
		
		//값 추가
		else stack.push(temp);
	}

	int sum = 0;
	//값을 합치기
	while (!stack.empty()) {
		int temp = stack.top();
		stack.pop();
		sum += temp;
	}

	cout << sum << endl;

	return 0;
}