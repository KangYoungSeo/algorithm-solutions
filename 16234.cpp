#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

	fast_io();

	//input
	int N; cin >> N;
	vector<int> home;
	int result = 1000001;
	int answer = 0;

	for (int i = 0; i < N; i++) {
		int c; cin >> c; home.push_back(c);
	}

	//정렬
	sort(home.begin(), home.end());
	cout << home[(N - 1) / 2];

	return 0;
}
