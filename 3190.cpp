#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int board[102][102]; 
int dx[4] = {0,1,0,-1}; 
int dy[4] = {1,0,-1,0}; 

int main() { 
	//init 입력출력 줄이기
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 

	//input
	int n,k; cin >> n >> k; 
	
	//사과 위치 입력
	for(int i=0;i<k;i++) { 
		int x, y; cin >> x >> y; 
		board[x][y] = 4; 
	} 
	
	// 방향 입력
	int L; cin >> L;
	vector<pair<int, char>> turnInfo; 

	//방향 전환 input
	for(int i=0;i<L;i++) { 
		int sec; 
		char dir; 
		cin >> sec >> dir; 
		turnInfo.push_back({sec, dir}); 
	} 
	
	int time =0; 
	pair<int, int> head = {1,1}; 
	int dir = 0; 
	int index = 0; 

	//뱀이 어느 x, y 값에 존재하는지 queue에 저장
	queue<pair<int, int>> snake; 
	//시작에 뱀 표시 (1,1)

	board[1][1] = 2; 
	snake.push(head);

	//게임 시작 
	while(1) { 
		//1초 추가 
		time++; 

		//머리 go
		head.first += dx[dir]; 
		head.second += dy[dir]; 
		
		int nx = head.first; 
		int ny = head.second; 
		
		//벽, 몸통인경우 종료.
		if(nx > n || ny > n || nx < 1 || ny < 1 || board[nx][ny] == 2) { 
			cout << time; 
			return 0; 
		}

		//빈칸이면 꼬리 제거 
		else if(board[nx][ny] == 0) { 
			pair<int, int> cur = snake.front(); 
			snake.pop(); 
			board[cur.first][cur.second] = 0; 
		} 

		//꼬리 제거 X 머리 push
		board[nx][ny] = 2; 
		snake.push({nx, ny}); 
		
		//입력받은 방향 전환 시간과, 현재 시간이 일치하면 방향 전환 
		if(time == turnInfo[index].first) { 
			if(turnInfo[index].second == 'D') { 
				//오른쪽 90도 회전
				dir = (dir+1) % 4; 
				index++; 
			} 
			else if(turnInfo[index].second == 'L') { 
				//왼쪽 90도 회전
				dir = (dir+3) % 4; 
				index++; 
			} 
		} 
	} 
}
