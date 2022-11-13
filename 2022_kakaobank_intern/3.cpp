#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int solution(vector<int> rooms) {

    int MAX = rooms.size();
    //방이 1개일 경우 마스터키 한번 사용
    if(rooms.size() == 1) return 1;
    
    //방문여부
    bool board[MAX];
    for(int i = 0 ; i < MAX ;i++) board[i] = false;
        
    queue<int> before;
    bool swapchance = false;
    int key = 0;
   
    for(int idx = 0; idx < MAX ; idx++){
        //1. 이미 열려있는 방
        if(board[idx] == true) continue;
        
        //2. 자신의 열쇠를 가진 방
        else if (rooms[idx] == idx + 1){
            //swap 기회가 있다면 연쇄 세트 하나의 요소와 스왑 & open
            if(swapchance == false)
                swapchance = true;
            //swap 기회가 없다면 마스터키 이용 open
            else
                key++;
            
            board[idx] = true;
        }
        //3. 마스터키 사용
        else{
            before.push(idx);
            //열쇠를 활용해서 연속적으로 방을 open
            //이로써 한 번의 마스터키로 열 수 있는 방들을 세트로 칭함.
            while(board[idx] != true){
                board[idx] = true;
                idx = rooms[idx] - 1;
            }
            key++;
        }
    }
    //아직 swapchance를 쓰지 않으면 
    //swap 후 마스터키 사용횟수 줄임.
    if( swapchance == false && key >1) key--;
    return key;
}
