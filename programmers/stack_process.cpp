#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    int answer = 0;
    queue<int> q;
    
    // queue 자료구조
    for(int i = 0; i < priorities.size(); i++) q.push(priorities[i]);
    
    //우선순위를 위해서 정렬 후, 해당 숫자가 pop할 수 있도록 작업
    sort(priorities.begin(), priorities.end());
    
    //실행 대기 큐(Queue)에서 대기중인 프로세스 하나
    
    int Aidx = location;
    
    while(true){
        
        //맨 앞 친구가 priority에 맞춰 나올 수 있는지?
        //현재 우선순위와 동일한지, 동일 하면 pop
        
        cout << q.front() << " " << priorities.back() << endl;
        
        if(q.front() == priorities.back()){
        
            answer++; cout << answer << endl;
            
            //근데 이번에 나오는 인덱스가 첫번째 인덱스였을 경우
            //(포인터 개념으로 계속 따라가게끔 할거임)
            if(Aidx == 0) break;
            
            priorities.pop_back(); //우선순위 함수 pop
            q.pop();             //queue 앞도 pop
            
            // 아닐 경우에는 pop만 진행함 <- 필요 없을 수도 있음
            Aidx--; if(Aidx < 0) Aidx = q.size()-1;
        }
        
        //우선 순위가 동일하지 않는다면 뒤로 다시 넣기
        else{
            int temp = q.front();
            q.pop();
            q.push(temp);
            
            // 아닐 경우에는 pop만 진행함 <- 필요 없을 수도 있음
            Aidx--; if(Aidx < 0) Aidx = q.size()-1;
        }
        
    }
    //2-1) 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣기
    
    //2-2) 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행
    //한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
    
    return answer;
}