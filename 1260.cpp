#include <iostream>
#include<queue>

using namespace std;
static int N; //정점의 개수
static int M; //간선의 개수
static int V;
static bool connected[1001][1001];
static bool checked[1001];
queue<int> q;

void dfs(int node);
void bfs(int node);

int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int cnn1, cnn2;
		scanf("%d %d", &cnn1, &cnn2);
		connected[cnn1][cnn2] = true;
		connected[cnn2][cnn1] = true;

	}
	dfs(V);
	printf("\n");
	for (int i = 0; i <= N; i++) checked[i] = false;

	bfs(V);
	return 0;

}

void dfs(int node) {

	checked[node] = true;
	cout << node << " ";
	for (int j = 1; j <= N; j++) {
		if (connected[node][j] == true && checked[j] == false) {
			dfs(j);
		}
	}
}

void bfs(int v) {
	
	q.push(v);
	checked[v] = true;
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";
		
		for (int i = 1; i <= N; i++) {
			if (!checked[i] && connected[v][i] == true) {
				checked[i] = true;
				q.push(i);
			}
		}
	}
}
