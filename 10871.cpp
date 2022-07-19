#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N, X; cin >> N >> X;
	int* A = new int[N];
	vector<int> answer = {};
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < X) answer.push_back(A[i]);
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	return 0;
}
