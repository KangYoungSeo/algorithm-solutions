
#include <iostream>
#include <vector>

using namespace std;

int N,M,K;

// i번 파이어볼의 위치는 (ri, ci), 질량은 mi이고, 방향은 di, 속력은 si이다. 위치 (r, c)는 r행 c열을 의미

vector<int> board[2500][2500];
vector<int> map;

int r[2500];
int c[2500];
int m[2500];        //질량
int s[2500];        //속도
int d[2500];        //방향

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void fireballCombine(){
    
    map
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

            if(board[i][j].size() > 1){//2개 이상의 파이어볼이 있는 칸 확인

                // 1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐짐
                int combineMess = 0;
                int combineSpeed = 0;
                bool checkAll = true;
                int oddAll = 1;

                for(int k = 0; k < board[i][j].size(); k++) {

                    int idx = board[i][j][k];
                    
                    combineMess += m[idx];
                    combineSpeed += s[idx];
                    
                    if( k == 0) oddAll = d[idx] % 2 == 1 ? 1 : -1;        //첫번째 값에서 홀, 짝 확인
                    else{  

                        if(checkAll){
                            //첫 값 홀수(true) & 현재 방향 홀수(true) + 짝수(false) & 현재 방향 짝수(false) 
                            if((oddAll * (d[idx]% 2 == 1? 1: -1)) == 1) continue;
                            else checkAll = false;
                        }
                    }
                }

                // 2. 파이어볼은 4개의 파이어볼로 나누어짐

                int newMess = combineMess / 5;      // 질량 = ⌊(합쳐진 파이어볼 질량의 합)/5⌋
                int newSpeed = combineSpeed / 5;    // 속력 = ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋

                if(newMess == 0) continue;          // 질량이 0인 파이어볼은 소멸되어 없어진다.
                    
                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수 => 방향은 0, 2, 4, 6
                if( checkAll == true){
                    
                }
                // 그렇지 않으면 1, 3, 5, 7
                else{   

                }


                


                

            }  




        }
    }
}

void fireballMove(){    //모든 파이어볼 이동 자신의 방향 di로 속력 si칸 만큼 이동

    for (int i = 1; i <= N; i++)            //board 초기화 
        for (int j = 1; j <= N; j++)
            board[i][j].clear();
        
    for(int i = 0; i < M; i++){
        
        //이동 칸
        int moveX = c[i] + (s[i] % N) * dx[d[i]];
        int moveY = r[i] + (s[i] % N) * dy[d[i]];

        if(moveX > N) moveX -= N;
        if(moveY > N) moveY -= N;
        if(moveX < 0) moveX += N;
        if(moveY < 0) moveY += N;

        c[i] = moveX; r[i] = moveY;         //이동 완료

        board[r[i]][c[i]].push_back(i);     //보드에 새로 추가
                                            //이동하는 중에는 같은 칸에 여러 개의 파이어볼이 있을 수도 있음 
    }
}

void input(){
    
    //첫째 줄에 N, M, K가 주어진다. 4 ≤ N ≤ 50, 0 ≤ M ≤ N^2, 1 ≤ K ≤ 1,000
    cin >> N >> M >> K;
    
    //둘째 줄부터 M개의 줄에 파이어볼의 정보가 한 줄에 하나씩 주어진다. 
    //파이어볼의 정보는 다섯 정수 ri, ci, mi, si, di로 이루어져 있다.
    //서로 다른 두 파이어볼의 위치가 같은 경우는 입력으로 주어지지 않는다.
    for(int i = 0; i < M; i++){
        //1 ≤ ri, ci ≤ N    1 ≤ mi ≤ 1,000   1 ≤ si ≤ 1,000   0 ≤ di ≤ 7
        cin >> r[i] >> c[i] >> m[i] >> s[i] >> d[i];
        r[i]--; c[i]--;
    }
}

int sumMass(){              //남은 질량 출력
    int answer = 0;
    for(int i = 0; i < M; i++) answer += m[i];
    return answer;
}

int main(){
    
    //어른 상어가 마법사가 되었고, 파이어볼 learn
    //마법사 상어가 크기가 N×N인 격자에 파이어볼 M개를 발사
    input();
    
    while(K-->0){           //마법사 상어 K번 이동
        
        fireballMove();     //모든 파이어볼 이동
        fireballCombine();  //2개 이상 파이어볼 합침
    }

    cout << sumMass();      //남은 질량 출력

    return 0;
}