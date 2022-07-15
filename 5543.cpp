#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int* score = new int[5];
	int min = 999999999;
	for (int i = 0; i < 5; i++) 
		cin >> score[i];
	for (int i = 0; i < 3; i++) {
		if (min > score[i]) min = score[i];
	}
	if (score[3] > score[4]) min += (score[4] - 50);
	else  min += (score[3] - 50);
	cout << min << endl;
	return 0;
}
