#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


int main() {
	
    //테스트 케이스 입력
	int t; scanf("%d", &t);
	queue<int> queue = {};


	while (t-->0) {

        //명령어 입력
		char cmd[100]; scanf("%s", cmd);

        //push
		if (!strcmp(cmd, "push")) {
			int n; scanf("%d", &n);
			queue.push(n);
		}
        //pop
		if (!strcmp(cmd, "pop")) {
			if (queue.empty()) printf("-1\n");
			else {
				printf("%d\n", queue.front());
				queue.pop();
			}
		}
		if (!strcmp(cmd, "size")) {
			printf("%d\n", queue.size());
		}
		if (!strcmp(cmd, "empty")) {
			if (queue.empty()) printf("1\n");
			else printf("0\n");
		}
		if (!strcmp(cmd, "front")) {
			if (queue.empty()) printf("-1\n");
			else printf("%d\n",queue.front());
		}
		if (!strcmp(cmd, "back")) {
			if (queue.empty()) printf("-1\n");
			else printf("%d\n", queue.back());
		}
	}
	return 0;
}