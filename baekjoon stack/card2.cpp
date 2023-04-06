#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;
int main() {
	queue<int> num = {};
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) num.push(i);

	while (num.size() != 1) {
		num.pop();
		if (num.size() == 1) break;
		int temp = num.front();
		num.pop();
		num.push(temp);
	}
	printf("%d", num.front());
	return 0;
}