#include <iostream>
#include <queue>

using namespace std;

int N, M, K, temp;
int board[21][21];

int total;


//주사위 위치 좌표
int DiceX;
int DiceY;

//주사위 평면값 추가
int DiceUnder;
int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };

//주사위 이동 갑 
int DiceDirection;  // 동 -1, 남 - 2, 서 - 3, 북 - 4
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void compareGetDirection(){ //아래 값을 비교하여 방향을 변경한다

    /* 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교*/
    int boardNum = board[DiceY][DiceX];
    
    // A > B인 경우 이동 방향을 90도 시계 방향으로 회전
    if(DiceUnder > boardNum) DiceDirection++;
    
    //A < B인 경우 이동 방향을 90도 반시계 방향으로 회전
    else if (DiceUnder < boardNum) DiceDirection--;
}

void changeDiceUnder(){     
    
    //현재 주사위가 굴러간 방향에 맞춰 
    //주사위 위치값 + 바닥 숫자 변경

    int d = DiceDirection;
    
    int d1 = dice[1];
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d5 = dice[5];
	int d6 = dice[6];
 
	switch (d) {
	case 0 :
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
		break;
	case 1:
		dice[1] = d3;
		dice[3] = d6;
		dice[6] = d4;
		dice[4] = d1;
		break;
	case 2:
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
		dice[5] = d1;
		break;
	case 3:
		dice[1] = d5;
		dice[5] = d6;
		dice[6] = d2;
		dice[2] = d1;
		break;
	}
	
	DiceUnder = dice[1];
}

void moveDice(){    //주사위를 해당 위치로 옮긴다.

    int moveX = DiceX + dx[DiceDirection -1];
    int moveY = DiceY + dy[DiceDirection -1];
    
    //이동 좌표가 막혔을 경우 반대 방향으로 이동합니다.
    if(moveX >= N || moveX < 0 || moveY >= M || moveY < 0){
        DiceDirection = (DiceDirection + 2) % 4;
        
        moveX = DiceX + dx[DiceDirection];
        moveY = DiceY + dy[DiceDirection];
    }
    
    DiceX = moveX;
    DiceY = moveY;
    
    changeDiceUnder();
}

