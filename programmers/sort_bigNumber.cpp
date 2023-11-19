#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
    
    string answer = "";    
    vector<string> div;
    
    // 0 ~ 양의 정수 => 정수를 이어 붙여 만들수 있는 가장 큰 수
    for(int i = 0; i < numbers.size(); i++) div.push_back(to_string(numbers[i]));
    
    // 정렬이 가능한가?
    sort(div.begin(), div.end(), cmp);
    
    for(int i = 0; i < div.size(); i++) answer += div[i];
        
    if(answer[0] == '0') return "0";
    
    return answer;
}