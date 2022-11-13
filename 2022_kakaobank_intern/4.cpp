#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> solution(vector<vector<int>> jobs) {
    int MAX = jobs.size();
    //작업 분류 번호 순서 저장
    vector<int> state; state.push_back(jobs[0][2]);
    if(MAX == 1) return state;
    //분류 별 중요도
    vector<int> priority(101);
    priority[jobs[0][2]] = jobs[0][3];
    //대기중인 jobs의 인덱스
    vector<int> wait; wait.push_back(0);

    //현재 시간
    int time = jobs[0][0];
    //실행 중인 작업 인덱스
    int idx = 0;
    // 현재 작업 중인 분류
    int now_stat = jobs[idx][2];


    while(!wait.empty()){

        //현재 대기 job이 끝남 -> 중요도에서 제거
        wait.erase(wait.begin() + idx);
        //작업 끝날 시 시간 변경
        time += jobs[idx][1];
        //중요도 감소
        priority[now_stat] -= jobs[idx][3];
        //새로 요청 된 작업들 탐색, 대기열에 추가
        for(int search = idx + 1; search < MAX; search++){
            if(jobs[search][0] > time) break;
            
            wait.push_back(search);
            priority[jobs[search][2]] += jobs[search][3];
        }
        //대기열 확인
        int max = priority[now_stat];
        for(int l = 0; l < wait.size() ; l++){
            //동일 state가 대기열에 있을 경우
            if(jobs[wait[l]][2] == now_stat){
                now_stat = jobs[wait[l]][2];
                idx = wait[l]; break;
            }
            
            // 우선순위가 같을 경우
            if(priority[ jobs[wait[l]][2]] == max){
                if (jobs[wait[l]][2] < jobs[now_stat][2]){
                    idx = wait[l];
                    now_stat = jobs[wait[l]][2];
                } 
            }
            //우선순위가 높을 경우
            else if(priority[ jobs[wait[l]][2] ] > max){
                now_stat = jobs[wait[l]][2];
                max = priority[jobs[wait[l]][2]];
                idx = wait[l];
            }
            */
        }
        if(state.back() != now_stat) state.push_back(now_stat);
    }
    return state;
}
