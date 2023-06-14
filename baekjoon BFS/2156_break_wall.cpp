#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX][2]; // 벽을 부쉈는지 여부를 저장하는 배열

// 상하좌우 이동을 위한 배열
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int BFS() {

	queue<pair<pair<int, int>, int>> q;

	q.push({ {0, 0}, 1 }); // 시작 지점 (0, 0)부터 시작하며, 벽을 아직 부수지 않았음을 의미하는 1

	visited[0][0][1] = 1; // 시작 지점 방문 처리

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int isBreak = q.front().second;
		q.pop();

		// 도착 지점에 도달한 경우
		if (x == N - 1 && y == M - 1) {
			return visited[x][y][isBreak];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 범위를 벗어나는 경우 무시
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				continue;
			}

			// 이동할 위치가 벽인 경우
			if (map[nx][ny] == 1) {
				// 벽을 이미 부쉈거나, 방문한 적이 있는 경우 무시
				if (isBreak == 0 || visited[nx][ny][0] != 0) {
					continue;
				}

				// 벽을 부수고 이동
				visited[nx][ny][0] = visited[x][y][1] + 1;
				q.push({ {nx, ny}, 0 });
			}
			// 이동할 위치가 벽이 아닌 경우
			else {
				// 방문한 적이 있는 경우 무시
				if (visited[nx][ny][isBreak] != 0) {
					continue;
				}

				// 벽을 부수지 않고 이동
				visited[nx][ny][isBreak] = visited[x][y][isBreak] + 1;
				q.push({ {nx, ny}, isBreak });
			}
		}
	}

	return -1; // 도착 지점에 도달할 수 없는 경우
}

int main() {
	// 입력 받기
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			map[i][j] = (int) c - 48;
		}
	}

	// BFS 수행
	int result = BFS();

	// 결과 출력
	cout << result << endl;

	return 0;
}
