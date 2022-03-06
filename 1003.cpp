#include <iostream>
using namespace std;

int main() {

	int T; cin >> T;
	int* Rzero = new int[T];
	int* Rone = new int[T];

	for(int j = 0; j < T ; j++) {
		int M; cin >> M; 

		int* zero = new int[M +1];
		int* one = new int[M + 1];
		
		zero[0] = 1; one[0] = 0;
		zero[1] = 0; one[1] = 1;

		for (int i = 2; i <= M; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
			one[i] = one[i - 1] + one[i - 2];

		}
		Rzero[j] = zero[M]; Rone[j] = one[M];
	}

	for (int i = 0; i < T; i++)
		cout << Rzero[i] << ' ' << Rone[i] << endl;
	

	return 0;
}
