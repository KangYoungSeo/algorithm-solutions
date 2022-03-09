#include <iostream>

using namespace std;

int main() {

	int N; cin >> N; if (N < 3 || N > 100) return 0;
	int M; cin >> M; if (M < 10 || M > 300000) return 0;

	int* num = new int[N];
	for (int i = 0; i < N; i++) cin >> num[i];
	//숫자 입력칸

	int min = 9999999999;
	int result;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = num[i] + num[j] + num[k];
				int dis = M - sum;
				if (dis >= 0 && dis < min) {
					min = dis;
					result = sum;
                    if(result == M){
                        cout <<result << endl;
                        return 0;
                    }
				}

			}
		}
	}

	cout << result << endl;

	return 0;
}
