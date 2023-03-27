#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int result = a * b;
	int num[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		num[i] = b % 10;
		b = b / 10;
	}
	
	cout << a * num[0] << endl;
	cout << a * num[1] << endl;
	cout << a * num[2] << endl;
	cout << result << endl;
	return 0;
}