#include <iostream>

#define N 21

int dX[] = {0,1,0,-1};
int dY[] = {-1,0,1,0};

using namespace std;

void fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main() {

    //싸움땅
    //n : 보드 크기, m : 플레이어 수, k : 라운드 수

    fast_io();

    int board[N][N];
    int player[N][N];


    int playerX[N*N];
    int playerY[N*N];

    int direction[N*N];
    int power[N*N];
    int gun[N*N];
    int point[N*N];

    int n, m, k;
    int x, y, d, s;

    //input
    cin >> n >> m >> k;

    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    // red -> 공격력 , yellow -> 플레이어의 번호

    for(int i = 0; i < m; i++){
        cin >>x >> y >> d >> s ;
        // x ,y 좌표
        //d 방향 d는 0부터 3까지 순서대로 ↑, →, ↓, ←
        //s 플레이어 초기 능력치

        playerX[i] = x;
        playerY[i] = y;
        player[playerX[i]][playerY[i]] = i;
        direction[i] = d;
        power[i] = s;
        gun[i] = 0;
        point[i] = 0;
    }




    //시뮬레이션 문제
    while(k-->0){

        // 라운드 시작
        for(int i = 0 ; i < m; i++){

            //1. 첫번재 플레이어부터 순차적으로 본이이 향하고 있는 방향대로 한칸 이동

            int total = gun[i] + power[i];

            //이전 데이터 저장
            int beforeX = playerX[i];
            int beforeY = playerY[i];

            int beforeGun = gun[i];


            //이동하기
            playerX[i] += dX[direction[i]];
            playerY[i] += dY[direction[i]];

            // if 격자에 벗어나는 경우 정반대의 방향으로 방향 바꾼 후 한칸 이동
            if(playerX[i] >= n || playerX[i] < 0){
                playerX[i] = beforeX -dX[direction[i]];
            }
            else if(playerY[i] >= n || playerY[i] <0){
                playerY[i] = beforeY -dY[direction[i]];
            }
            
            //옮겨졌기 때문에 이 부분은 비어있다.
            player[beforeX][beforeY] = 0;
            
            
            
            //2.2 플레이어가 있다면
            if (player[playerX[i]][playerY[i]]>0) {

                //플레이어의 총 공격력!!
                //board에 있는 플레이어의 총 값
                int rival_idx = player[playerX[i]][playerY[i]];
                int rival = gun[rival_idx] + power[rival_idx];


                //둘이 같을 경우
                //2.2.1 이길경우!! ----------------not yet
                if(total == rival){
                    //초기 능력자 비교

                    //이길 경우
                    if(power[i] > power[rival_idx]){
                        //포인트 획득
                        point[i] += total;
                    }

                    //질 경우
                    else{
                        //총을 내려놓습니다.
                        gun[i] = beforeGun;

                        beforeX = playerX[i] + dX[direction[i]];
                        beforeY = playerY[i] + dY[direction[i]];
                    }
                }

                //플레이어가 이길경우!
                else if(total > rival){
                    //포인트 획득
                    point[i] += total;

                }

                //2.2.2 질 경우
                else {
                    //총을 내려놓습니다.
                    gun[i] = beforeGun;
                    

                    //한번 더 이동합니다.
                    //변수 재활용
                    beforeX = playerX[i];
                    beforeY = playerY[i];


                    //약 이동하려는 칸에 다른 플레이어가 있거나 격자 범위 밖인 경우에는 
                    for(int i = 0 ; i < 4; i++){
                        beforeX = playerX[i] + dX[(direction[i]+i)%4];
                        beforeY = playerY[i] + dY[(direction[i]+i)%4];

                        //범위에 넘어감
                        if(playerX[i] >= n || playerX[i] < 0)
                            continue;
                        if(playerY[i] >= n || playerY[i] <0)
                            continue;
                        //플레이어가 있음
                        if(player[beforeX][beforeY] > 0)
                            continue;
                        else
                            break;
                        
                    }

                    playerX[i] = beforeX;
                    playerY[i] = beforeY;
                    player[playerX[i]][playerY[i]] = i;
                    
                    
                    //오른쪽으로 90도씩 회전하여 빈 칸이 보이는 순간 이동합니다.
                    
                }

            }

            //만약 이동한 방향에 
            //2-1. 해당 칸에 총이 있는지 확인
            if(board[playerX[i]][playerY[i]]){
                //총 획득!
                //획득한 총이 플레이어 것 보다 클 경우 가져감
                //아닐 경우는 그냥 놓고 간다
                if(board[playerX[i]][playerY[i]] > power[i]){
                    gun[i] = board[playerX[i]][playerY[i]];
                    board[playerX[i]][playerY[i]] = 0;
                }

            }

            //라운드 끝 =====================

        }
    }

    for(int i = 0; i < m; i++)
        cout << point[i] << " ";
    return 0;
}