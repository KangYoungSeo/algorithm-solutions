#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    //성의 첫 글자가 같은 선수 5명을 선발
    //성의 첫 글자가 같은 선수가 5명보다 적다면, 기권
    
    int N; cin >> N; //선수의 수 N (1 ≤ N ≤ 150)
    //(성은 알파벳 소문자로만 이루어져 있고, 최대 30글자이다)
    
    vector<string> name;
    
    vector<string> cntName[27];
    
    string temp;
    
    for(int i = 0; i < N ; i++){
        cin >> temp;
        name.push_back(temp);
    }


    for(int i = 0; i < N; i++){
        
        //문자열의 맨 앞 알파벳의 인덱스 추출
        int alpha = (int)(name[i][0] - 'a');
        
        //그 인덱스의 vector에 넣기
        cntName[alpha].push_back(name[i]);
    }
    
    bool goTeam = false;
    
    //선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력
    for(int i = 0; i < 26; i++){
        
        
        if(cntName[i].size() >= 5){
            
            cout << (char)('a' + i);
            
            if(!goTeam) goTeam = true;
        }
    }
    
    
    //다섯 명을 선발할 수 없는 경우에는 "PREDAJA" 
    if(goTeam == false) cout << "PREDAJA" << endl;

    return 0;
}
