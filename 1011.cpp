#include <iostream>
using namespace std;

int main() {

	int T; cin >> T;

	for (int j = 0; j < T; j++) {
		int x; cin >> x; if (x < 0) return 0;
		int y; cin >> y; if (y < x || y > 100000000000000000) return 0;

		long long int i = 1, cnt = 0;

		while (true) {
			i++; if (i*i > y - x) break;
		}

		if ((i - 1)*(i - 1) == y - x)
			cnt = 2 * (i - 1) - 1;
		else if((i - 1)*(i - 1) + ((i*i - (i - 1)*(i - 1)) / 2) >= y - x)
			cnt = 2 * i - 2;
		// 중간지점 < y-x < i의 제곱수 인 경우
		else
			cnt = 2 * i - 1;
		cout << cnt << endl;

	}

	return 0;
}
