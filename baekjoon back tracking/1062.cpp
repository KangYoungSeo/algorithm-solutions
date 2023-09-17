#include <iostream>
#include <stack>

using namespace std;

string words[50];
int N, K;
int learnMax;
bool alphaCheck[26];

void countLearnWords(){
    
    int wordCnt = 0;
    //N개의 알파벳에서 계산
    for(int i = 0; i < N; i++){
        
        int canRead = true;
        
        //앞, 뒤 알파벳 제외 중간알파벳을 읽을 수 있는 지 여부 확인하기
        for(int j = 4; j < words[i].size() - 4; j++){
            
            int alphaNum = (int)(words[i][j] - 'a');
            if(alphaCheck[alphaNum] == false){
                canRead = false;
                break;
            }
        }
        
        //읽을 수 있는 단어라면, 추가
        if(canRead == true) wordCnt++;
    }
    
    //최대인지 확인
    if(wordCnt > learnMax) learnMax = wordCnt;
    
}

void chooseRecursive(int least, int alphaIdx){
    
    //더이상 남은 알파벳이 없을 경우 + 다 선택시, 사용 가능한 단어들 확인하기
    if(alphaIdx > 25 || least == 0){
        countLearnWords();
        return;
    }
    
    //1. 해당 알파벳이 이미 선택되어 있을 경우, skip (true일 경우)
    if(alphaCheck[alphaIdx]){
        
        chooseRecursive(least, alphaIdx + 1);
        return;
    }
    
    //2. 해당 알파벳이 선택되지 않았을 경우,
    //해당 알파벳 선택하고 경우의 수 탐색
    alphaCheck[alphaIdx] = true;
    chooseRecursive(least -1, alphaIdx + 1);
    
    //해당 알파벳 선택하지 않고 경우의 수 탐색
    alphaCheck[alphaIdx] = false;
    chooseRecursive(least, alphaIdx + 1);
    
}

int main(){
    
    //N : 단어 개수, K : 배울 수 있는 글자 수
    cin >> N >> K;
    
    //단어들의 입력
    for(int i = 0; i < N; i++){
        cin >> words[i];
    }
    
    //anti ~ tica에서 atinc 알파벳 나머지 확인
    if( K < 5) { cout << 0 << endl; return 0; }
    
    //a c i n t 알파벳 방문 check
    alphaCheck[0] = true; alphaCheck[2] = true; alphaCheck[8] =true; alphaCheck[13] = true; alphaCheck[19] = true;
    
    
    //골라야 할 알파벳 최댓값
    
    //재귀 + 백트래킹
    chooseRecursive(K-5, 1);
    
    cout << learnMax << endl;

    return 0;
}