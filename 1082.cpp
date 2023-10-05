#include <iostream>
#include <algorithm>
#include <string>

#define INF 987654321

using namespace std;

int N, M;
int Pi[11];
int temp;

int main(){
    
    string answer;
    
    //input
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        Pi[i] = temp;

    }
    cin >> M;
    
    int first = INF, second = INF;
    int firstIdx, secondIdx;
    
    
    //0 index ~ final index min 값 탐색
    for(int i = 0; i < N; i++){
        if(Pi[i] < first) {
            first = Pi[i];
            firstIdx = i;
        }
    }
    
    // 1 index ~ final index min 값 검색
    // 맨 앞 숫자가 0이 아니어야 하는 경우를 위해 찾아 둠
    for(int i = 1; i < N; i++){
        if(Pi[i] < second) {
            second = Pi[i];
            secondIdx = i;
        }
    }
    
    // 0 이외에 계산할 수 없을 경우
    if(M < second){
        cout << 0 << endl;
        return 0;
    } 
    
    // 먼저 첫 자리수는 1~N-1중에 비용이 최소인 값을 설정
    M -= second;    
    answer.push_back('0' + secondIdx);
    
    // 그리고 나머지 자리수는 0 ~ N- 1중에 비용이 최소인 값으로 미리 설정해둔다
    // greedy 기법. 초기화를 애초에 최소 비용으로 설정해둔다.
    // 최대로 만들 수 있는 길이를 계산한다.
    while(M >= first) {
        answer.push_back('0' + firstIdx);
        M -= first;
    }
    
    int idx;

    // 여기서 문자 하나씩 체크를 하면서
    // 해당 숫자 더 비용이 저렴한 경우의 수가 있는지 파악하고
    // 그 경우를 추가하는 식으로 반복문 탐색
    for (int i = 0; i < answer.length(); ++i) {
        for (int j = N - 1; j >= 0; --j) {
            idx = answer[i] - '0';
                        
            if (M >= Pi[j] - Pi[idx]) { // 비용 뒤에서 부터 살수있으면  
                M -= (Pi[j] - Pi[idx]);
                answer[i] = '0' + j;
                break;
            }            
        }
    }
    
    cout << answer;
    
    return 0;
}