#include <iostream>
#include <vector>
#include <cstring> // memset
#include <utility> // pair

using namespace std;

int A[5][5] = {0}; // 격자 4*4 - 물고기 수 표시
int smell[5][5] = {0}; // 물고기 냄새 표기
int M, S;

// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

// 상어는 현재 칸에서 상하좌우로 인접한 칸으로 이동
// 우선순위 : 상 좌 하 우
int sx[4] = {0, -1, 0, 1};
int sy[4] = {-1, 0, 1, 0};

struct FISH{
  int x, y;
  int d;
};

FISH shark; // 상어 정보 저장

vector<FISH> v; // 물고기 정보 저장
vector<FISH> copyFish; // 복제된 물고기 저장
bool visited[5][5] = {false}; // DFS 방문 체크
int sharkWay[3] = {0}; // 상어 이동 방향 저장 - 중복순열
int tempSharkWay[3] = {0}; // DFS 탐색용 방향 저장 임시 배열

int maxSum = -1;

void paste(){
  for(int i = 0; i < copyFish.size(); i++){
    int x = copyFish[i].x; int y = copyFish[i].y;
    A[y][x]++; // 물고개 개수 늘려주기
    v.push_back(copyFish[i]);
  }
}

void smellX(){
  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4; j++){
      // 냄새 존재하면 하나씩 빼주기
      if(smell[i][j] > 0){
        smell[i][j]--;
      }
    }
  }
}

int huntFish(){
  FISH cur = {shark.x, shark.y}; // 상어 현재 위치부터 탐색 시작
  int sum = 0;
  memset(visited, false, sizeof(visited));

  // 상어가 간 길 점수 계산
  for(int i = 0; i < 3; i++){
    int dir = tempSharkWay[i];
    int nx = cur.x + sx[dir];
    int ny = cur.y + sy[dir];

    // 맵 범위 체크
    if(nx < 1 || ny < 1 || nx > 4 || ny > 4){
      return -1;
    }

    // 방문하지 않았으면 방문하고 물고기 점수 계산
    if(!visited[ny][nx]){
      visited[ny][nx] = true;
      sum += A[ny][nx];        
      // visited[ny][nx] = false; // 백트래킹
    }
    cur = {nx, ny}; // 상어 위치 갱신
  }
  return sum;
}

// 백트래킹 - 최적의 경우만 탐색
void DFS(int depth){
  // 깊이가 3 = 상어 3칸 움직였으면 점수 계산하기
  if(depth == 3){
    int sum = huntFish();
    
    if(maxSum < sum){
      // 상어 이동 방향 갱신
      for(int i = 0; i < 3; i++){
        sharkWay[i] = tempSharkWay[i];
      }
      maxSum = sum; // 최댓값 갱신
    }
    return; // 멈춰줘야함
  }

  for(int i = 0; i < 4; i++){
    tempSharkWay[depth] = i; // depth 턴에는 i 방향으로 이동
    DFS(depth + 1);
  }
}

void sharkMove(){
  maxSum = -1;
  DFS(0); // 상어 움직임 방향 구하기

  vector<FISH> tmp;

  for(int i = 0; i < 3; i++){
    int nx = shark.x + sx[sharkWay[i]];
    int ny = shark.y + sy[sharkWay[i]];

    // 물고기 존재하는 경우
    if(A[ny][nx] > 0){
      // 물고기 잡아먹고 냄새 남기기
      A[ny][nx] = 0;
      smell[ny][nx] = 3; // 두 번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라진다.
    }
    shark = {nx, ny}; // 상어 좌표 갱신
  }

  for(int i = 0; i < v.size(); i++){
    // 냄새가 3인 방금 잡아먹은 물고기만 제외하고 벡터에 넣기
    if(smell[v[i].y][v[i].x] != 3){
      tmp.push_back({v[i].x, v[i].y, v[i].d});
    }
  }

  v = tmp;
}

int rotate(int d){
  d--;
  if(d == -1){
    d = 7;
  }
  return d;
}

void move(){
  for(int i = 0; i < v.size(); i++){
    int x = v[i].x; int y = v[i].y; int d = v[i].d;
    // 모든 물고기가 한 칸 이동
    int nd = d;
    int nx = x + dx[nd];
    int ny = y + dy[nd];

    // 상어가 없고 물고기 냄새가 없고 범위 안이면 이동 가능
    if(!(ny == shark.y && nx == shark.x) && smell[ny][nx] == 0 && (nx > 0 && ny > 0 && nx <= 4 && ny <= 4)){
      A[y][x]--;
      A[ny][nx]++;
      v[i].x = nx; v[i].y = ny;
    } else {
      // 이동할 수 없는 경우
      // 이동할 수 있을 때까지 반시계방향 회전
      nd = rotate(nd);
      // 한바퀴 다 회전할 때까지 탐색 - 이동할 수 있는 칸이 없으면 이동을 하지 않는다
      while(d != nd){
        nx = x + dx[nd];
        ny = y + dy[nd];
        if(!(ny == shark.y && nx == shark.x) && smell[ny][nx] == 0 && (nx > 0 && ny > 0 && nx <= 4 && ny <= 4)){
          A[y][x]--; A[ny][nx]++;
          v[i].x = nx; v[i].y = ny; v[i].d = nd;
          break;
        }
        nd = rotate(nd);
      }
    }
  }
}

