#include <iostream>
#include <string>
using namespace std;

int N;
int* A;
int* opr;
int oprCnt[4] = { 0,0,0,0 }; //세는 거
long long int MINresult;
long long int MAXresult;


void count(int idx, long long int result) {

	for (int j = 0; j < 4; j++) {
		if (oprCnt[j] != opr[j]) {
			int before = result;
			switch (j) {
			case 0:
				result += A[idx]; break;
			case 1:
				result -= A[idx]; break;
			case 2:
				result *= A[idx]; break;
			case 3:
				result /= A[idx]; break;
			}
			oprCnt[j]++;
			
			if (idx == N - 1) {
				if (MINresult > result) MINresult = result;
				if (MAXresult < result) MAXresult = result;
			}
			else count(idx + 1, result);
			result = before;
			oprCnt[j] --;
		}
    }
}

int main() {
	 cin >> N;
	 A = new int[N];for (int i = 0; i < N; i++) cin >> A[i];
	opr = new int[4];for (int i = 0; i < 4; i++) cin >> opr[i];
	

	MAXresult = -1000000000;
	MINresult = 1000000000;
	count(1, A[0]);


	cout << MAXresult << endl;
	cout << MINresult << endl;
	
	return 0;

}
