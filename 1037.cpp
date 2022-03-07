#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	int*num = new int[N];
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num,num + N);
	if (N % 2 == 0) cout << num[0] * num[N - 1];
	else cout << num[N / 2] * num[N / 2];
	return 0;
}