void copy(){
  copyFish.clear();
  copyFish.assign(v.begin(), v.end()); // vector 복사
}

int main(){
  scanf("%d %d", &M, &S);

  for(int i = 0; i < M; i++){
    int x, y, d;
    scanf("%d %d %d", &y, &x, &d);
    A[y][x]++; // 물고기 수 세기
    
    v.push_back({x, y, --d});
  }

  scanf("%d %d", &shark.y, &shark.x);

  // 마법 연습 S번
  for(int i = 0; i < S; i++){
    copy(); // 복제 마법
    move(); // 물고기 한 칸 이동
    sharkMove();
    smellX();
    paste();
  }

  int cnt = 0;

  for(int i = 1; i <= 4; i++){
    for(int j = 1; j <= 4; j++){
      cnt += A[i][j];
    }
  }

  printf("%d", cnt);

  return 0;
}

/*#include <iostream>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

//←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이
int dx[8] = {-1, -1, 0, 1, 1, 1, };
int dy[8] = {0,-1, -1, -1, 0, 1, };

int sx[4] = {0, -1, 0, 1};
int sy[4] = {-1, 0, 1, 0};

int fishCnt;
int M, S;
int sx, sy;

vector<int> fishboard[4][4];
int smellboard[4][4];

vector<pair< pair<int,int>, int >> originFish;
vector<pair<pair<int,int>, int>> addFish;


void printFishboard(){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            for(int k = 0; k < fishboard[i][j].size(); k++){
                cout << fishboard[i][j][k] << " ";
            }
            
            cout << " ";
        }
        
        cout << endl;
    }
}

void moveShark(){
    
    stack<int> shark;
    
    for(int i = 0; i < shark.size() ; i++){
        
    }
    
}

void removeSmell(){
    
    
    
}

void moveFish(){
    
    //원래 있었던 물고기 복제 진행
    for(int i = 0; i < originFish.size(); i++){
        
        int direction = originFish[i].second;
        int moveX = originFish[i].first.first + dx[direction-1];
        int moveY = originFish[i].first.second + dy[direction-1];
        
        //이동 가능 경우 확인
        while( moveX > -1 && moveX < 4 && moveY > -1 && moveY < 4){
            
            //이동 할 수 없다면 45도 회전 & 이동
            direction = (direction + 1) % 8;
            
            //좌표 재정비
            moveX = originFish[i].first.first + dx[direction-1];
            moveY = originFish[i].first.second + dy[direction-1];
        }
    
        //board에 새기기
        fishboard[moveX][moveY].push_back(direction);
        
        //debug
        printFishboard();
    }
    
    //기존 board에 있던 물고기 탐색
    for(int i = 0; i < addFish.size(); i++){
        
        int direction = addFish[i].second;
        int moveX = addFish[i].first.first + dx[direction-1];
        int moveY = addFish[i].first.second + dy[direction-1];
        
        //이동 가능 경우 확인
        while( moveX > -1 && moveX < 4 && moveY > -1 && moveY < 4){
            
            //이동 할 수 없다면 45도 회전 & 이동
            direction = (direction + 1) % 8;
            
            //좌표 재정비
            moveX = addFish[i].first.first + dx[direction-1];
            moveY = addFish[i].first.second + dy[direction-1];
        }
    
        //board에 새기기
        fishboard[moveX][moveY].push_back(direction);
        
        //debug
        printFishboard();
    }
}


int main(){
    
    //첫째 줄에 물고기의 수 M, 상어가 마법을 연습한 횟수 S가 주어짐
    cin >> M >> S; fishCnt = M;
    
    for(int i = 0; i < M; i++){
        
        int fx, fy, d; cin >> fx >> fy >> d; //(fx, fy) :  물고기 위치, d 방향
        
        //방향 : 8 이하의 자연수로 표현, 1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 이
        originFish.push_back(make_pair(make_pair(fx,fy), d));
    }
    
    cin >> sx >> sy; ////sx, sy : 상어의 위치
    
    
    //상어 연습 시작
    while(S-->0){
        
        moveFish();         //물고기 이동
        
        moveShark();        //상어 이동
        
        removeSmell();      //냄새 제거
        
    }
    
    //격자 위에 있는 물고기의 수가 항상 1,000,000 이하인 입력만 주어진다.
    //S번의 연습을 마친 후 격자에 있는 물고기의 수를 출력
    cout << fishCnt << endl;

    return 0;
}*/