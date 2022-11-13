#include <string>
#include <vector>
//#include <iostream>
using namespace std;
vector<int> solution(string logs) {
    vector<int> answer(24);
    int time_idx = 0;
    //string 탐색
    while( time_idx < logs.size() ){
        int hour = stoi(logs.substr(time_idx + 11,2)) + 9;
        answer[hour%24]++;
        
        //다음 string 이동
        time_idx += 20;
    }
    return answer;
}
