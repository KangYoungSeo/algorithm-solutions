#include <iostream>
using namespace std;

int main() {

	int A, B, C; cin >> A >> B >> C;
	
	if (B + C > 59) {
		int temp = (B + C) / 60;
		A += temp;
		B -= temp * 60;
	}
	B += C;
	if (A > 23) { A -= 24; }

	cout << A << " "<< B << endl;
	return 0;
}
