#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201];
vector<int> connected[201];
int n;


void DFS(int idx){
    
    //방문 처리 진행
    if(visited[idx] == false) visited[idx] = true;
    else return;
    
    
    //연결된 노드들을 확인
    for(int i = 0; i < connected[idx].size(); i++){
        
        //연결되어 있을 경우, 탐색
        DFS(connected[idx][i]);
    }

}

int solution(int _n, vector<vector<int>> computers) {
    
    // 1 <= n <= 200 자연수
    n = _n;
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            if(i == j) continue;
            
            if(computers[i][j] == 1) connected[i].push_back(j);
        }
    }
    
    //각 노드별 탐색을 진행한다
    for(int i = 0; i < n ; i++){
        
        
        //하나도 연결되어있지 않을 경우, 네트워크 하나로 취급
        if(connected[i].size() == 0){
            
            cout << "alone" << endl;
            answer++;
            continue;
        }
        
        
        //연결되어 있지만, 
        if(visited[i] == false) {
            
            cout << "탐색" << endl;
            
            DFS(i);
            answer++;
        }
    }
    
    return answer;
}