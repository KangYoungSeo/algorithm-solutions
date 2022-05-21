#include <iostream>
using namespace std;

int main() {

	//int Cnt[7] = { 0, };

	int A, B, C; 
	int max, result;
	cin >> A >> B >> C;

	if (A == B && A == C) result = 10000 + A * 1000;
	else if (A == B) result = 1000 + A * 100;
	else if (B == C) result = 1000 + B * 100;
	else if (A == C) result = 1000 + A * 100;
	else {
		max = A > C ? A : C;
		max = B > max ? B : max;
		result = 100 * max;
	}

	cout << result << endl;
	return 0;
}
