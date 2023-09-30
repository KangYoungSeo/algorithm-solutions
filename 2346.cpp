#include <iostream>
#include <deque>

using namespace std;
deque<pair<int,int>> dq;
int N;

int main(void)
{
	cin >> N;
	int num;
	for (int i = 0; i < N; i++){
		cin >> num;
		dq.push_back(make_pair(num,i+1)); 
	}
    
    
	while (!dq.empty()){
        
		int cur = dq.front().first;    //이동 값 저장
		cout << dq.front().second << " "; //원래 풍선 번호 출력
		dq.pop_front();    // 실제 원형 큐에서 out

		if (dq.empty()) break;   
        
        // 양수이면 이미 출력후 pop을 한번 했기에 cur-1번 front를 back으로 옮김
		if (cur > 0){ 
            
			for (int i = 0; i < cur-1; i++){
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
        
		else{
			for (int i = 0; i < (-1)*cur; i++)
			{ // 음수일 경우 왼쪽 이동이므로 맨뒤의것을 맨앞으로 옮기기
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
}