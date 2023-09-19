#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int N, M;//int board[21][21]; // 얘가 필요 없을 수도?

struct fish{
    
    int Y;
    int X;
    int size;
};

//남은 물고기 리스트
vector<fish> fishList;

//상어
fish baby;

//물고기가 얼마나 먹었는지 카운트
int eat;

int moveCnt;

//상어가 idx의 고기를 먹자.
void eatFish(int idx){

    //이동 거리 계산
    int move = abs(fishList[idx].Y - baby.Y) + abs(fishList[idx].X - baby.X);
    
    //상어가 그 위치로 옮기기
    baby.Y = fishList[idx].Y;
    baby.X = fishList[idx].X;
            
    //물고기 리스트에 삭제
    fishList.erase(fishList.begin() + idx);
            
    //물고기 먹기
    eat++;
            
    //사이즈가 커질 만큼 먹을 경우, 
    if(eat == baby.size){
                
        //먹은 개수 초기화
        eat = 0;
                
        //아기 상어 사이즈 증가
        baby.size++;
        
    }
    
    moveCnt += move;
    
}

//주변 
bool checkFishes(){
    
    int distance = 500;
    vector<int> maxIdx;
    
    //각자 상어랑 가까운지 물고기확인
    for(int i = 0; i < fishList.size() ; i++){
        
        //생선의 위치
        int fishY = fishList[i].Y;
        int fishX = fishList[i].X;
        
        //생선 크기
        int fishSize = fishList[i].size;
        
        
        //1. 아기 상어보다 작을 경우, 먹을 가능성 있음
        if(fishSize <= baby.size){
            
            //아기가 물고기까지 움직이려면 이동 횟수
            int move = abs(fishY - baby.Y) + abs(fishX - baby.X);
            
            //현재 상황 기준 가장 거리가 짧을 때
            if(move < distance){
                
                //기존에 먹으려고 했던 배열 없애고 추가
                maxIdx.clear();
                maxIdx.push_back(i);
                
                //거리도 갱신
                distance = move;
            }
            
            //거리가 같을 경우 확인
            else if(move == distance) maxIdx.push_back(i);
        }
    }
    
    //먹을 수 있는 물고기가 없을 경우
    if(maxIdx.empty()) return false;
    
    //마지막에 한 개의 물고기일 경우
    if(maxIdx.size() == 1){
        
        eatFish(maxIdx[0]);
        
    } 
    
    //여러개 물고기 후보 중 걸러내서 먹기
    else{
        
        int top = 30;
        vector<int> finalIdx;
        
        //맨 위의 
        for(int i = 0; i < maxIdx.size(); i++){
        
            //유일하게 제일 위에 있을때
            if(top > fishList[maxIdx[i]].Y){
                
                top = fishList[maxIdx[i]].Y;
                
                finalIdx.clear();
                finalIdx.push_back(maxIdx[i]);
            }
            
            //같은 위치에 있을 때
            else if(top == fishList[maxIdx[i]].Y){
                finalIdx.push_back(maxIdx[i]);
            }
                
        }
        
        
        if(finalIdx.size() == 1) eatFish(finalIdx[0]);
        
        else{
            int left = 30;
            int leftFinalIndex;

            for(int i = 0; i < finalIdx.size(); i++){
                
                if(left > fishList[finalIdx[i]].X){
                    
                    left = fishList[finalIdx[i]].X;
                    leftFinalIndex = finalIdx[i];
                }
            }
            
            eatFish(leftFinalIndex);
        }
    }
    
    return true;
}


int main(){
    
    //공간 N 
    cin >> N;
    int temp;
    
    //공간의 상태 입력 0 :빈칸, 9: 아기상어, 나머지는 물고기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            
            cin >> temp;
            
            //아기 상어의 위치일 경우, 초기화
            if(temp >= 9){
                baby.Y = i;
                baby.X = j;
                baby.size = 2;
                eat = 0;
            }
            
            //물고기 저장해두기 
            else if(temp > 0){
                fishList.push_back({i,j,temp});
            }
        }
    }
    
    moveCnt = 0;
    bool check = true;
    
    //물고기 먹기 시작
    while(check){
        
        //상어가 먹을 수 있는 고기가 있는지 확인
        check = checkFishes();
    }
    
    cout<< moveCnt <<endl;

    return 0;
}
