#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> time;
int n;

int compute() {

	int sum = 0,answer=0;
	sort(time.begin(), time.end());

	for (int i = 0; i < time.size(); i++) {
		sum += time[i];
		answer += sum;
	}
	return answer;

}



int main(void) {

	cin >> n;
	time.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}
	cout << compute();
	return 0;
}