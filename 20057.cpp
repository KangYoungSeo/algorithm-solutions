#include <iostream>
#include <queue>

using namespace std;

int N, temp;
int A[500][500];  //(r, c)는 격자의 r행 c열을 의미하고, A[r][c]는 (r, c)에 있는 모래의 양

int total;

int curX, curY;

// 동 -0, 남 - 1, 서 - 2, 북 - 3
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


//모래 흩날리는 구성
int xdx[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
                  { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
int ydy[4][10] = { { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
                  { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };
                  
int Percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };


void spreadSand(int x, int y, int dirt){  //모래 흩뿌리기

    int xx = x + dx[dirt];
    int yy = y + dy[dirt];
    
    if (A[xx][yy] == 0) return;     //해당 블럭에 모래가 없으면 skip
 
    int Sand = A[xx][yy];
    int Temp = Sand;

    for (int i = 0; i < 9; i++){

        int nx = x + xdx[dirt][i];          //흩뿌릴 블럭
        int ny = y + ydy[dirt][i];
        int Per = Percent[i];               //모래 퍼센테지
        int Plus = (Temp * Per) / 100;      //총 추가될 모래

        if (nx < 1 || ny < 1 || nx > N || ny > N) total += Plus;
        else A[nx][ny] += Plus;
        
        Sand -= Plus;
    }

    int nx = x + xdx[dirt][9];
    int ny = y + ydy[dirt][9];
    
    //보드에 벗어나는 모래가 있을 경우 => 추가, 아닐 경우는 해당 보드에 모래 추가
    if (nx < 1 || ny < 1 || nx > N || ny > N) total += Sand;
    else A[nx][ny] += Sand;

    A[xx][yy] = 0;      //이제 해당 블럭에 모래는 없다.
}

void tornado(int dist, int dirt){ //이동, dist = 얼만큼 이동, dirt 방향
    
    for(int i = 1; i <= dist; i++){
        
        int moveX = curX + dx[dirt];    //이동 방향
        int moveY = curY + dy[dirt];
        
        spreadSand(moveX, moveY, dirt);       //모래 흩뿌리기
    }
    
    curX += dx[dirt] * dist; 
    curY += dy[dirt] * dist;
}

void input(){
    
    //격자의 크기 N, 3 ≤ N ≤ 499, 홀수
    cin >> N;
    
    //둘째 줄부터 N개의 줄에는 격자의 각 칸에 있는 모래가 주어진다. 
    //r번째 줄에서 c번째 주어지는 정수는 A[r][c] 이다.
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp; A[j][i] = temp;
        }
    }
    
    //중간 값 설정   
    curX = N/2; curY = N/2;
}

int main(){

    input();
    
    int moveDist = 2;
    
    while(moveDist < N){
        
        //이동하기
        tornado(moveDist, 2);   //서
        tornado(moveDist, 1);   //남
        
        moveDist++;
        
        tornado(moveDist, 0);   //동
        tornado(moveDist, 3);   //북
        
        moveDist++;
    }

    cout << total << endl;
    return 0;
}
/*
#include <iostream>
 
#define MAX 510
#define endl "\n"
using namespace std;
 
int N, Answer;
int MAP[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
// 1 1 7 7 10 10 2 2 5 순서
int xdx[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
                  { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2} };
int ydy[4][10] = { { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, { 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
                  { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} };
int Percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
int Change_Dir(int Dir)
{
    if (Dir == 0) return 3;
    if (Dir == 1) return 2;
    if (Dir == 2) return 0;
    if (Dir == 3) return 1;
}
 
void Spread_Sand(int x, int y,int Dir)
{
    int xx = x + dx[Dir];
    int yy = y + dy[Dir];
    if (MAP[xx][yy] == 0) return;
 
    int Sand = MAP[xx][yy];
    int Temp = Sand;
    for (int i = 0; i < 9; i++)
    {
        int nx = x + xdx[Dir][i];
        int ny = y + ydy[Dir][i];
        int Per = Percent[i];
        int Plus = (Temp * Per) / 100;
 
        if (nx < 1 || ny < 1 || nx > N || ny > N) Answer += Plus;
        else MAP[nx][ny] += Plus;
        
        Sand -= Plus;
    }
    int nx = x + xdx[Dir][9];
    int ny = y + ydy[Dir][9];
 
    if (nx < 1 || ny < 1 || nx > N || ny > N) Answer += Sand;
    else MAP[nx][ny] += Sand;
    MAP[xx][yy] = 0;
}
 
void Solution()
{
    int x = (N + 1) / 2;
    int y = (N + 1) / 2;
    int Dir = 1;        
    int Move_Cnt = 1;    
 
    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < Move_Cnt; j++)
            {
                Spread_Sand(x, y, Dir);
                x += dx[Dir];
                y += dy[Dir];
            }
            Dir = Change_Dir(Dir);
        }
 
        Move_Cnt++;
        if (Move_Cnt == N)
        {
            for (int j = 0; j < Move_Cnt; j++)
            {
                Spread_Sand(x, y, Dir);
                x += dx[Dir];
                y += dy[Dir];
            }
            break;
        }
    }
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}



*/