int canMove(){  //현재 diceX, diceY에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수를 반환
    
    // BFS
    int num = board[DiceY][DiceX];
	bool visit[21][21];
	int cnt = 1;
	
	int a = DiceX;
	int b = DiceY;
 
	queue<pair<int, int>> q;
	q.push(make_pair(a, b);
	visit[a][b] = true;
 
	while (q.empty() == 0) {
	    
	    //queue에서 맨 앞 값을 pop
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
    
        //해당 좌표의 동서 남북 중에
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//범위를 벗어나지 않음 + 방문하지 않음 + 주사위의 바닥 깂과 같은 블럭일 경우
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			    
			    //이동 + 이동횟수 추가 + queue에 반납하기
				if (board[nx][ny] == num && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
    
    return cnt;
}

void getScore(){        //현재 board의 x,y의 값을 얻는다
    
    //(x, y)에 있는 정수, B
    //(x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수, C
    int C = canMove();
    total += board[DiceY][DiceX] * C;
}

void input(){
    
    //첫째 줄에 지도의 세로 크기 N, 가로 크기 M (2 ≤ N, M ≤ 20), 
    //그리고 이동하는 횟수 K (1 ≤ K ≤ 1,000)가 주어진다.
    cin >> N >> M >> K;
    
    //지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수
    DiceX = 0; DiceY = 0; total = 0; DiceDirection = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp; board[j][i] = temp;
        }
    }
}

int main(){

    input();
    
    while(K-->0){
        
        moveDice();             //주사위를 정해진 방향대로 움직인다
        getScore();             //현재 board의 x,y 값을 얻는다
        compareGetDirection();  //아래 값을 비교하여 방향을 변경한다
    }

    cout << total << endl;
    return 0;
}



/*
#include <iostream>
#include <queue>

using namespace std;

int N, M, K, temp;
int board[21][21];

int total;


//주사위 위치 좌표
int DiceX;
int DiceY;

//주사위 평면값 추가
int DiceUnder;
int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };

//주사위 이동 갑 
int DiceDirection;  // 동 -1, 남 - 2, 서 - 3, 북 - 4
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



void compareGetDirection(){ //아래 값을 비교하여 방향을 변경한다

    //주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교
    int boardNum = board[DiceY][DiceX];
    
    // A > B인 경우 이동 방향을 90도 시계 방향으로 회전
    if(DiceUnder > boardNum) DiceDirection++;
    
    //A < B인 경우 이동 방향을 90도 반시계 방향으로 회전
    else if (DiceUnder < boardNum) DiceDirection--;
}

void changeDiceUnder(){     
    
    //현재 주사위가 굴러간 방향에 맞춰 
    //주사위 위치값 + 바닥 숫자 변경

    int d = DiceDirection;
    
    int d1 = dice[1];
	int d2 = dice[2];
	int d3 = dice[3];
	int d4 = dice[4];
	int d5 = dice[5];
	int d6 = dice[6];
 
	switch (d) {
	case 0 :
	    // 오른쪽
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
		dice[5] = d1;
		break;
	case 1:
	    //아래
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
		break;
	case 2:
	    // 왼쪽
		dice[1] = d5;
		dice[5] = d6;
		dice[6] = d2;
		dice[2] = d1;
		break;
	case 3:
	    //위
		dice[1] = d3;
		dice[3] = d6;
		dice[6] = d4;
		dice[4] = d1;
		break;
	}
	
	DiceUnder = dice[6];
}

void moveDice(){    //주사위를 해당 위치로 옮긴다.

    int moveX = DiceX + dx[DiceDirection];
    int moveY = DiceY + dy[DiceDirection];
    
    //이동 좌표가 막혔을 경우 반대 방향으로 이동합니다.
    if(moveX >= N || moveX < 0 || moveY >= M || moveY < 0){
        DiceDirection = (DiceDirection + 2) % 4;
        
        moveX = DiceX + dx[DiceDirection];
        moveY = DiceY + dy[DiceDirection];
    }
    
    DiceX = moveX;
    DiceY = moveY;
    
    changeDiceUnder();
}

int canMove(){  //현재 diceX, diceY에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수를 반환
    
    // BFS
    int num = board[DiceY][DiceX];
	bool visit[21][21];
	int cnt = 1;
	
	int a = DiceX;
	int b = DiceY;
 
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
 
	while (q.empty() == 0) {
	    
	    //queue에서 맨 앞 값을 pop
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
    
        //해당 좌표의 동서 남북 중에
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//범위를 벗어나지 않음 + 방문하지 않음 + 주사위의 바닥 깂과 같은 블럭일 경우
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			    
			    //이동 + 이동횟수 추가 + queue에 반납하기
				if (board[nx][ny] == num && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
    
    return cnt;
}

void getScore(){        //현재 board의 x,y의 값을 얻는다
    
    //(x, y)에 있는 정수, B
    //(x, y)에서 동서남북 방향으로 연속해서 이동할 수 있는 칸의 수, C
    total += board[DiceY][DiceX] * canMove();
}

void input(){
    
    //첫째 줄에 지도의 세로 크기 N, 가로 크기 M (2 ≤ N, M ≤ 20), 
    //그리고 이동하는 횟수 K (1 ≤ K ≤ 1,000)가 주어진다.
    cin >> N >> M >> K;
    
    //지도의 좌표는 (r, c)로 나타내며, r는 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로부터 떨어진 칸의 개수
    DiceX = 0; DiceY = 0; total = 0; DiceDirection = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp; board[j][i] = temp;
        }
    }
}

int main(){

    input();
    
    while(K-->0){
        
        moveDice();             //주사위를 정해진 방향대로 움직인다
        getScore();             //현재 board의 x,y 값을 얻는다
        compareGetDirection();  //아래 값을 비교하여 방향을 변경한다
    }

    cout << total << endl;
    
    return 0;
}

*/