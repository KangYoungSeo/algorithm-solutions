#include <iostream>
#include <vector>

using namespace std;

int main() {

	// get number by int type
	int N; cin >> N;
	int temp = N;
	vector<int> list;

	// loop for check number
	// divide 10 and get remainder 
	int idx = 0;
	int total = 0;
	while (temp > 0) {

		int left = temp % 10;
		list.push_back(left);
		temp = temp / 10;
		idx++;
		total += left;
	}

	idx = idx / 2;

	// divide right & left
	int right = 0;
	for (int i = 0; i < idx; i++) right += list[i];
	int left = total - right;

	//print
	if (left == right) printf("LUCKY\n");
	else printf("READY\n");

	return 0;
}
