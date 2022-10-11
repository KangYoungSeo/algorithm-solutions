#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    
    int answer = 1e8;           //최대값 집어넣기
    int w_size = weak.size();
    
    // n : 그다음 인덱스, 방향은 자유자제!
    // weak : 어디 인덱스가 가장 취약한지 정보 제공
    // dist : 친구 별 이동거리
    
    // next_permision 사용하기
    for(int i=0; i<w_size-1; ++i) {
        weak.push_back(weak[i] + n);
    }
    
    // 첫번째 이론, dist에서 가장 거리를 많이 가는 친구를 찾기
    
    // -> dist를 먼저 정렬
    sort(dist.begin(), dist.end());
    
    //weak 데이터를 board에 표시 vs int 값 그대로 사용하
    //1) board 사용 
    bool* board = new bool[n+1];
    
    for(int i = 0; i < weak.size(); i++) board[weak[i]] = true;
    
    // 이후 가장 많이 가는 친구를 기준으로 기준으로 탐색을 진행
    /*
    int count = 0;
    int max = weak.size();
    
    //순서 1: 현재 남아있는 친구 중 가장 많이 움직일 수 있는 친구를 먼저 외벽점검
    //순서 2: 친구를 기준으로 최대한 외벽 점검이 가능할 수 있는 경우 계산
    
    queue<int> search;
    
    while(){
        
        //보드 선언 필요없음 int 값 계산으로 진행하기
        int friend = dist.pop_back();
        //시계 방향일 경우 
        int clk = weak[(i+1)/max] - weak[i]; 
        
        //반시계 방향일 경우 - 역순 
        int clk_ops = weak[(i-1)/max] - weak[i]; 
        count++;
        
        //시계방향이 더 가깝다면 시계방향 탐색
        if(clk > clk_ops) {
            search.push(weak[(i+1)/max]); 
        }
        //반시계방향이 더 가깝다면 해당 방향 탐색
        else{
            search.push(weak[(i-1)/max]);
        }
        weak.erase(weak.begin()+i);
        
    }
    */
    
    do {
        for(int i=0; i<w_size; ++i) {
            int start = weak[i];
            int end = weak[i+w_size-1];
            
            for(int j=0; j<dist.size(); ++j) {
                start += dist[j]; // 친구 이동 (이 이동이 모든 부분을 다 쓰는게 아닌듯)
                
                if(start >= end) { // 모든 지점 점검 마쳤을 경우
                    answer = min(answer, j+1);
                    break;
                }
                
                // 외벽 점검을 마치지 않았지만 더이상 이동할 수 없으면 다음 지점으로 이동
                for(int z=i+1; z<i+w_size; ++z) {
                    if(weak[z] > start) {
                        start = weak[z];
                        break;
                    }
                }
            }
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 1e8) return -1;

    return answer;
}
