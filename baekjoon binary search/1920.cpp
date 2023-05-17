#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 
	int N;  cin >> N;
	bool found = false;
	int temp;
	 
	
	//다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다.
	vector<int> list;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		list.push_back(temp);
	}

	//정렬
	sort(list.begin(), list.end());


	// 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 
	int M; cin >> M;


	//다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
	for (int i = 0; i < M; i++) {
		cin >> temp;

		int first = 0;
		int end = N - 1;
		int mid;

		while (end >= first) {

			mid = (first + end) / 2;

			//같을 경우
			if (list[mid] == temp) {
				found = true;
				break;
			}

			//클 경우, 
			else if (list[mid] > temp) end = mid - 1;

			//작을 경우
			else first = mid + 1;


		}
		// M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
		cout << found << '\n';

		found = false;
	}

	return 0;
}