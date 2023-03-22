#include <iostream>
using namespace std;

int main() {

	long long N; cin >>N;
    
	int Cnt = 1;
    long sum = 1;
    long temp = 1;

	while (true) {
		if (sum >= N) {
			cout << Cnt<< endl;
			break;
		}
        temp = 6 * (Cnt++);
		sum += temp;
    }

	return 0;
}
