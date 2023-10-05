#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int R, C, K;
char temp;

char map[6][6];
bool visited[6][6];

int answer;

// 상하좌우
int dy[4] = { -1, 1, 0, 0};
int dx[4] = { 0, 0, -1, 1};

void DFS(int Ny, int Nx, int move){
    
    visited[Ny][Nx] = true;
        
    if((Ny == 0) && (Nx == (C-1))){
        
        if(move == K) answer++;
        
        visited[Ny][Nx] = false;
        
        return;
    }
    
    //사방을 확인하자.
    //1. 보드에 벗어나지 않는 선에서
    //2. 방문하지 않을 경우
    //3. 장애물이 있어서 갈 수 없는 경우
        
    //상하좌우 체크하기
    for(int i = 0; i < 4; i++){
            
        int Tx = Nx + dx[i];
        int Ty = Ny + dy[i];

        //보드에 벗어나지 않음 && 방문하지 않았음 && 장애물이 없을 경우
        if(Tx < 0 || Tx >= C || Ty < 0 || Ty >= R || visited[Ty][Tx] || (map[Ty][Tx] == 'T')) continue;
            
        // stack에 집어 넣기
        DFS(Ty, Tx, move + 1);

    }
    
    visited[Ny][Nx] = false;
    
}


int main(){
    
    //첫 줄에 정수 R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가 공백으로 구분되어 주어진다. 
    cin >> R >> C >> K;

    //두 번째부터 R+1번째 줄까지는 R×C 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> temp;
            
            map[i][j] = temp;
        }
    }
    
    answer = 0;
    
    //그래프 탐색, DFS
    // y, x, 이동 횟수 저장
    
    DFS(R-1,0,1);
    
    cout << answer << endl;
    
    return 0;
}