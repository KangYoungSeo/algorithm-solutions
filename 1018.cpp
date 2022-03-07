#include <iostream>
using namespace std;

int main() {

	int N; cin >> N; 
	int M; cin >> M;

	char** arr = new char*[N]; 
	for (int i = 0; i < N; i++) { 
		arr[i] = new char[M]; 
		cin >> arr[i];
	}
	//모든 변수 선언 및 입력

	int min = 9999999999999;
	for (int k = 0; k < N - 7; k++) {
		for (int l = 0; l < M - 7; l++) {
			int CntB = 0;
			int CntW = 0;
		
			for (int i = k; i < 8 + k; i++) {
				for (int j = l; j < 8 + l; j++) {
					if ((i + j) % 2 == 0) {
						if (arr[i][j] == 'B')
							CntW++;
						else
							CntB++;
					}
					else {
						if (arr[i][j] == 'B')
							CntB++;
						else
							CntW++;
					}
				}

			}
			int temp = CntB < CntW ? CntB : CntW;
			min = temp < min ? temp : min;

		}
	}
	
	cout << min << endl;
	return 0;

}
