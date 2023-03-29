#include <cstdio>
#include <vector>
using namespace std;
int main() {
	vector<int> stack;
	int stackNum = 1;
	int n; scanf("%d",&n);
	int* arr = new int[n];
	for (int i = 0; i < n; i++)  scanf("%d", &arr[i]);
	vector<char> result;
	for (int i = 0; i < n; i++) {
		int& status = arr[i];
		while (stackNum <= status){
			stack.push_back(stackNum++);
			result.push_back('+');
		}
		if (stack.back() == status) {
			stack.pop_back();
			result.push_back('-');
		}
		else {
			printf("NO"); return 0;
		}
	}
	for (int i = 0; i < result.size(); i++)printf("%c\n", result[i]);
	return 0;
}