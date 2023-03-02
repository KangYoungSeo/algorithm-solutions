#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp (vector<int> i, vector<int> j){
    
    return i[0] > j[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    
    //피로도 시스템
    //던전은 하루에 한 번씩만
    //유저 피로도 - k
    //최소 필요 피로도, 소모 피로도 - dungeons
    
    //유저가 탐험할 수 있는 최대 던전 수
    int answer = 0;
    
    //난 이 문제가 왜 백트래킹 같...지?
    //....
    
    //정렬 먼저하기 -> 순열 조합 문제는 무조건 정렬 후에 들어가야한다.
    sort(dungeons.begin(), dungeons.end());
    
    
    //나열한 후에 하나씩 진행했을 때 깰 수 있는 던전 수를 구한 후 최댓값 출력
    do {

        int current = k;
        int idx = 0;
        int total = 0;
    
        while(1){

            // 최소 필요 피로도가 던전의 요구사항보다 클 경우,
            if(current >= dungeons[idx][0]){
                // 던전 통과
                total++;
                // 현재 값에서 던전 들어가고 소모된 값을 마이너스
                current -= dungeons[idx++][1];
            }
            //크지 않을 경우 해당 던전은 포기해야하기 때문에 인덱스를 다음으로 옯기자
            else idx++;
            
            if(idx >= dungeons.size()) break;
        }

        if(answer < total) answer = total;
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    
    return answer;
}
