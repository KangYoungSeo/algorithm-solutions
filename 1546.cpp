#include <iostream>
using namespace std;
int main()
{
	int max = 0;
	int N; cin >> N;
	double* score = new double[N];
	for (int i = 0; i < N; i++) { 
		cin >> score[i]; 
		if (max < score[i]) max = score[i];
	}
	double result = 0;
	for (int i = 0; i < N; i++) {
		score[i] = score[i] / max * 100;
		result += score[i];
	}
	cout <<(double) result / N << endl;
	return 0;
}
