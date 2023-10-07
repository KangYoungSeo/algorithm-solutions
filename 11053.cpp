#include <iostream>
using namespace std;

int N;
int* num;
int* result;

int LIS(int idx) {
    
	int& ret = result[idx + 1];
    
	if (ret != -1) return ret;
    
	ret = 1;
    
	for (int i = idx + 1; i < N ; i++) {
		if (idx == -1 || num[idx] < num[i]) {
			int temp;
			temp = LIS(i) + 1;
			if (idx == -1) temp--;
			ret = ret < temp ? temp : ret;
		}
	}
	return ret;
}

int main() {
    
    //input
	cin >> N;
	num = new int[N]; result = new int[N +1];
	for (int i = 0; i < N; i++) {
		cin >> num[i]; result[i] = -1;
	}
    
	result[N] = -1;
	cout << LIS(-1) << endl;
	return 0;
}