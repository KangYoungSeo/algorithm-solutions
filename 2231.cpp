#include <iostream>
using namespace std;

int main() {

	int N; cin >> N; if (N < 1 || N > 1000000) return 0;

	for (int i = 1; i < N; i++) {

		int sum = i; int num = i;

		while(num != 0) {
			sum += num % 10;
			num = num / 10;

		}
		if (sum == N) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}
